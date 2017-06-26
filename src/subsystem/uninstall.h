#ifndef UNINSTALL_H
#define UNINSTALL_H

#include "app.h"


class AppingUninstall : public AppingApp
{
public:
    AppingUninstall();
    void process(int argc, const char *argv[]);
};

#endif // UNINSTALL_H
