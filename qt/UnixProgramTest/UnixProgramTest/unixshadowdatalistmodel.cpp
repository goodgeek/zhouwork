#include "unixshadowdatalistmodel.h"
#include <shadow.h>
#include <QDebug>

UnixShadowDataListModel::UnixShadowDataListModel()
{
    int role = Qt::UserRole;

    shadowHashData.insert(role++, "spName");
    shadowHashData.insert(role++, "spPwdp");
    shadowHashData.insert(role++, "spLstchg");
    shadowHashData.insert(role++, "spMin");
    shadowHashData.insert(role++, "spMax");
    shadowHashData.insert(role++, "spWarn");
    shadowHashData.insert(role++, "spInact");
    shadowHashData.insert(role++, "spExpire");
    shadowHashData.insert(role++, "spFlag");
}

UnixShadowDataListModel::~UnixShadowDataListModel()
{
    for (int i = 0; i < shadowDataList.count(); i++)
    {
        delete shadowDataList.at(i);
    }
}

int UnixShadowDataListModel::rowCount(const QModelIndex &parent) const
{
    return shadowDataList.count();
}

QHash<int, QByteArray> UnixShadowDataListModel::roleNames() const
{
    return shadowHashData;
}

QVariant UnixShadowDataListModel::data(const QModelIndex &index, int role) const
{
    ShadowData *shData = shadowDataList.at(index.row());

    QString retData;

    switch (role - Qt::UserRole) {
    case 0:
        retData = shData->spName;
        break;
    case 1:
        retData = shData->spPwdp;
        break;
    case 2:
        retData = shData->spLstchg;
        break;
    case 3:
        retData = shData->spMin;
        break;
    case 4:
        retData = shData->spMax;
        break;
    case 5:
        retData = shData->spWarn;
        break;
    case 6:
        retData = shData->spInact;
        break;
    case 7:
        retData = shData->spExpire;
        break;
    case 8:
        retData = shData->spFlag;
        break;
    default:
        retData = "Unkown";
        break;
    }

    return retData;
}

void UnixShadowDataListModel::getShadowData()
{
    struct spwd *spData;

    shadowDataList.clear();
    setspent();
    while ((spData = getspent()) != NULL) {
        ShadowData *swData = new ShadowData();
        swData->spExpire = QString::number(spData->sp_expire);
        swData->spFlag = QString::number(spData->sp_flag);
        swData->spInact = QString::number(spData->sp_inact);
        swData->spLstchg = QString::number(spData->sp_lstchg);
        swData->spMax = QString::number(spData->sp_max);
        swData->spMin = QString::number(spData->sp_min);
        swData->spName = spData->sp_namp;
        swData->spPwdp = spData->sp_pwdp;
        swData->spWarn = QString::number(spData->sp_warn);
        shadowDataList.append(swData);
    }
    endspent();

    qDebug() << shadowDataList.count() << endl;
    emit layoutChanged();
}
