#include <cstring>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include "inst_launcher.h"


#define LAUNCHER_APT_OUTPUT_BUFFER  255


inst_launcher::inst_launcher()
{

}

int inst_launcher::execWait(const char* path,
                            const char* argv[],
                            std::string& output)
{
    int fd[2];
    pid_t pid;
    int n, status;
    char buf[LAUNCHER_APT_OUTPUT_BUFFER + 1];
    memset(buf, 0, LAUNCHER_APT_OUTPUT_BUFFER);
    output.clear();

    if (pipe(fd) < 0)
        return -1;

    if ((pid = fork()) < 0)
        return -1;
    else if (pid > 0)
    {
        // This is the parent process
        //printf("Parent %d\n", getpid());
        close(fd[1]);
        while ((n = read(fd[0], buf, LAUNCHER_APT_OUTPUT_BUFFER)) > 0)
        {
            buf[n] = '\0';
            output.append(buf);
        }
        close(fd[0]);
        if (waitpid(pid, &status, 0) == -1 || !WIFEXITED(status))
            return -1;
        else
            return WEXITSTATUS(status);
    }
    else
    {
        // This is the child process
        //printf("Child %d\n", getpid());
        close(fd[0]);
        if (fd[1] != STDOUT_FILENO)
        {
             if (dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO
            	|| dup2(fd[1], STDERR_FILENO) != STDERR_FILENO)
            {
            	close(fd[1]);
                return -1;
            }
        }

        // Not sure if exec() will modify the content of each arguments
        // But this seems to be the simplest way to call exec()
        if (execv(path, const_cast<char* const*>(argv)) == -1)
            exit(-1);
        
        // This "return" shall never be reached. It is only used to eliminate
        // "control reaches end of non-void function" warning from gcc
        return 0;
    }
}

const char* inst_launcher::searchExecPath(const char* command, const char* arg)
{
    const char* execPathPrefix[] = {"/bin/",
                                    "/usr/bin/",
                                    "/usr/sbin/",
                                    "/usr/local/bin/"};
    std::string aptPath, output;
    char* execPath = nullptr;
    const char* args[] = {nullptr, arg, nullptr};
    bool execFound = false;

    for (auto prefix : execPathPrefix)
    {
        aptPath = prefix;
        aptPath.append(command);
        args[0] = aptPath.c_str();
        if (execWait(aptPath.c_str(), args, output) == 0)
        {
            execFound = true;
            break;
        }
    }
    if (execFound)
    {
        execPath = new char[aptPath.size() + 1];
        strcpy(execPath, aptPath.data());
    }
    return execPath;
}
