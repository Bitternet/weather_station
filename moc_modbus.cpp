/****************************************************************************
** Meta object code from reading C++ file 'modbus.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "modbus.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modbus.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusNetwork_t {
    QByteArrayData data[17];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusNetwork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusNetwork_t qt_meta_stringdata_ModbusNetwork = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ModbusNetwork"
QT_MOC_LITERAL(1, 14, 16), // "sendDataToSlaves"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "data"
QT_MOC_LITERAL(4, 37, 8), // "logPrint"
QT_MOC_LITERAL(5, 46, 3), // "msg"
QT_MOC_LITERAL(6, 50, 15), // "send_data_array"
QT_MOC_LITERAL(7, 66, 20), // "send_data_array_groz"
QT_MOC_LITERAL(8, 87, 14), // "openConnection"
QT_MOC_LITERAL(9, 102, 15), // "closeConnection"
QT_MOC_LITERAL(10, 118, 8), // "sendData"
QT_MOC_LITERAL(11, 127, 7), // "receive"
QT_MOC_LITERAL(12, 135, 12), // "receive_groz"
QT_MOC_LITERAL(13, 148, 15), // "errorSerialPort"
QT_MOC_LITERAL(14, 164, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(15, 193, 5), // "error"
QT_MOC_LITERAL(16, 199, 13) // "logSlavePrint"

    },
    "ModbusNetwork\0sendDataToSlaves\0\0data\0"
    "logPrint\0msg\0send_data_array\0"
    "send_data_array_groz\0openConnection\0"
    "closeConnection\0sendData\0receive\0"
    "receive_groz\0errorSerialPort\0"
    "QSerialPort::SerialPortError\0error\0"
    "logSlavePrint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusNetwork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    1,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   81,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x0a /* Public */,
      10,    1,   83,    2, 0x0a /* Public */,
      11,    0,   86,    2, 0x0a /* Public */,
      12,    0,   87,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x09 /* Protected */,
      16,    1,   91,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void ModbusNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModbusNetwork *_t = static_cast<ModbusNetwork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataToSlaves((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->logPrint((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->send_data_array((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->send_data_array_groz((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->openConnection(); break;
        case 5: _t->closeConnection(); break;
        case 6: _t->sendData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->receive(); break;
        case 8: _t->receive_groz(); break;
        case 9: _t->errorSerialPort((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 10: _t->logSlavePrint((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModbusNetwork::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusNetwork::sendDataToSlaves)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModbusNetwork::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusNetwork::logPrint)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ModbusNetwork::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusNetwork::send_data_array)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ModbusNetwork::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusNetwork::send_data_array_groz)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ModbusNetwork::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ModbusNetwork.data,
      qt_meta_data_ModbusNetwork,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ModbusNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusNetwork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ModbusNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ModbusNetwork::sendDataToSlaves(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ModbusNetwork::logPrint(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ModbusNetwork::send_data_array(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ModbusNetwork::send_data_array_groz(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
