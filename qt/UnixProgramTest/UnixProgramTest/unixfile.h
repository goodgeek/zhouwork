#ifndef UNIXFILE_H
#define UNIXFILE_H

#include <QObject>

class UnixFile
{
public:
    UnixFile();

    QString iNode;
    QString fileName;
    QString fileSize;
    QString fileMode;
    QString fileUid;
    QString fileStTime;
    QString fileAccess;
};

#endif // UNIXFILE_H
