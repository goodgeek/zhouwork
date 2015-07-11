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
    Q_INVOKABLE bool openFile();
    Q_INVOKABLE bool writeFile(QString fileData);
    Q_INVOKABLE QString readFile();
    Q_INVOKABLE void fileTest();
signals:
    void newInfo(QString info);
private:
    int fd;
};

#endif // SYSTEMMANAGER_H
