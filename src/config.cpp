#include <cstdio>
#include <cstring>
#include <unistd.h>
#include "config.h"

#define APPING_CONFIG_FILE_DEFAULT      "/etc/apping/apping.conf"
#define APPING_CONFIG_FILE_EXIST        0
#define APPING_CONFIG_FILE_READ         1
#define APPING_CONFIG_FILE_RW           2


AppingConfig::ErrorNumber Apping_checkConfigFile(const char* filePath,
                                                        int testMode)
{
    if (filePath == nullptr)
        return AppingConfig::ErrorNumber::ConfigFileNotFound;

    if (testMode == APPING_CONFIG_FILE_EXIST)
    {
        if (access(filePath, F_OK) != 0)
            return AppingConfig::ErrorNumber::ConfigFileNotFound;
    }
    else if (testMode == APPING_CONFIG_FILE_READ)
    {
        if (access(filePath, F_OK  | R_OK) != 0)
            return AppingConfig::ErrorNumber::CannotReadConfig;
    }
    else if (testMode == APPING_CONFIG_FILE_READ)
    {
        if (access(filePath, F_OK  | R_OK) == 0)
            return AppingConfig::ErrorNumber::CannotWriteConfig;
    }

    return AppingConfig::ErrorNumber::OK;
}

AppingConfig::AppingConfig()
{
    configFile = nullptr;

    ErrorNumber errNumber = Apping_checkConfigFile(APPING_CONFIG_FILE_DEFAULT,
                                                   APPING_CONFIG_FILE_EXIST);
    if (errNumber != ErrorNumber::OK)
        return;

    configFile = new char[strlen(APPING_CONFIG_FILE_DEFAULT) + 1];
    strcpy(configFile, APPING_CONFIG_FILE_DEFAULT);
}

AppingConfig::~AppingConfig()
{
    closeConfigFile();
}

bool AppingConfig::closeConfigFile()
{
    file.close();
    return true;
}


AppingConfig::ErrorNumber AppingConfig::getConfig(const char* recordKey,
                                                  char*& recordValue)
{
    if (!openConfigFile(APPING_CONFIG_FILE_READ))
        return ErrorNumber::CannotReadConfig;

    return ErrorNumber::OK;
}


bool AppingConfig::openConfigFile(int openMode)
{
    if (Apping_checkConfigFile(configFile, openMode) != ErrorNumber::OK)
        return false;

    if (openMode == APPING_CONFIG_FILE_READ)
    file.open(configFile, std::ios_base::in | std::ios_base::binary);
    if (!file.is_open())
        return false;
    else
        return true;
}


AppingConfig::ErrorNumber AppingConfig::setConfig(const char* recordKey,
                                                  char*& recordValue)
{
    if (!openConfigFile(APPING_CONFIG_FILE_RW))
        return ErrorNumber::CannotWriteConfig;

    return ErrorNumber::OK;
}

AppingConfig::ErrorNumber AppingConfig::setConfigFile(const char* path)
{
    if (path == nullptr)
        return ErrorNumber::ConfigFileNotFound;
    if (access(path, F_OK | R_OK))
        return ErrorNumber::CannotReadConfig;
    if (access(path, F_OK | W_OK))
        return ErrorNumber::CannotWriteConfig;

    if (configFile != nullptr)
        delete configFile;
    configFile = new char[strlen(path) + 1];
    strcpy(configFile, path);
    return ErrorNumber::OK;
}

AppingConfig appingConfig;
