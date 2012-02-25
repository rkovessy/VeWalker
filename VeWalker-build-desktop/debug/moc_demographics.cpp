/****************************************************************************
** Meta object code from reading C++ file 'demographics.h'
**
** Created: Sat Feb 25 17:44:16 2012
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
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      33,   13,   13,   13, 0x08,
      53,   13,   13,   13, 0x08,
      72,   13,   13,   13, 0x08,
      94,   13,   13,   13, 0x08,
     117,   13,   13,   13, 0x08,
     135,   13,   13,   13, 0x08,
     155,   13,   13,   13, 0x08,
     178,   13,   13,   13, 0x08,
     200,   13,   13,   13, 0x08,
     224,   13,   13,   13, 0x08,
     251,   13,   13,   13, 0x08,
     279,   13,   13,   13, 0x08,
     303,   13,   13,   13, 0x08,
     327,   13,   13,   13, 0x08,
     345,   13,   13,   13, 0x08,
     364,   13,   13,   13, 0x08,
     389,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Demographics[] = {
    "Demographics\0\0on_start_clicked()\0"
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
        case 0: on_start_clicked(); break;
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
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
