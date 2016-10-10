#ifndef UNIXSHADOWDATALISTMODEL_H
#define UNIXSHADOWDATALISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "shadowdata.h"

class UnixShadowDataListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    UnixShadowDataListModel();
    ~UnixShadowDataListModel();

    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void getShadowData();
signals:

public slots:
private:
    QHash<int, QByteArray> shadowHashData;
    QList<ShadowData *> shadowDataList;
};

#endif // UNIXSHADOWDATALISTMODEL_H
