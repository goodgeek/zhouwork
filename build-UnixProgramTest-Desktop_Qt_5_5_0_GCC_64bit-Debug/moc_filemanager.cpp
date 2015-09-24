/****************************************************************************
** Meta object code from reading C++ file 'filemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UnixProgramTest/filemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileManager_t {
    QByteArrayData data[15];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileManager_t qt_meta_stringdata_FileManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileManager"
QT_MOC_LITERAL(1, 12, 10), // "setMessage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "msg"
QT_MOC_LITERAL(4, 28, 17), // "fileProgressValue"
QT_MOC_LITERAL(5, 46, 9), // "fileValue"
QT_MOC_LITERAL(6, 56, 10), // "onReadFile"
QT_MOC_LITERAL(7, 67, 6), // "getPid"
QT_MOC_LITERAL(8, 74, 8), // "openFile"
QT_MOC_LITERAL(9, 83, 8), // "readFile"
QT_MOC_LITERAL(10, 92, 9), // "closeFile"
QT_MOC_LITERAL(11, 102, 14), // "getCurrentPath"
QT_MOC_LITERAL(12, 117, 8), // "copyFile"
QT_MOC_LITERAL(13, 126, 8), // "fromFile"
QT_MOC_LITERAL(14, 135, 6) // "toFile"

    },
    "FileManager\0setMessage\0\0msg\0"
    "fileProgressValue\0fileValue\0onReadFile\0"
    "getPid\0openFile\0readFile\0closeFile\0"
    "getCurrentPath\0copyFile\0fromFile\0"
    "toFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   65,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   68,    2, 0x02 /* Public */,
       8,    0,   69,    2, 0x02 /* Public */,
       9,    0,   70,    2, 0x02 /* Public */,
      10,    0,   71,    2, 0x02 /* Public */,
      11,    0,   72,    2, 0x02 /* Public */,
      12,    2,   73,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // methods: parameters
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,

       0        // eod
};

void FileManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileManager *_t = static_cast<FileManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->setMessage((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: _t->fileProgressValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onReadFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: { QString _r = _t->getPid();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->openFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->readFile(); break;
        case 6: _t->closeFile(); break;
        case 7: { QString _r = _t->getCurrentPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 8: _t->copyFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef QString (FileManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileManager::setMessage)) {
                *result = 0;
            }
        }
        {
            typedef void (FileManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileManager::fileProgressValue)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FileManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FileManager.data,
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
    return QObject::qt_metacast(_clname);
}

int FileManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
QString FileManager::setMessage(QString _t1)
{
    QString _t0 = QString();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
void FileManager::fileProgressValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
