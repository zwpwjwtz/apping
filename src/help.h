#ifndef HELP_H
#define HELP_H

class AppingHelp
{
public:
    AppingHelp();
    void setContext(const char* str);
    void showText();

private:
    const char* context;
};

#endif // HELP_H
