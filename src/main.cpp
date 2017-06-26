#include <cstring>
#include <iostream>
#include <vector>

#include "main.h"
#include "error.h"
#include "help.h"
#include "subsystem/info.h"
#include "subsystem/install.h"
#include "subsystem/reinstall.h"
#include "subsystem/uninstall.h"
#include "i18n.h"


using namespace std;

char* stolower(char* s)
{
    char* p = s;
    while ((*p = tolower(*p)) != '\0')
        p++;
    return s;
}

int parseCommand(int argc, const char *argv[])
{

    if (argc < 2)
        return APPING_ACTION_HELP;

    char* command = new char[strlen(argv[1])];
    strcpy(command, argv[1]);
    command = stolower(command);
    
    if (strcmp(command, APPING_COMMAND_HELP) == 0
        || strcmp(command, APPING_COMMAND_HELP2) == 0)
        return APPING_ACTION_HELP;
    if (strcmp(command, APPING_COMMAND_INFO) == 0)
        return APPING_ACTION_INFO;
    else if (strcmp(command, APPING_COMMAND_INSTALL) == 0)
        return APPING_ACTION_INSTALL;
    else if (strcmp(command, APPING_COMMAND_REINSTALL) == 0)
        return APPING_ACTION_REINSTALL;
    else if (strcmp(command, APPING_COMMAND_UNINSTALL) == 0)
        return APPING_ACTION_UNINSTALL;
    else
        return APPING_ACTION_ERROR;
}

int main(int argc, const char *argv[])
{
    AppingApp* handler = nullptr;
    AppingHelp* apping_help;

    int result = parseCommand(argc, argv);
    switch (result)
    {
        case APPING_ACTION_HELP:
            apping_help = new AppingHelp;
            apping_help->showText();
            break;
        case APPING_ACTION_INFO:
            handler = new AppingInfo;
            break;
        case APPING_ACTION_INSTALL:
            handler = new AppingInstall;
            break;
        case APPING_ACTION_REINSTALL:
            handler = new AppingReinstall;
            break;
        case APPING_ACTION_UNINSTALL:
            handler = new AppingUninstall;
            break;
        default:
            appingError.setMessage(_("Unkown command specified. "
                                     "Use \"apping -h\" to see help.\n\n"));
            appingError.showText();
    }
    if (handler != nullptr)
        handler->process(argc - 2, argv + 2);
    
    return 0;
}
