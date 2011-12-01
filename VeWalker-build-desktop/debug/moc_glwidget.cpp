/****************************************************************************
** Meta object code from reading C++ file 'glwidget.h'
**
** Created: Wed Nov 30 23:09:11 2011
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x0a,
      37,   10,    9,    9, 0x0a,
      58,   10,    9,    9, 0x0a,
      96,   79,    9,    9, 0x0a,
     126,    9,    9,    9, 0x0a,
     143,    9,    9,    9, 0x0a,
     161,    9,    9,    9, 0x0a,
     179,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GLWidget[] = {
    "GLWidget\0\0angle\0setXRotation(double)\0"
    "setYRotation(double)\0setZRotation(double)\0"
    "magnitude,zTrans\0setTranslation(double,double)\0"
    "rotation(double)\0Zrotation(double)\0"
    "Xrotation(double)\0updateScene()\0"
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
        case 0: setXRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: setYRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: setZRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: setTranslation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: rotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: Zrotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: Xrotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: updateScene(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
