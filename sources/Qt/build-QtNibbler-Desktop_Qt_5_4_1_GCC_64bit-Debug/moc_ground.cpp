/****************************************************************************
** Meta object code from reading C++ file 'ground.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtNibbler/ground.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ground.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_snakeField_t {
    QByteArrayData data[7];
    char stringdata[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_snakeField_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_snakeField_t qt_meta_stringdata_snakeField = {
    {
QT_MOC_LITERAL(0, 0, 10), // "snakeField"
QT_MOC_LITERAL(1, 11, 11), // "snakeLength"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "length"
QT_MOC_LITERAL(4, 31, 10), // "snakeRound"
QT_MOC_LITERAL(5, 42, 5), // "round"
QT_MOC_LITERAL(6, 48, 4) // "quit"

    },
    "snakeField\0snakeLength\0\0length\0"
    "snakeRound\0round\0quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_snakeField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // enums: name, flags, count, data

 // enum data: key, value

       0        // eod
};

void snakeField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        snakeField *_t = static_cast<snakeField *>(_o);
        switch (_id) {
        case 0: _t->snakeLength((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->snakeRound((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (snakeField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&snakeField::snakeLength)) {
                *result = 0;
            }
        }
        {
            typedef void (snakeField::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&snakeField::snakeRound)) {
                *result = 1;
            }
        }
        {
            typedef void (snakeField::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&snakeField::quit)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject snakeField::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_snakeField.data,
      qt_meta_data_snakeField,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *snakeField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *snakeField::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_snakeField.stringdata))
        return static_cast<void*>(const_cast< snakeField*>(this));
    return QWidget::qt_metacast(_clname);
}

int snakeField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void snakeField::snakeLength(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void snakeField::snakeRound(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void snakeField::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE