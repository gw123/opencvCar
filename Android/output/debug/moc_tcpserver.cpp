/****************************************************************************
** Meta object code from reading C++ file 'tcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TcpDmeo1/tcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TcpServer_t {
    QByteArrayData data[10];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpServer_t qt_meta_stringdata_TcpServer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpServer"
QT_MOC_LITERAL(1, 10, 12), // "statusChange"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 2), // "id"
QT_MOC_LITERAL(4, 27, 5), // "isRun"
QT_MOC_LITERAL(5, 33, 6), // "status"
QT_MOC_LITERAL(6, 40, 8), // "onFinish"
QT_MOC_LITERAL(7, 49, 7), // "request"
QT_MOC_LITERAL(8, 57, 23), // "onTcpServerStatusChange"
QT_MOC_LITERAL(9, 81, 6) // "stauts"

    },
    "TcpServer\0statusChange\0\0id\0isRun\0"
    "status\0onFinish\0request\0onTcpServerStatusChange\0"
    "stauts"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpServer[] = {

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
       1,    3,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   36,    2, 0x0a /* Public */,
       8,    3,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    3,    4,    9,

       0        // eod
};

void TcpServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpServer *_t = static_cast<TcpServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->statusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->onFinish((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->onTcpServerStatusChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpServer::*_t)(int , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpServer::statusChange)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject TcpServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_TcpServer.data,
      qt_meta_data_TcpServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpServer.stringdata0))
        return static_cast<void*>(const_cast< TcpServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int TcpServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void TcpServer::statusChange(int _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TcpWorker_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpWorker_t qt_meta_stringdata_TcpWorker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TcpWorker"
QT_MOC_LITERAL(1, 10, 6), // "proess"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "total"
QT_MOC_LITERAL(4, 24, 6), // "finish"
QT_MOC_LITERAL(5, 31, 6), // "result"
QT_MOC_LITERAL(6, 38, 11), // "onReadyRead"
QT_MOC_LITERAL(7, 50, 14) // "onDisconnected"

    },
    "TcpWorker\0proess\0\0total\0finish\0result\0"
    "onReadyRead\0onDisconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       4,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   42,    2, 0x0a /* Public */,
       7,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    1,    3,
    QMetaType::Void, QMetaType::QImage,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TcpWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TcpWorker *_t = static_cast<TcpWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->proess((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->finish((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->onReadyRead(); break;
        case 3: _t->onDisconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TcpWorker::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpWorker::proess)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (TcpWorker::*_t)(QImage );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TcpWorker::finish)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject TcpWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TcpWorker.data,
      qt_meta_data_TcpWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpWorker.stringdata0))
        return static_cast<void*>(const_cast< TcpWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int TcpWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TcpWorker::proess(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TcpWorker::finish(QImage _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_TcpWorkThread_t {
    QByteArrayData data[1];
    char stringdata0[14];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TcpWorkThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TcpWorkThread_t qt_meta_stringdata_TcpWorkThread = {
    {
QT_MOC_LITERAL(0, 0, 13) // "TcpWorkThread"

    },
    "TcpWorkThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TcpWorkThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void TcpWorkThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TcpWorkThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_TcpWorkThread.data,
      qt_meta_data_TcpWorkThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TcpWorkThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TcpWorkThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TcpWorkThread.stringdata0))
        return static_cast<void*>(const_cast< TcpWorkThread*>(this));
    return QThread::qt_metacast(_clname);
}

int TcpWorkThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
