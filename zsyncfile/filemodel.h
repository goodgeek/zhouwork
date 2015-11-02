#ifndef FILEMODEL_H
#define FILEMODEL_H

#include <QObject>

class FileModel
{
public:
    FileModel();
    QString fileName;
    QString fileSize;
    QString fileSort;
    QString blkSize;
    QString blockCount;
    QString aTime;
    QString cTime;
    QString mTime;
};

#endif // FILEMODEL_H
