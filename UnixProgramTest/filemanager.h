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
    Q_INVOKABLE void readFile();
    Q_INVOKABLE void closeFile();
    Q_INVOKABLE QString getCurrentPath();
signals:
    QString setMessage(QString msg);
public slots:
    void onReadFile(QString msg);
private:
    int fd;
};

#endif // FILEMANAGER_H
