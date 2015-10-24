#include "filemanager.h"
#include <QDebug>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

FileManager::FileManager()
{
    int role = Qt::UserRole;
    fileHash.insert(role++, "fileName");
    fileHash.insert(role++, "fileSize");
    fileHash.insert(role++, "fileSort");
}

QVariant FileManager::data(const QModelIndex &index, int role) const
{
    FileModel *fModel = fileModelList.at(index.row());

    QString retValue;
    switch (role - Qt::UserRole) {
    case 0:
        retValue = fModel->fileName;
        break;
    case 1:
        retValue = fModel->fileSize;
        break;
    case 2:
        retValue = fModel->fileSort;
        break;
    default:
        retValue = "nukown";
    }
}

QHash<int, QByteArray> FileManager::roleNames() const
{
    return fileHash;
}

int FileManager::rowCount(const QModelIndex &parent) const
{
    return fileHash.count();
}

void *FileManager::threadFiles(void *arg)
{
    QString filePath = *(QString *)arg;

    DIR *dirp;
    dirp = opendir(filePath.toLatin1());
    if (dirp == NULL) {
        //emit sendErrMsg("opendir failed");
        qDebug() << "opendir failed" << endl;
        return NULL;
    }

    struct dirent *drt;

    rewinddir(dirp);
    while ((drt = readdir(dirp)) != NULL) {
        FileModel *fModel = new FileModel();
        fModel->fileName = drt->d_name;
           fileModelList.insert(fModel);
    }
    //emit layoutChanged();

    qDebug() << "Thread Files end" << filePath << endl;
}

void FileManager::getFiles(QString path)
{
    pthread_t tidFile;
    int pthreadRet;

    pthreadRet = pthread_create(&tidFile, NULL, threadFiles, (void *)&path);
    if (pthreadRet != 0) {
        emit sendErrMsg("Pthread_create failed");
        return;
    }

    pthread_join(tidFile, NULL);
}
