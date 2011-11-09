/****************************************************************************
** Meta object code from reading C++ file 'countdown.h'
**
** Created: Tue Jul 26 21:11:02 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../countdown.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'countdown.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Countdown[] = {

 // content:
       5,       // revision
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

static const char qt_meta_stringdata_Countdown[] = {
    "Countdown\0"
};

const QMetaObject Countdown::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Countdown,
      qt_meta_data_Countdown, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Countdown::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Countdown::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Countdown::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Countdown))
        return static_cast<void*>(const_cast< Countdown*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Countdown::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
