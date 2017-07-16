#include <cstdio>
#include "info.h"
#include "../i18n.h"


AppingInfo::AppingInfo()
{
    subsystem = APPING_ACTION_INFO;
    initBackend();
}

void AppingInfo::process(int argc, const char *argv[])
{
    if (backend == nullptr)
        return;

    inst_launcher::PackageList packages;
    for(int i = 0; i < argc; i++)
        packages.push_back(argv[i]);

    char* message;
    switch (backend->info(packages))
    {
        case inst_launcher::ErrorNumber::ExecNotFound:
            appingError.setAction(APPING_ACTION_INFO);
            message = new char[APPING_ERROR_MESSAGE_MAXLEN];
            sprintf(message,
                    _("Cannot found executable for backend %s."),
                    backend->getName());
            appingError.setMessage(message);
            appingError.showText();
            break;
        case inst_launcher::ErrorNumber::PermissionDenied:
            break;
        case inst_launcher::ErrorNumber::OK:
            break;
    }
}
