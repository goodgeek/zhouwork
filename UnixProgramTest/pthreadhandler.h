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
    //int fd;
};

#endif // PTHREADHANDLER_H
