#include "logger.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <error.h>
#include <string.h>
#include <time.h>

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::logInfo(std::string info)
{
    logWrite("INFO ", info);
    return;
}

void Logger::logDebug(std::string info)
{
    logWrite("DEBUG", info);
    return;
}

void Logger::logError(std::string info)
{
    logWrite("ERROR", info);
    return;
}

void Logger::logWrite(std::string logHeader, std::string logMsg)
{
    if (!isDirExist("logs")) {
        mkdir("logs", 0777);
    }

    time_t nowTime = time(NULL);
    struct tm *tPtr = localtime(&nowTime);

    char timeBuf[64];
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d.log", tPtr);

    char timeHeader[64];
    strftime(timeHeader, sizeof(timeHeader), "%H:%M:%S ", tPtr);
    std::string strTimeHeader = std::string(timeHeader);
    strTimeHeader = "[" + strTimeHeader + logHeader + "] ";

    std::string strLog = "logs/";
    strLog += timeBuf;
    const char *logFileName = strLog.c_str();

    int fd = open(logFileName, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        printf("Open log file failed:%s\n", strerror(fd));
        return;
    }

    logMsg =  strTimeHeader + logMsg + "\n";
    ssize_t nw = write(fd, logMsg.c_str(), logMsg.length());
    if (nw == -1) {
        printf("Write log file failed: %s\n", strerror(nw));
    }
    printf("%s", logMsg.c_str());

    close(fd);
}

bool Logger::isDirExist(std::string dirName)
{
    if (access(dirName.c_str(), F_OK) == 0) {
        return true;
    } else {
        return false;
    }
}
