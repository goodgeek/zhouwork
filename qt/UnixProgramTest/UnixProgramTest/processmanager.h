#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <QObject>

class ProcessManager : public QObject
{
    Q_OBJECT
public:
    ProcessManager();
    Q_INVOKABLE void getIdInfos();
signals:
    void setMessage(QString mesg);
};

#endif // PROCESSMANAGER_H
