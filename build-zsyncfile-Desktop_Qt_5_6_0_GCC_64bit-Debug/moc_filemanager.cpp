/****************************************************************************
** Meta object code from reading C++ file 'filemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../zsyncfile/filemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileManager_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileManager_t qt_meta_stringdata_FileManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileManager"
QT_MOC_LITERAL(1, 12, 10), // "sendErrMsg"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "errMsg"
QT_MOC_LITERAL(4, 31, 8), // "getFiles"
QT_MOC_LITERAL(5, 40, 4), // "path"
QT_MOC_LITERAL(6, 45, 15), // "onButtonClicked"
QT_MOC_LITERAL(7, 61, 5) // "index"

    },
    "FileManager\0sendErrMsg\0\0errMsg\0getFiles\0"
    "path\0onButtonClicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x02 /* Public */,
       6,    1,   35,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,

       0        // eod
};

void FileManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileManager *_t = static_cast<FileManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendErrMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getFiles((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->onButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FileManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileManager::sendErrMsg)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FileManager::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_FileManager.data,
      qt_meta_data_FileManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileManager.stringdata0))
        return static_cast<void*>(const_cast< FileManager*>(this));
    return QAbstractListModel::qt_metacast(_clname);
}

int FileManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FileManager::sendErrMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
