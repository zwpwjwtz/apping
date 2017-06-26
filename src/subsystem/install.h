#ifndef INSTALL_H
#define INSTALL_H

#include "app.h"


class AppingInstall : public AppingApp
{
public:
    AppingInstall();
    void process(int argc, const char *argv[]);
};

#endif // INSTALL_H
