#include "pthreadhandler.h"
#include <pthread.h>
#include <QDebug>
#include <QTime>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <errno.h>
#include <QThread>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <signal.h>
#include <setjmp.h>
#include <sys/uio.h>
#include <sys/select.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <dirent.h>

static int fd;
static FILE *mfp;
static char memFileBuf[1024];
pthread_mutex_t   mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t    cond = PTHREAD_COND_INITIALIZER;
pthread_barrier_t barrier;
pthread_once_t    ponce = PTHREAD_ONCE_INIT;
pthread_key_t     pkey;
static bool doRead = false;
static jmp_buf jmpBuff;
#define FILEBUFSIZE 65535

PthreadHandler::PthreadHandler()
{
    testList = new QList<int>();
}

void *PthreadHandler::pthread_handler1(void *)
{
    /*
    struct timespec startTime, endTime;

    clock_gettime(CLOCK_REALTIME, &startTime);

    int sfd = open("1111.rmvb", O_RDONLY);
    if (sfd == -1) {
        qDebug() << "Open Source File failed" << strerror(errno);
        return NULL;
    }

    struct stat statBuf;

    if (fstat(sfd, &statBuf) == -1) {
        qDebug() << "fstat failed" << strerror(errno) << endl;
        return NULL;
    }

    int dfd = open("888.rmvb", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (dfd == -1) {
        qDebug() << "Create File failed" << strerror(errno);
        return NULL;
    }

    char fileBuf[FILEBUFSIZE];

    size_t nbytes;

    while (1) {
        nbytes = read(sfd, fileBuf, FILEBUFSIZE);
        if (nbytes == 0) {
            break;
        }
        else if (nbytes == -1) {
            qDebug() << "Read Source File failed" << strerror(errno);
            break;
        }
        
        if (write(dfd, fileBuf, nbytes) == -1) {
            qDebug() << "Write File failed" << strerror(errno);
            break;
        }

        kill(getpid(), SIGUSR1);
    }

    close(dfd);
    close(sfd);

    clock_gettime(CLOCK_REALTIME, &endTime);

    qDebug() << "Copy File Time: " << endTime.tv_sec - startTime.tv_sec << endl;
    qDebug() << (endTime.tv_nsec - startTime.tv_nsec) / 1000 / 1000 << ":ms"<<endl;

    qDebug() << "Thread 1 done";
    */
}

void PthreadHandler::findFile(QString dirName)
{
    DIR *dir;
    struct dirent *dirInfo;
    struct stat statBuf;

    dir = opendir(dirName.toLatin1());
    if (dir == NULL) {
        qDebug() << "Open Source Dir failed" << endl;
        return;
    }

    int fileCount = 0;
    while ((dirInfo = readdir(dir)) != NULL) {
        fileCount++;

        if (QString(dirInfo->d_name) == ".") {
            continue;
        }
        if (QString(dirInfo->d_name) == "..") {
            continue;
        }

        if (stat(dirInfo->d_name, &statBuf) == -1) {
            qDebug() << "Get File " << dirInfo->d_name << "failed:" <<
                        strerror(errno);
        }

        if (S_ISDIR(statBuf.st_mode)) {
            findFile(dirInfo->d_name);
        }

        qDebug() << "File Name: " << dirInfo->d_name << "File Type:"
                 << dirInfo->d_type << "File inode: " << dirInfo->d_ino;

    }
    qDebug() << "File Count: " << fileCount << endl;

    closedir(dir);
}

void *PthreadHandler::pthread_handler2(void *)
{
    findFile("./");
}

void sighandler(int signo)
{

}

void PthreadHandler::startThread()
{
    int err;
    pthread_t tid1, tid2;
    struct sigaction act;

    act.sa_flags = 0;
    if (sigemptyset(&act.sa_mask) == -1) {
        qDebug() << "sigemptyset failed" << strerror(errno) << endl;
        return;
    }

    act.sa_handler = sighandler;
    if (sigaction(SIGUSR1, &act, NULL) == -1) {
        qDebug() << "Sigaction failed" << strerror(errno) << endl;
        return;
    }

    err = pthread_create(&tid1, NULL, pthread_handler1, NULL);
    if (err != 0) {
        qDebug() << "Pthread 1 create failed";
    }

    err = pthread_create(&tid2, NULL, pthread_handler2, NULL);
    if (err != 0) {
        qDebug() << "Pthread 2 create failed";
    }

    pthread_join(tid2, NULL);
    pthread_join(tid1, NULL);

    qDebug() << "Thead main done" << endl;
}
