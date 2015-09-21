#include "filemanager.h"
#include <QDebug>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

FileManager::FileManager(QObject *parent) : QObject(parent)
{

}

QString FileManager::getPid()
{
    pid_t pid, ppid;

    pid = getpid();
    ppid = getppid();

    return QString::number(pid) + ": " + QString::number(ppid);

    emit setMessage("test info");
}

bool FileManager::openFile()
{
    fd = open("test.txt", O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd == -1)
    {
        qDebug() << "Open File failed: " << strerror(errno) << endl;
        return false;
    }

    emit setMessage("Open File success fd: " + QString::number(fd));

    char *dataBuf = "Hello world";

    if (write(fd, dataBuf, strlen(dataBuf)) == -1)
    {
        emit setMessage(QString("Write file is failed: ") + strerror(errno));
        return false;
    }
}

QString FileManager::readFile()
{
    /*
    char readBuf[1024];

    if (read(fd, readBuf, sizeof(readBuf)) == -1)
    {
        emit setMessage(QString("Read file is failed") + strerror(errno));
        return "";
    }

    emit setMessage(readBuf);
    close(fd);
    */
}
