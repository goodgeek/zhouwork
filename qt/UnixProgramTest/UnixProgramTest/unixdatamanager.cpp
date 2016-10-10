#include "unixdatamanager.h"
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <QDebug>

UnixDataManager::UnixDataManager()
{
    int role = Qt::UserRole;

    dataHash.insert(role++, "pwName");
    dataHash.insert(role++, "pwPasswd");
    dataHash.insert(role++, "pwUid");
    dataHash.insert(role++, "pwGid");
    dataHash.insert(role++, "pwGeco");
    dataHash.insert(role++, "pwDir");
    dataHash.insert(role++, "pwShell");
}

int UnixDataManager::rowCount(const QModelIndex &parent) const
{
    return  pwdDataList.count();
}


QHash<int, QByteArray> UnixDataManager::roleNames() const
{
    return dataHash;
}

QVariant UnixDataManager::data(const QModelIndex &index, int role) const
{
    PwdObject *pwdObject = pwdDataList.at(index.row());
    QString retValue;

    switch (role - Qt::UserRole) {
    case 0:
        retValue = pwdObject->name;
        break;
    case 1:
        retValue = pwdObject->passwd;
        break;
    case 2:
        retValue = pwdObject->uid;
        break;
    case 3:
        retValue = pwdObject->gid;
        break;
    case 4:
        retValue = pwdObject->dir;
        break;
    case 5:
        retValue = pwdObject->shell;
        break;
    default:
        retValue = "Unkonw";
        break;
    }

    return retValue;
}

void UnixDataManager::getDataList()
{
    struct passwd *pt;

    pwdDataList.clear();
    setpwent();
    while ((pt = getpwent()) != NULL) {
        PwdObject *pwdObject = new PwdObject();
        pwdObject->dir = QString::number(pt->pw_uid);
        pwdObject->gecos = pt->pw_gecos;
        pwdObject->gid = QString::number(pt->pw_gid);
        pwdObject->name = pt->pw_name;
        pwdObject->passwd = pt->pw_passwd;
        pwdObject->shell = pt->pw_shell;
        pwdObject->uid = QString::number(pt->pw_uid);

        pwdDataList.append(pwdObject);
    }
    endpwent();



    emit layoutChanged();
}
