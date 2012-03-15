/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created: Thu Mar 15 16:05:14 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../glwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GLWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x0a,
      44,   34,    9,    9, 0x0a,
      72,   62,    9,    9, 0x0a,
      99,   90,    9,    9, 0x0a,
     136,  129,    9,    9, 0x0a,
     165,  159,    9,    9, 0x0a,
     186,  159,    9,    9, 0x0a,
     207,  159,    9,    9, 0x0a,
     245,  228,    9,    9, 0x0a,
     282,  275,    9,    9, 0x0a,
     309,    9,    9,    9, 0x0a,
     326,    9,    9,    9, 0x0a,
     344,    9,    9,    9, 0x0a,
     362,    9,    9,    9, 0x0a,
     380,    9,    9,    9, 0x0a,
     394,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0zRotVal\0setZRot(double)\0"
    "yTransVal\0setYTrans(double)\0xTransVal\0"
    "setXTrans(double)\0angleVal\0"
    "setAngularAccelActual(double)\0rotVal\0"
    "setShoulderRot(double)\0angle\0"
    "setXRotation(double)\0setYRotation(double)\0"
    "setZRotation(double)\0magnitude,zTrans\0"
    "setTranslation(double,double)\0potRot\0"
    "setArduinoTranslation(int)\0rotation(double)\0"
    "Zrotation(double)\0Xrotation(double)\0"
    "Yrotation(double)\0updateScene()\0"
    "determineAngularAccel(double)\0"
};

const QMetaObject GLWidget::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_GLWidget,
      qt_meta_data_GLWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GLWidget))
        return static_cast<void*>(const_cast< GLWidget*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int GLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setZRot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: setYTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: setXTrans((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: setAngularAccelActual((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: setShoulderRot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: setXRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: setYRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: setZRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: setTranslation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: setArduinoTranslation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: rotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: Zrotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: Xrotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: Yrotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: updateScene(); break;
        case 15: determineAngularAccel((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
