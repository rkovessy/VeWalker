/****************************************************************************
** Meta object code from reading C++ file 'collectdata.h'
**
** Created: Wed Nov 30 23:09:14 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../collectdata.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'collectdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CollectData[] = {

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
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      27,   12,   12,   12, 0x0a,
      36,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CollectData[] = {
    "CollectData\0\0updateScene()\0update()\0"
    "set(double)\0"
};

const QMetaObject CollectData::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CollectData,
      qt_meta_data_CollectData, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CollectData::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CollectData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CollectData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CollectData))
        return static_cast<void*>(const_cast< CollectData*>(this));
    return QWidget::qt_metacast(_clname);
}

int CollectData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateScene(); break;
        case 1: update(); break;
        case 2: set((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void CollectData::updateScene()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
