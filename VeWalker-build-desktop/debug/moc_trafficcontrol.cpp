/****************************************************************************
** Meta object code from reading C++ file 'trafficcontrol.h'
**
** Created: Thu Mar 8 16:17:51 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../trafficcontrol.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trafficcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TrafficControl[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TrafficControl[] = {
    "TrafficControl\0\0close_window()\0clicked()\0"
};

const QMetaObject TrafficControl::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TrafficControl,
      qt_meta_data_TrafficControl, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TrafficControl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TrafficControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TrafficControl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrafficControl))
        return static_cast<void*>(const_cast< TrafficControl*>(this));
    return QWidget::qt_metacast(_clname);
}

int TrafficControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: close_window(); break;
        case 1: clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TrafficControl::close_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
