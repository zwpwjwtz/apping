#include <cstring>
#include "app.h"
#include "../config.h"
#include "../backend/apt_launcher.h"

#define APPING_SUBSYSTEM_BACKEND_MAXLEN  256


AppingApp::AppingApp()
{
    subsystem = APPING_ACTION_NONE;
    backend = nullptr;
}

const char* AppingApp::getBackend()
{
    char* backendName;
    //appingConfig.getConfig("backend", backendName);
    backendName = new char[4]; strcpy(backendName, "apt");
    return backendName;
}

bool AppingApp::initBackend()
{
    const char* backendName = getBackend();
    if (backendName == nullptr)
        return false;
    else if (strcmp(backendName, "apt") == 0)
        backend = new apt_launcher;
    else
        return false;

    if (backendName != nullptr)
        delete backendName;

    if (backend == nullptr)
    {
        appingError.setAction(APPING_ACTION_ERROR);
        appingError.setMessage(_("Backend initialization failed."));
        appingError.showText();
        return false;
    }
    else
        return true;
}
