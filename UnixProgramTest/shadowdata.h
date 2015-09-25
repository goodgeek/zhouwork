#ifndef SHADOWDATA_H
#define SHADOWDATA_H

#include <QObject>
#include <shadow.h>

class ShadowData
{
public:
    ShadowData();

    QString spName;
    QString spPwdp;
    QString spLstchg;
    QString spMin;
    QString spMax;
    QString spWarn;
    QString spInact;
    QString spExpire;
    QString spFlag;
};

#endif // SHADOWDATA_H
