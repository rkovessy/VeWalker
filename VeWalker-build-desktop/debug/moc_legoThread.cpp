/****************************************************************************
** Meta object code from reading C++ file 'legoThread.h'
**
** Created: Wed Nov 30 11:05:22 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../legoThread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'legoThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LegoThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      37,   12,   11,   11, 0x05,
      73,   67,   11,   11, 0x05,
     117,   93,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     164,  151,   11,   11, 0x0a,
     180,   11,   11,   11, 0x0a,
     197,   11,   11,   11, 0x0a,
     210,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LegoThread[] = {
    "LegoThread\0\0magnitude,stepped,zTrans\0"
    "sendMotor(double,bool,double)\0angle\0"
    "sendCompass(double)\0posX1,posX2,posY1,posY2\0"
    "sendCameraValues(int,int,int,int)\0"
    "height,timer\0set(double,int)\0"
    "UpdateRotation()\0UpdateRoll()\0"
    "UpdateCamera()\0"
};

const QMetaObject LegoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_LegoThread,
      qt_meta_data_LegoThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LegoThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LegoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LegoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LegoThread))
        return static_cast<void*>(const_cast< LegoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int LegoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendMotor((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: sendCompass((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: sendCameraValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: set((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: UpdateRotation(); break;
        case 5: UpdateRoll(); break;
        case 6: UpdateCamera(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LegoThread::sendMotor(double _t1, bool _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LegoThread::sendCompass(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LegoThread::sendCameraValues(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
