#include <iostream>
#include "help.h"
#include "i18n.h"


AppingHelp::AppingHelp()
{
    context = nullptr;
}

void AppingHelp::setContext(const char* str)
{
    context = str;
}

void AppingHelp::showText()
{
    std::cout <<
          _("Usage:  apping [OPTIONS] COMMAND [ARGUMENTS...]\n"
            "\n"
            "[COMMAND] can be one of the following actions:\n"
            "       info            Show the information of the application\n"
            "       install         Install the application specified\n"
            "       uninstall       Remove the application as well as its\n"
            "                       dependencies (if applicable)\n"
            "       reinstall       Reinstall the application\n"
            "\n"
            "apping is a simple tool for managing applications under Linux.\n"
            "It provides commands for searching, uninstalling and reinstalling \n"
            "package set (i.e. application), while keeping dependencies simple \n"
            "and clean.\n\n");
}
