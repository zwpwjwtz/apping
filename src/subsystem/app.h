#ifndef APP_H
#define APP_H

#include "../error.h"
#include "../i18n.h"
#include "../main.h"
#include "../backend/inst_launcher.h"


class AppingApp
{
public:
    AppingApp();
    virtual void process(int argc, const char *argv[]) = 0;

protected:
    const char* getBackend();
    bool initBackend();

    int subsystem;
    inst_launcher* backend;
};

#endif // APP_H
