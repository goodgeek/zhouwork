#include "pthreadhandler.h"
#include <pthread.h>
#include <QDebug>
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
#include <aio.h>

static int fd;
pthread_mutex_t   mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t    cond = PTHREAD_COND_INITIALIZER;
pthread_barrier_t barrier;
pthread_once_t    ponce = PTHREAD_ONCE_INIT;
pthread_key_t     pkey;
bool startWrite = false;
static jmp_buf jmpBuff;

PthreadHandler::PthreadHandler()
{

}

void *pthread_handler1(void *)
{
    char *writeBuf = "1.hello world\n";
    char *writeBuf2 = "2.what is your name\n";

    struct iovec ive[2];

    ive[0].iov_base = writeBuf;
    ive[0].iov_len = strlen(writeBuf);

    ive[1].iov_base = writeBuf2;
    ive[1].iov_len = strlen(writeBuf2);

    if (writev(fd, ive, 2) == -1) {
        qDebug() << "Write failed" << strerror(errno) << endl;
    }
}


void *pthread_handler2(void *)
{

    char *writeBuf = "aaaaaaaaaaaaaaaaaaaaaa\n";
    struct timespec waitTime = {0, 10000000};

    for (int i = 0; i < strlen(writeBuf); i++) {
        write(fd, writeBuf+i, 1);

        nanosleep(&waitTime, NULL);
    }

    qDebug() << "Thread 2 run success";
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

    fd = open("threadtest.log", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        qDebug() << "Open File failed" << strerror(errno) << endl;
        return;
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    close(fd);

    qDebug() << "Thead main " << pthread_self() << endl;
}

