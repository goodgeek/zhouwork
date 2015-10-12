#ifndef PTHREADHANDLER_H
#define PTHREADHANDLER_H

#include <QObject>

class PthreadHandler : public QObject
{
    Q_OBJECT
public:
    PthreadHandler();
    Q_INVOKABLE void startThread();
private:
    //int fd;
};

#endif // PTHREADHANDLER_H
