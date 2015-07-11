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
    fd = open("test.txt", O_RDWR | O_CREAT | O_SYNC, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        emit newInfo(QString("Open File failed: %1").arg(strerror(errno)));
        //qDebug() << "Open file failed" << strerror(errno);
        return false;
    }

    int fl = fcntl(fd, F_GETFL);
    switch (fl & O_ACCMODE)
    {
    case O_RDONLY:
        emit newInfo("File is Readonly");
        break;
    case O_RDWR:
        emit newInfo("File is Read write");
        break;
    case O_WRONLY:
        emit newInfo("File is Writeonly");
        break;
    default:
        emit newInfo("Unkown access mode");
        break;
    }
    if (fl & O_SYNC)
        emit newInfo("SYNC flag is set");

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
    fsync(fd);
    newInfo(QString("Write File success write size:%1").arg(writeCount));

    return true;
}

QString SystemManager::readFile()
{
    char readBuf[4096] = {0};

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

void SystemManager::fileTest()
{
    char readBuf[4096] = {0};

    lseek(fd, 0, SEEK_SET);
    int wfd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (wfd == -1)
    {
        emit newInfo(QString("create file failed"));
    }

    ssize_t nRead = read(fd, readBuf, sizeof(readBuf));
}
