/****************************************************************************
** Meta object code from reading C++ file 'serialportengine_p_win.h'
**
** Created: Tue Mar 13 22:57:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "C:/qserialport/qserialdevice-qserialdevice/src/serialportengine_p_win.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportengine_p_win.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WinSerialPortEngine[] = {

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

static const char qt_meta_stringdata_WinSerialPortEngine[] = {
    "WinSerialPortEngine\0"
};

const QMetaObject WinSerialPortEngine::staticMetaObject = {
    { &QWinEventNotifier::staticMetaObject, qt_meta_stringdata_WinSerialPortEngine,
      qt_meta_data_WinSerialPortEngine, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WinSerialPortEngine::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WinSerialPortEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WinSerialPortEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WinSerialPortEngine))
        return static_cast<void*>(const_cast< WinSerialPortEngine*>(this));
    if (!strcmp(_clname, "SerialPortEngine"))
        return static_cast< SerialPortEngine*>(const_cast< WinSerialPortEngine*>(this));
    return QWinEventNotifier::qt_metacast(_clname);
}

int WinSerialPortEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWinEventNotifier::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
