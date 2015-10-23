#include "filemanager.h"
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

FileManager::FileManager()
{
    int role = Qt::UserRole;
    fileHash.insert(role++, "fileName");
    fileHash.insert(role++, "fileSize");
    fileHash.insert(role++, "fileSort");
}

QVariant FileManager::data(const QModelIndex &index, int role) const
{

}

QHash<int, QByteArray> FileManager::roleNames() const
{

}

int FileManager::rowCount(const QModelIndex &parent) const
{

}

void *FileManager::threadFiles(void *arg)
{

}

void FileManager::getFiles(QString path)
{
    pthread_t tidFile;
    int pthreadRet;

    pthreadRet = pthread_create(&tidFile, NULL, threadFiles, NULL);
    if (pthreadRet != 0) {
        emit sendErrMsg("Pthread_create failed");
        return;
    }

    pthread_join(tidFile, NULL);
}
