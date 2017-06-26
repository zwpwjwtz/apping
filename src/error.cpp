#include <iostream>
#include "error.h"
#include "i18n.h"

AppingError::AppingError()
{
    action = APPING_ACTION_NONE;
    message = nullptr;
}

void AppingError::setAction(int actionType)
{
    action =  actionType;
}

void AppingError::setMessage(const char* str)
{
    message = str;
}

void AppingError::showText()
{
    std::cout << "apping: " << message << "\n";
}
