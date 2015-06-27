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
};

#endif // SYSTEMMANAGER_H
