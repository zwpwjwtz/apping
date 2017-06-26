#ifndef APP_H
#define APP_H

#include "../main.h"


class AppingApp
{
public:
    AppingApp();
    virtual void process(int argc, const char *argv[]) = 0;

protected:
    int subsystem;
};

#endif // APP_H
