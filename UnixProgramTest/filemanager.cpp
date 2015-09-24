#include "filemanager.h"
#include <QDebug>
#include <unistd.h>
#include <sys/time.h>
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

QString FileManager::getCurrentPath()
{
    long pathSize = pathconf(".", _PC_PATH_MAX);
    if (pathSize == -1)
        return "";

    char pathBuf[pathSize];
    qDebug() << "Path Size: " << pathSize;

    getcwd(pathBuf, sizeof(pathBuf));
    return pathBuf;
}


void FileManager::copyFile(QString fromFile, QString toFile)
{
    struct timeval startTime, endTime;

    gettimeofday(&startTime, NULL);
    if (access(fromFile.toLatin1(), F_OK) == -1) {
        emit setMessage(fromFile + ":No This File");
        return;
    }

    int toFd;

    toFd = open(toFile.toLatin1(), O_WRONLY | O_CREAT | O_TRUNC,
                S_IRUSR | S_IWUSR);
    if (toFd == -1) {
        emit setMessage(QString("Create toFile failed:") + strerror(errno));
        return;
    }

    struct stat statBuf;
    fstat(toFd, &statBuf);

    int fileSize = statBuf.st_size;

    int fromFd;

    fromFd = open(fromFile.toLatin1(), O_RDONLY);
    if (fromFd == -1) {
        emit setMessage(QString("Open fromFile failed:") + strerror(errno));
        return;
    }
    emit setMessage("Start Copying file...");

    char fileDataBuf[65536] = {0};
    ssize_t readCount = 0;
    int i = 0;

    while ((readCount = read(fromFd, fileDataBuf, sizeof(fileDataBuf))) > 0) {
        write(toFd, fileDataBuf, readCount);
        emit setMessage(QString("CopyFile :%1").arg(readCount));
        emit fileProgressValue(i++);
    }

    close(toFd);
    close(fromFd);

    gettimeofday(&endTime, NULL);
    float timeUse = (endTime.tv_sec - startTime.tv_sec) +
            (endTime.tv_usec - startTime.tv_usec);
    qDebug() << "Use Time: " << timeUse << "us" << endl;
}
