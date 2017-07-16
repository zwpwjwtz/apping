#include <cstring>
#include <iostream>
#include "../main.h"
#include "apt_launcher.h"


#define LAUNCHER_APT_EXECPATH_LEN  256
#define LAUNCHER_APT_COMMAND_LIST   "list"
#define LAUNCHER_APT_COMMAND_INFO   "show"
#define LAUNCHER_APT_COMMAND_INST   "install"
#define LAUNCHER_APT_COMMAND_UNINST "purge"
#define LAUNCHER_APT_OPTION_VERSION "--version"


apt_launcher::apt_launcher()
{
    execPath = searchExecPath(command, LAUNCHER_APT_OPTION_VERSION);
    execPath2 = searchExecPath(command2, LAUNCHER_APT_OPTION_VERSION);

    if (execPath == nullptr || execPath2 == nullptr)
        initialized = false;
    else
        initialized = true;
}

const char* apt_launcher::getName()
{
    return "apt";
}

apt_launcher::ErrorNumber apt_launcher::install(PackageList packages)
{
    if (execPath == nullptr)
        return ErrorNumber::ExecNotFound;

    std::string output;
    const char* args[3 + packages.size()];

    args[0] = execPath;
    args[1] = LAUNCHER_APT_COMMAND_INST;
    for (auto package : packages)
    {
        static int i = 2;
        args[i++] = package;
    }
    args[2 + packages.size()] = nullptr;

    execWait(execPath, args, output);
    std::cout << output << std::endl;

    return ErrorNumber::OK;
}

apt_launcher::ErrorNumber apt_launcher::uninstall(PackageList packages)
{
    if (execPath == nullptr)
        return ErrorNumber::ExecNotFound;

    std::string output;
    const char* args[3 + packages.size()];

    args[0] = execPath;
    args[1] = LAUNCHER_APT_COMMAND_UNINST;
    for (auto package : packages)
    {
        static int i = 2;
        args[i++] = package;
    }
    args[2 + packages.size()] = nullptr;

    execWait(execPath, args, output);
    std::cout << output << std::endl;

    return ErrorNumber::OK;
}

apt_launcher::ErrorNumber apt_launcher::reinstall(PackageList packages)
{
    if (execPath == nullptr)
        return ErrorNumber::ExecNotFound;

    std::string output;
    const char* args[3 + packages.size()];

    args[0] = execPath;
    args[1] = LAUNCHER_APT_COMMAND_UNINST;
    for (auto package : packages)
    {
        static int i = 2;
        args[i++] = package;
    }
    args[2 + packages.size()] = nullptr;

    execWait(execPath, args, output);
    std::cout << output << std::endl;

    args[1] = LAUNCHER_APT_COMMAND_INST;
    execWait(execPath, args, output);
    std::cout << output << std::endl;

    return ErrorNumber::OK;
}

apt_launcher::ErrorNumber apt_launcher::info(PackageList packages)
{
    if (execPath2 == nullptr)
        return ErrorNumber::ExecNotFound;

    std::string output;
    const char* args[3 + packages.size()];

    args[0] = execPath2;
    args[1] = LAUNCHER_APT_COMMAND_INFO;
    for (auto package : packages)
    {
        static int i = 2;
        args[i++] = package;
    }
    args[2 + packages.size()] = nullptr;

    execWait(execPath2, args, output);
    std::cout << output << std::endl;

    return ErrorNumber::OK;
}
