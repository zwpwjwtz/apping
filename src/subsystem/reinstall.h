#ifndef REINSTALL_H
#define REINSTALL_H

#include "app.h"


class AppingReinstall : public AppingApp
{
public:
    AppingReinstall();
    void process(int argc, const char *argv[]);
};

#endif // REINSTALL_H
