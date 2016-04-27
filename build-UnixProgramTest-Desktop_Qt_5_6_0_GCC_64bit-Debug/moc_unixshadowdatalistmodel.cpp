/****************************************************************************
** Meta object code from reading C++ file 'unixshadowdatalistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UnixProgramTest/unixshadowdatalistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'unixshadowdatalistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UnixShadowDataListModel_t {
    QByteArrayData data[3];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UnixShadowDataListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UnixShadowDataListModel_t qt_meta_stringdata_UnixShadowDataListModel = {
    {
QT_MOC_LITERAL(0, 0, 23), // "UnixShadowDataListModel"
QT_MOC_LITERAL(1, 24, 13), // "getShadowData"
QT_MOC_LITERAL(2, 38, 0) // ""

    },
    "UnixShadowDataListModel\0getShadowData\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UnixShadowDataListModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void UnixShadowDataListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UnixShadowDataListModel *_t = static_cast<UnixShadowDataListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getShadowData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UnixShadowDataListModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_UnixShadowDataListModel.data,
      qt_meta_data_UnixShadowDataListModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UnixShadowDataListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UnixShadowDataListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UnixShadowDataListModel.stringdata0))
        return static_cast<void*>(const_cast< UnixShadowDataListModel*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int UnixShadowDataListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
