/****************************************************************************
** Meta object code from reading C++ file 'failscreen.h'
**
** Created: Tue Jul 19 15:49:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../failscreen.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'failscreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FailScreen[] = {

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
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      22,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FailScreen[] = {
    "FailScreen\0\0clicked()\0on_resume_clicked()\0"
};

const QMetaObject FailScreen::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_FailScreen,
      qt_meta_data_FailScreen, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FailScreen::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FailScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FailScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FailScreen))
        return static_cast<void*>(const_cast< FailScreen*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int FailScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FailScreen::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
