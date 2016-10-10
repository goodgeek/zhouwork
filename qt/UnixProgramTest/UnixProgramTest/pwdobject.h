#ifndef PWDOBJECT_H
#define PWDOBJECT_H

#include <QObject>

class PwdObject
{
public:
    PwdObject();

    QString name;
    QString passwd;
    QString uid;
    QString gid;
    QString gecos;
    QString dir;
    QString shell;
};

#endif // PWDOBJECT_H
