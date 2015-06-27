#include "systemmanager.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <QDebug>

SystemManager::SystemManager()
{

}

SystemManager::~SystemManager()
{

}

QString SystemManager::getInfo()
{
    pid_t chpid;

    chpid = fork();
    if (chpid == 0) {
        qDebug() << "I'm child process" << getpid();
        qDebug() << "I'm father is: " << getppid();
    }
    else {
        waitpid(chpid, NULL, 0);
        qDebug() << "I'm father process " << getpid();
    }

    return "over";
}

