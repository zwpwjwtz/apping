#ifndef ERROR_H
#define ERROR_H

#include "main.h"

#define APPING_ERROR_MESSAGE_MAXLEN 256

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

extern "C" AppingError appingError; // Default error handler

#endif // ERROR_H
