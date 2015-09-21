#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>

class FileManager : public QObject
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = 0);

    Q_INVOKABLE QString getPid();
    Q_INVOKABLE bool openFile();
    Q_INVOKABLE QString readFile();
signals:
    QString setMessage(QString msg);
public slots:
private:
    int fd;
};

#endif // FILEMANAGER_H
