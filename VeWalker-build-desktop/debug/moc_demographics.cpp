/****************************************************************************
** Meta object code from reading C++ file 'demographics.h'
**
** Created: Thu Mar 15 18:09:45 2012
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
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      32,   13,   13,   13, 0x08,
      52,   13,   13,   13, 0x08,
      71,   13,   13,   13, 0x08,
      93,   13,   13,   13, 0x08,
     116,   13,   13,   13, 0x08,
     134,   13,   13,   13, 0x08,
     154,   13,   13,   13, 0x08,
     177,   13,   13,   13, 0x08,
     199,   13,   13,   13, 0x08,
     223,   13,   13,   13, 0x08,
     250,   13,   13,   13, 0x08,
     278,   13,   13,   13, 0x08,
     302,   13,   13,   13, 0x08,
     326,   13,   13,   13, 0x08,
     344,   13,   13,   13, 0x08,
     363,   13,   13,   13, 0x08,
     388,   13,   13,   13, 0x08,
     412,   13,   13,   13, 0x08,
     438,   13,   13,   13, 0x08,
     465,   13,   13,   13, 0x08,
     494,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Demographics[] = {
    "Demographics\0\0on_quit_clicked()\0"
    "on_cancel_clicked()\0on_datum_clicked()\0"
    "on_download_clicked()\0on_calibrate_clicked()\0"
    "on_male_clicked()\0on_female_clicked()\0"
    "on_neongreen_clicked()\0on_neonpink_clicked()\0"
    "on_neonorange_clicked()\0"
    "on_trafficenable_clicked()\0"
    "on_trafficdisable_clicked()\0"
    "on_singlelane_clicked()\0on_doublelane_clicked()\0"
    "on_demo_clicked()\0on_trial_clicked()\0"
    "on_righthanded_clicked()\0"
    "on_lefthanded_clicked()\0"
    "on_unsafeenable_clicked()\0"
    "on_unsafedisable_clicked()\0"
    "on_shoulderControl_clicked()\0"
    "on_headControl_clicked()\0"
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
        case 1: on_cancel_clicked(); break;
        case 2: on_datum_clicked(); break;
        case 3: on_download_clicked(); break;
        case 4: on_calibrate_clicked(); break;
        case 5: on_male_clicked(); break;
        case 6: on_female_clicked(); break;
        case 7: on_neongreen_clicked(); break;
        case 8: on_neonpink_clicked(); break;
        case 9: on_neonorange_clicked(); break;
        case 10: on_trafficenable_clicked(); break;
        case 11: on_trafficdisable_clicked(); break;
        case 12: on_singlelane_clicked(); break;
        case 13: on_doublelane_clicked(); break;
        case 14: on_demo_clicked(); break;
        case 15: on_trial_clicked(); break;
        case 16: on_righthanded_clicked(); break;
        case 17: on_lefthanded_clicked(); break;
        case 18: on_unsafeenable_clicked(); break;
        case 19: on_unsafedisable_clicked(); break;
        case 20: on_shoulderControl_clicked(); break;
        case 21: on_headControl_clicked(); break;
        default: ;
        }
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
