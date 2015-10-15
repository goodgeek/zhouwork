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

}

void *pthread_handler1(void *)
{
    /*
    struct timespec startTime, endTime;

    clock_gettime(CLOCK_REALTIME, &startTime);

    int sfd = open("1111.rmvb", O_RDONLY);
    if (sfd == -1) {
        qDebug() << "Open Source File failed" << strerror(errno);
        return NULL;
    }

    int dfd = open("888.rmvb", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    if (dfd == -1) {
        qDebug() << "Create File failed" << strerror(errno);
        return NULL;
    }

    char fileBuf[FILEBUFSIZE];

    ssize_t nbytes;

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
    }

    close(dfd);
    close(sfd);

    clock_gettime(CLOCK_REALTIME, &endTime);

    qDebug() << "Copy File Time: " << endTime.tv_sec - startTime.tv_sec << endl;
    qDebug() << (endTime.tv_nsec - startTime.tv_nsec) / 1000 / 1000 << ":ms"<<endl;
    */
    qDebug() << "Thread 1 done";
}


void *pthread_handler2(void *)
{
    FILE *sfp, *dfp;

    QTime handTime;
    handTime.start();

    sfp = fopen("1111.rmvb", "r");
    if (sfp == NULL) {
        qDebug() << "Open file failed" << endl;
        return NULL;
    }

    dfp = fopen("999.rmvb", "w+");
    if (dfp == NULL) {
        qDebug() << "Crate File failed" << endl;
        return NULL;
    }

    char fileBuf[FILEBUFSIZE];
    size_t nbytes;

    while (1) {
        nbytes = fread(fileBuf, FILEBUFSIZE, 1, sfp);
        if (nbytes < FILEBUFSIZE) {
            if (feof(sfp)) {
                fwrite(fileBuf, FILEBUFSIZE, 1, dfp);
                break;
            }
            else if (ferror(sfp)) {
                break;
            }
        }
        fwrite(fileBuf, FILEBUFSIZE, 1, dfp);
    }

    fclose(sfp);
    fclose(dfp);

    qDebug() << "Handtime: " << handTime.elapsed() << endl;
    qDebug() << "Thread 2 done";
}


void PthreadHandler::startThread()
{
    int err;
    pthread_t tid1, tid2;

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

