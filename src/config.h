#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>


class AppingConfig
{
public:
    enum ErrorNumber
    {
        OK = 0,
        ConfigFileNotFound = 1,
        CannotReadConfig = 2,
        CannotWriteConfig = 4,
        FormatError = 8,
        RecordNotFound = 16,
        RecordNotSaved = 32
    };

    AppingConfig();
    ~AppingConfig();
    ErrorNumber getConfig(const char* recordKey, char*& recordValue);
    ErrorNumber setConfig(const char* recordKey, char*& recordValue);
    ErrorNumber setConfigFile(const char* path);

private:
    bool closeConfigFile();
    bool openConfigFile(int openMode);
    char* configFile;
    std::fstream file;
};

extern "C" AppingConfig appingConfig; // Default configuration

#endif // CONFIG_H
