#include "filemanager.h"
#include <QDebug>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QTextCodec>
#include <threadfileread.h>

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
    fd = open("222.log", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);

    if (fd == -1)
    {
        emit setMessage(QString("Open File failed: ") + strerror(errno));
        qDebug() << "Open File failed: " << strerror(errno) << endl;
        return false;
    }

    struct stat statBuf;

    if (stat("222.log", &statBuf) > 0)
    {
        emit setMessage(QString("File size: ") + QString::number(statBuf.st_uid));
    }
    else
    {
        emit setMessage(QString("Get File size faild: %1").arg(strerror(errno)));
    }

    off_t fileSeek = lseek(fd, 0, SEEK_CUR);
    emit setMessage(QString("File seek :%1").arg(fileSeek));
    emit setMessage("Open File success fd: " + QString::number(fd));

    return true;
}

void FileManager::readFile()
{
    ThreadFileRead *threadFileRead = new ThreadFileRead();
    connect(threadFileRead, SIGNAL(getMessage(QString)), this, SLOT(onReadFile(QString)));
    threadFileRead->setFd(fd);
    threadFileRead->start();
}

void FileManager::onReadFile(QString msg)
{
    emit setMessage(msg);
}

void FileManager::closeFile()
{
    close(fd);
}
