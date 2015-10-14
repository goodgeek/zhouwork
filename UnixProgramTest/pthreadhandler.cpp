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

PthreadHandler::PthreadHandler()
{

}

void *pthread_handler1(void *)
{
    char readBuf[256] = {0};

    pthread_mutex_lock(&mutex);
    while (!doRead) {
        pthread_cond_wait(&cond, &mutex);
    }

    fseek(mfp, 0, SEEK_SET);
    while (1) {
        if (fgets(readBuf, sizeof(readBuf), mfp) == NULL) {
            if (feof(mfp)) {
                qDebug() << "Read File End";
                break;
            }
            else if (ferror(mfp)) {
                qDebug() << "Read file failed" << endl;
                break;
            }
        }
        qDebug() << "Read data: " << readBuf << endl;
    }
    pthread_mutex_unlock(&mutex);
}



void *pthread_handler2(void *)
{
    char *writeBuf = "cccccccccccccccccc";

    pthread_mutex_lock(&mutex);
    if (fputs(writeBuf, mfp) == EOF) {
        if (ferror(mfp)) {
            qDebug() << "Write file error" << endl;
        }
    }
    pthread_mutex_unlock(&mutex);
    doRead = true;
    pthread_cond_signal(&cond);
}

void sigHandler(int signo)
{
    qDebug() << "Receive Signal: " << signo << strsignal(signo);
    siglongjmp(jmpBuff, 1);
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

    mfp = fmemopen(memFileBuf, sizeof(memFileBuf), "w+");
    if (mfp == NULL) {
        qDebug() << "Open mem file failed" << strerror(errno) << endl;
    }


    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    fclose(mfp);

    qDebug() << "Thead main " << pthread_self() << endl;
}

