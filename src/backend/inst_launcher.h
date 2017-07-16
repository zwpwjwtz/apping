#ifndef INST_LAUNCHER_H
#define INST_LAUNCHER_H

// Base class for launching package manager (apt, dnf, ...)

#include <string>
#include <vector>


class inst_launcher
{
public:
    typedef std::vector<const char*> PackageList;
    enum ErrorNumber
    {
        OK = 0,
        ExecNotFound = 1,
        PermissionDenied = 2
    };

    inst_launcher();
    virtual const char* getName() = 0;
    virtual ErrorNumber install(PackageList packages) = 0;
    virtual ErrorNumber uninstall(PackageList packages) = 0;
    virtual ErrorNumber reinstall(PackageList packages) = 0;
    virtual ErrorNumber info(PackageList packages) = 0;

protected:
    int execWait(const char* path, const char* argv[], std::string& output);
    const char* searchExecPath(const char* command, const char* arg);
};

#endif // INST_LAUNCHER_H
