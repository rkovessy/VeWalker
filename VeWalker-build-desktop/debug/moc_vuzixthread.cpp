/****************************************************************************
** Meta object code from reading C++ file 'vuzixthread.h'
**
** Created: Wed Mar 14 00:39:29 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../vuzixthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vuzixthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VuzixThread[] = {

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
      34,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      82,   69,   12,   12, 0x0a,
      98,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VuzixThread[] = {
    "VuzixThread\0\0HTyaw,HTpitch,HTroll\0"
    "sendHTrackerValues(long,long,long)\0"
    "height,timer\0set(double,int)\0"
    "UpdateHTracking()\0"
};

const QMetaObject VuzixThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VuzixThread,
      qt_meta_data_VuzixThread, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VuzixThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VuzixThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VuzixThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VuzixThread))
        return static_cast<void*>(const_cast< VuzixThread*>(this));
    return QThread::qt_metacast(_clname);
}

int VuzixThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendHTrackerValues((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])),(*reinterpret_cast< long(*)>(_a[3]))); break;
        case 1: set((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: UpdateHTracking(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void VuzixThread::sendHTrackerValues(long _t1, long _t2, long _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
