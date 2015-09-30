#include "pthreadhandler.h"
#include <pthread.h>
#include <QDebug>
#include <unistd.h>

PthreadHandler::PthreadHandler()
{

}

void *pthread_handler1(void *)
{
    sleep(5);
    qDebug() << "Pthread 1 run";
    qDebug() << "Thead1 " << pthread_self() << endl;
    pthread_exit((void *)50);
}

void *pthread_handler2(void *)
{
    sleep(2);
    qDebug() << "Pthread 2 run";
    qDebug() << "Thead2 " << pthread_self() << endl;
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

    jovoid *threadvalue;
    pthread_join(tid1, &threadvalue);
    pthread_join(tid2, NULL);

    qDebug() << "Thead main " << pthread_self() << endl;
    qDebug() << "wait thread 1 value: " << (long)(threadvalue) << endl;
}

