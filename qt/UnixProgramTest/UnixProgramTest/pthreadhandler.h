#ifndef PTHREADHANDLER_H
#define PTHREADHANDLER_H

#include <QObject>

class PthreadHandler : public QObject
{
    Q_OBJECT
public:
    PthreadHandler();
    Q_INVOKABLE void startThread();

signals:
    void copyFileProgress(int progressValue, int maxValue);

private:
    QList<int> *testList;

    static void findFile(QString dirName);
    static void *pthread_handler2(void *);
    static void *pthread_handler1(void *);
    //int fd;
};

#endif // PTHREADHANDLER_H
