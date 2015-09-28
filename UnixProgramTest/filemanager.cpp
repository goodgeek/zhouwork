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
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

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


void FileManager::readFileForBuf()
{
    FILE *fp;

    struct timeval startTime, endTime;
    struct timespec sTime, eTime;

    clock_gettime(CLOCK_REALTIME, &sTime);
    gettimeofday(&startTime, NULL);
    char memBuf[4096];

    fp = fmemopen(memBuf, sizeof(memBuf), "w+");
    if (fp == NULL) {
        qDebug() << "fmemopen failed" << strerror(errno) << endl;
    }
    fputs("hello world\n", fp);

    fseek(fp, 0, SEEK_SET);
    char buf[256] = {0};
    fgets(buf, sizeof(buf), fp);
    qDebug() << "Read Buf: " << buf << endl;
    fclose(fp);


    time_t nowTime;
    if (time(&nowTime) == -1) {
        qDebug() << "Time failed" << strerror(errno) << endl;
    }

    struct tm *nowTm;
    nowTm = localtime(&nowTime);
    char timeBuf[256];
    strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d", nowTm);
    qDebug() << "Now Time: " << timeBuf << endl;

    /*
    fp = fopen("444.log", "r");
    if (fp == NULL) {
        qDebug() << "Open File failed" << endl;
        return;
    }

    char dataBuf[256];
    fpos_t ipos;

    while (fread(dataBuf, sizeof(dataBuf), 1, fp) != 0) {
        fgetpos(fp, &ipos);
        qDebug() << "File Pos: " << ipos << endl;
    }

    while (fgets(dataBuf, sizeof(dataBuf), fp) != NULL) {
        //emit setMessage(dataBuf);
    }
    if (ferror(fp)) {
        qDebug() << "Read File error" << endl;
    }
    else if (feof(fp)) {
        qDebug() << "Read File End" << endl;
    }

    fclose(fp);
    */

    gettimeofday(&endTime, NULL);
    float useTime = (endTime.tv_sec - startTime.tv_sec) +
            (endTime.tv_usec - startTime.tv_usec);
    qDebug() << "Use Time: " << useTime << "us" << endl;

    clock_gettime(CLOCK_REALTIME, &eTime);
    float uTime = eTime.tv_sec - sTime.tv_sec + eTime.tv_nsec - sTime.tv_nsec;
    qDebug() << "clock get use Time: " << uTime << endl;
}
