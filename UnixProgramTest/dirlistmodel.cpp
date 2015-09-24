#include "dirlistmodel.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unixfile.h>
#include <QDebug>
#include <errno.h>
#include <sys/utsname.h>

DirListModel::DirListModel()
{
    int role = Qt::UserRole;
    fileRoleName.insert(role++, "fileMode");
    fileRoleName.insert(role++, "fileName");
    fileRoleName.insert(role++, "fileSize");
    fileRoleName.insert(role++, "fiileStTime");
    fileRoleName.insert(role++, "fileUid");
    fileRoleName.insert(role++, "iNode");

    //getDirList();
}

QVariant DirListModel::data(const QModelIndex &index, int role) const
{
    UnixFile *unixFile = fileList.at(index.row());

    QString retData;

    switch (role - Qt::UserRole) {
    case 0:
        retData = unixFile->fileMode;
        break;
    case 1:
        retData = unixFile->fileName;
        break;
    case 2:
        retData = unixFile->fileSize;
        break;
    case 3:
        retData = unixFile->fileStTime;
        break;
    case 4:
        retData = unixFile->fileUid;
        break;
    case 5:
        retData = unixFile->iNode;
        break;
    default:
        retData = "";
        break;
    }

    return retData;
}


QHash<int, QByteArray> DirListModel::roleNames() const
{
    return fileRoleName;
}

int DirListModel::rowCount(const QModelIndex &parent) const
{
    return fileList.count();
}

void  DirListModel::getDirList(QString path)
{
    DIR *dir;
    struct dirent *rent;

    fileList.clear();
    emit layoutChanged();

    dir = opendir(path.toLatin1());

    if (dir == NULL)
        return;

    while (rent = readdir(dir)) {
        UnixFile *file = new UnixFile();

        QString fName = rent->d_name;
        if (fName == "." || fName == "..")
            continue;

        struct stat statBuf;
        file->fileName = fName;
        qDebug() << "File: " << fName << endl;

        if (stat(fName.toLatin1(), &statBuf) == 0) {
            file->fileSize = QString::number(statBuf.st_size / 1024) + " KB";
            file->fileStTime = statBuf.st_mode;
            file->fileUid = QString::number(statBuf.st_uid);

            if (S_ISREG(statBuf.st_mode)) {
                file->fileMode = "Regular File";
            }
            else if (S_ISDIR(statBuf.st_mode)) {
                file->fileMode = "directory";
            }

            if (S_IRUSR & statBuf.st_mode) {
                file->fileAccess = "r";
            }
            if (S_IWUSR & statBuf.st_mode) {
                file->fileAccess += "w";
            }
            if (S_IXUSR & statBuf.st_mode)
            {
                file->fileAccess += "x";
            }
        }
        else {
            qDebug() << "Stat failed: " << strerror(errno) << endl;
        }

        fileList.append(file);
    }
    qDebug() <<  "Flie list count: " << fileList.count() << endl;
    closedir(dir);

    emit layoutChanged();
}


void DirListModel::getFunck()
{
    int fd;

    fd = open("333.log", O_RDWR | O_TRUNC);
    if (fd == -1) {
        qDebug() << "Open file 333.log failed:" << strerror(errno) << endl;
        return;
    }
    close(fd);
}
