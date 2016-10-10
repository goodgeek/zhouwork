#ifndef THREADFILEREAD_H
#define THREADFILEREAD_H

#include <QObject>
#include <QThread>

class ThreadFileRead : public QThread
{
    Q_OBJECT
public:
    void setFd(int aFd);
signals:
    void getMessage(QString msg);
public slots:
protected:
    void run();
private:
    int fd;
};

#endif // THREADFILEREAD_H
