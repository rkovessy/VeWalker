/****************************************************************************
** Meta object code from reading C++ file 'starttrials.h'
**
** Created: Tue Jul 26 16:12:00 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../starttrials.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'starttrials.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StartTrials[] = {

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
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      23,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StartTrials[] = {
    "StartTrials\0\0clicked()\0on_resume_clicked()\0"
};

const QMetaObject StartTrials::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StartTrials,
      qt_meta_data_StartTrials, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StartTrials::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StartTrials::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StartTrials::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StartTrials))
        return static_cast<void*>(const_cast< StartTrials*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StartTrials::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: on_resume_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void StartTrials::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
