#ifndef UNIXDATAMANAGER_H
#define UNIXDATAMANAGER_H

#include <QObject>
#include <QAbstractListModel>

class UnixDataManager : public QAbstractListModel
{
    Q_OBJECT
public:
    UnixDataManager();
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
private:
    QHash<int, QByteArray> dataHash;
};

#endif // UNIXDATAMANAGER_H
