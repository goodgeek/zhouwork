#include "filemanager.h"
#include <QDebug>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <QMetaType>
#include <errno.h>
#include <time.h>

FileManager *FileManager::pfileManager = NULL;

FileManager::FileManager()
{
    pfileManager = this;

    int role = Qt::UserRole;
    fileHash.insert(role++, "fileName");
    fileHash.insert(role++, "fileSize");
    fileHash.insert(role++, "fileSort");
    fileHash.insert(role++, "blockSize");
    fileHash.insert(role++, "blockCount");
    fileHash.insert(role++, "mTime");
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
    case 3:
        retValue = fModel->blkSize;
        break;
    case 4:
        retValue = fModel->blockCount;
        break;
    case 5:
        retValue = fModel->mTime;
        break;
    default:
        retValue = "nukown";
    }
    return retValue;
}

QHash<int, QByteArray> FileManager::roleNames() const
{
    return fileHash;
}

int FileManager::rowCount(const QModelIndex &parent) const
{
    return fileModelList.count();
}

void *FileManager::threadFiles(void *arg)
{
    QString filePath = *(QString *)arg;

    DIR *dirp;
    dirp = opendir(filePath.toLatin1());
    if (dirp == NULL) {
        qDebug() << "opendir failed" << endl;
        return NULL;
    }

    struct dirent *drt;
    struct stat   statBuf;

    //rewinddir(dirp);
    while ((drt = readdir(dirp)) != NULL) {
        FileModel *fModel = new FileModel();
        QString fileName = drt->d_name;
        if (pfileManager->fileExistList(fileName))
           continue;

        if (stat(fileName.toLatin1(), &statBuf) == -1) {
            qDebug() << "Invoke stat failed" << strerror(errno) << endl;
            continue;
        }

        fModel->fileSize = QString::number(statBuf.st_size / 1024) + " KB";
        fModel->blkSize = QString::number(statBuf.st_blksize) + " Bytes";
        fModel->blockCount = QString::number(statBuf.st_blocks);

        time_t file_mtime = statBuf.st_mtim.tv_sec;
        struct tm *file_tm = localtime(&file_mtime);
        char strfTimeBuf[64];
        strftime(strfTimeBuf, sizeof(strfTimeBuf), "%F %T", file_tm);
        fModel->mTime = QString(strfTimeBuf);

        QString fileMode = "nuknow";
        if (S_ISDIR(statBuf.st_mode)) {
            fileMode = "Directory";
        } else if (S_ISREG(statBuf.st_mode)) {
            fileMode = "Reg File";
        }
        fModel->fileSort = fileMode;

        fModel->fileName = fileName;
        pfileManager->fileModelList.append(fModel);
    }

    qDebug() << "Thread Files end File Count:" << endl;
}

bool FileManager::fileExistList(QString fileName)
{
    for (int i = 0; i < fileModelList.count(); i++)
    {
        FileModel *fModel = fileModelList.at(i);
        if (fModel->fileName == fileName)
            return true;
    }
    return false;
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
    emit layoutChanged();
}
