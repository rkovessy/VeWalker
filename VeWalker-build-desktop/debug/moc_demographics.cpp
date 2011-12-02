/****************************************************************************
** Meta object code from reading C++ file 'demographics.h'
**
** Created: Thu Dec 1 19:39:20 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../demographics.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demographics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Demographics[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      32,   13,   13,   13, 0x08,
      50,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Demographics[] = {
    "Demographics\0\0on_quit_clicked()\0"
    "on_male_clicked()\0on_female_clicked()\0"
};

const QMetaObject Demographics::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Demographics,
      qt_meta_data_Demographics, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Demographics::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Demographics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Demographics::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Demographics))
        return static_cast<void*>(const_cast< Demographics*>(this));
    return QDialog::qt_metacast(_clname);
}

int Demographics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_quit_clicked(); break;
        case 1: on_male_clicked(); break;
        case 2: on_female_clicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
