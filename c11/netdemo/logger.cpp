#include "logger.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::logInfo(std::string info)
{
    return;
}

void Logger::logDebug(std::string info)
{
    return;
}

void Logger::logError(std::string info)
{
    return;
}

void Logger::logWrite(std::string logMsg)
{
    
}

bool Logger::isDirExist(std::string dirName)
{
    if (access(dirName.c_str(), F_OK) == 0) {
        return true;
    } else {
        return false;
    }
}
