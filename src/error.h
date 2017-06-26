#ifndef ERROR_H
#define ERROR_H

#include "main.h"

class AppingError
{
public:
    AppingError();
    void setAction(int actionType);
    void setMessage(const char* str);
    void showText();
private:
    int action;
    const char* message;
};

static AppingError appingError;

#endif // ERROR_H
