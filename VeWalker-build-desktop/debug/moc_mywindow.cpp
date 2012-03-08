/****************************************************************************
** Meta object code from reading C++ file 'mywindow.h'
**
** Created: Thu Mar 8 14:30:08 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mywindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      35,   10,    9,    9, 0x0a,
      79,   67,    9,    9, 0x0a,
     136,  115,    9,    9, 0x0a,
     185,  173,    9,    9, 0x0a,
     213,  209,    9,    9, 0x0a,
     222,    9,    9,    9, 0x0a,
     235,    9,    9,    9, 0x0a,
     257,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWindow[] = {
    "MyWindow\0\0magnitude,stepped,zTrans\0"
    "updateMotor(double,bool,double)\0"
    "x1,x2,y1,y2\0updateCameraValues(int,int,int,int)\0"
    "HTyaw,HTpitch,HTroll\0"
    "updateHTrackerValues(long,long,long)\0"
    "potRotation\0updatePotRotation(long)\0"
    "pid\0set(int)\0set_replay()\0"
    "updateCompass(double)\0updateScene()\0"
};

const QMetaObject MyWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWindow,
      qt_meta_data_MyWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWindow))
        return static_cast<void*>(const_cast< MyWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateMotor((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 1: updateCameraValues((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: updateHTrackerValues((*reinterpret_cast< long(*)>(_a[1])),(*reinterpret_cast< long(*)>(_a[2])),(*reinterpret_cast< long(*)>(_a[3]))); break;
        case 3: updatePotRotation((*reinterpret_cast< long(*)>(_a[1]))); break;
        case 4: set((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: set_replay(); break;
        case 6: updateCompass((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: updateScene(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
