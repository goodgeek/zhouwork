#ifndef UNIXDATAMANAGER_H
#define UNIXDATAMANAGER_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <pwdobject.h>

class UnixDataManager : public QAbstractListModel
{
    Q_OBJECT
public:
    UnixDataManager();
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;

    Q_INVOKABLE void getDataList();
private:
    QHash<int, QByteArray> dataHash;
    QList<PwdObject *> pwdDataList;
};

#endif // UNIXDATAMANAGER_H
