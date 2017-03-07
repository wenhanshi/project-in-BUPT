/****************************************************************************
** Meta object code from reading C++ file 'firstinput.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MUTI_TS_V2.1.5.27/MUTI_TS_V2.1.5.27/TravelSystem_V2.1.5.27_MUTI/firstinput.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'firstinput.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_firstInput_t {
    QByteArrayData data[7];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_firstInput_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_firstInput_t qt_meta_stringdata_firstInput = {
    {
QT_MOC_LITERAL(0, 0, 10), // "firstInput"
QT_MOC_LITERAL(1, 11, 8), // "sendCity"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "sendTime"
QT_MOC_LITERAL(4, 30, 16), // "sendCloseMessage"
QT_MOC_LITERAL(5, 47, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(6, 69, 21) // "on_buttonBox_rejected"

    },
    "firstInput\0sendCity\0\0sendTime\0"
    "sendCloseMessage\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_firstInput[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    1,   42,    2, 0x06 /* Public */,
       4,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void firstInput::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        firstInput *_t = static_cast<firstInput *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCity((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sendCloseMessage((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_buttonBox_accepted(); break;
        case 4: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (firstInput::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&firstInput::sendCity)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (firstInput::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&firstInput::sendTime)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (firstInput::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&firstInput::sendCloseMessage)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject firstInput::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_firstInput.data,
      qt_meta_data_firstInput,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *firstInput::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *firstInput::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_firstInput.stringdata0))
        return static_cast<void*>(const_cast< firstInput*>(this));
    return QDialog::qt_metacast(_clname);
}

int firstInput::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void firstInput::sendCity(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void firstInput::sendTime(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void firstInput::sendCloseMessage(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
