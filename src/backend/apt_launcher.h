#ifndef APT_LAUNCHER_H
#define APT_LAUNCHER_H

// Class for launching APT package manager

#include "inst_launcher.h"


class apt_launcher : public inst_launcher
{
public:    
    apt_launcher();
    const char* getName();
    const char* getCommand();
    ErrorNumber install(PackageList packages);
    ErrorNumber uninstall(PackageList packages);
    ErrorNumber reinstall(PackageList packages);
    ErrorNumber info(PackageList packages);

    const char* command = "apt-get";
    const char* command2 = "apt-cache";

private:
    const char* execPath;
    const char* execPath2;
    bool initialized;
};

#endif // APT_LAUNCHER_H
