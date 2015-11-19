#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <filemodel.h>

class FileManager : public QAbstractListModel
{
    Q_OBJECT
public:
    FileManager();

    Q_INVOKABLE void getFiles(QString path);
    Q_INVOKABLE void onButtonClicked(int index);

    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
signals:
    void sendErrMsg(QString errMsg);
private:
    QHash<int, QByteArray> fileHash;
    QList<FileModel *> fileModelList;
    bool fileExistList(QString fileName);

    static void *threadFiles(void *arg);
    static FileManager *pfileManager;
};

#endif // FILEMANAGER_H
