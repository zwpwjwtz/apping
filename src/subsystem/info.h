#ifndef INFO_H
#define INFO_H

#include "app.h"


class AppingInfo : public AppingApp
{
public:
    AppingInfo();
    void process(int argc, const char *argv[]);
};

#endif // INFO_H
