/****************************************************************************
** Meta object code from reading C++ file 'arduino.h'
**
<<<<<<< HEAD
** Created: Wed Mar 14 00:39:31 2012
=======
** Created: Wed Mar 14 00:42:26 2012
>>>>>>> origin/fresh_branch
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../arduino.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arduino.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ArduinoThread[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   49,   14,   14, 0x0a,
      78,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ArduinoThread[] = {
    "ArduinoThread\0\0potRotation\0"
    "sendPotRotation(long)\0height,timer\0"
    "set(double,int)\0UpdateArduino()\0"
};

const QMetaObject ArduinoThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ArduinoThread,
      qt_meta_data_ArduinoThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ArduinoThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ArduinoThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ArduinoThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ArduinoThread))
        return static_cast<void*>(const_cast< ArduinoThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ArduinoThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendPotRotation((*reinterpret_cast< long(*)>(_a[1]))); break;
        case 1: set((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: UpdateArduino(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ArduinoThread::sendPotRotation(long _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
