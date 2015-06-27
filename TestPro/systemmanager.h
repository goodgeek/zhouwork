#ifndef SYSTEMMANAGER_H
#define SYSTEMMANAGER_H

#include <QObject>

class SystemManager : public QObject
{
    Q_OBJECT
public:
    SystemManager();
    ~SystemManager();
    Q_INVOKABLE QString getInfo();
signals:
    void newInfo(QString info);
};

#endif // SYSTEMMANAGER_H
