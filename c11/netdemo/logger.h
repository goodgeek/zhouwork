#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

class Logger
{
public:
    Logger();
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void logInfo(std::string info);
    void logDebug(std::string info);
    void logError(std::string info);
}

#endif
