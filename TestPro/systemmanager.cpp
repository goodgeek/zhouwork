#include "systemmanager.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <QDebug>

SystemManager::SystemManager()
{

}

SystemManager::~SystemManager()
{

}

QString SystemManager::getInfo()
{
    int fd = open("test.file", O_CREAT | O_APPEND);
    if (fd == -1) {
        qDebug() << "Open file error" << strerror(errno);
        return "";

    }
    qDebug() << "Open file ok";
    close(fd);

    return "ok";
}

