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
    //int fd = open()
}

bool SystemManager::openFile()
{
    fd = open("test.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        emit newInfo(QString("Open File failed: %1").arg(strerror(errno)));
        //qDebug() << "Open file failed" << strerror(errno);
        return false;
    }
    emit newInfo(QString("Open File success fd: %1").arg(fd));

    return true;
}

bool SystemManager::writeFile(QString fileData)
{
    ssize_t writeCount = write(fd, fileData.toLatin1(), fileData.length());
    if (writeCount == -1)
    {
        emit newInfo("Write File failed");
        return false;
    }
    newInfo("Write File success");

    return true;
}

QString SystemManager::readFile()
{
    char readBuf[1024] = {0};
    lseek(fd, SEEK_SET, 0);
    ssize_t nRead = read(fd, readBuf, sizeof(readBuf));
    if (nRead == -1)
    {
       emit("Read File failed");
        return "empty";
    }
    emit newInfo(QString::number(nRead));
    return readBuf;
}
