#ifndef DIRLISTMODEL_H
#define DIRLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <unixfile.h>

class DirListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    DirListModel();
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void getDirList(QString path);
    Q_INVOKABLE void getFunck();
private:
    QHash<int, QByteArray> fileRoleName;
    QList<UnixFile *> fileList;
};

#endif // DIRLISTMODEL_H
