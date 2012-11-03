/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Apr 14 15:26:00 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      54,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     121,   11,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     157,   11,   11,   11, 0x08,
     175,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,
     229,   11,   11,   11, 0x08,
     247,   11,   11,   11, 0x08,
     263,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clearBoard()\0showAbout()\0"
    "showProgrammer()\0showOptions()\0"
    "showStatistics()\0on_btn1_clicked()\0"
    "on_btn2_clicked()\0on_btn3_clicked()\0"
    "on_btn4_clicked()\0on_btn5_clicked()\0"
    "on_btn6_clicked()\0on_btn7_clicked()\0"
    "on_btn8_clicked()\0on_btn9_clicked()\0"
    "changeTurnToO()\0changeTurnToX()\0"
    "changeModeToP2P()\0changeModeToP2C()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->clearBoard(); break;
        case 1: _t->showAbout(); break;
        case 2: _t->showProgrammer(); break;
        case 3: _t->showOptions(); break;
        case 4: _t->showStatistics(); break;
        case 5: _t->on_btn1_clicked(); break;
        case 6: _t->on_btn2_clicked(); break;
        case 7: _t->on_btn3_clicked(); break;
        case 8: _t->on_btn4_clicked(); break;
        case 9: _t->on_btn5_clicked(); break;
        case 10: _t->on_btn6_clicked(); break;
        case 11: _t->on_btn7_clicked(); break;
        case 12: _t->on_btn8_clicked(); break;
        case 13: _t->on_btn9_clicked(); break;
        case 14: _t->changeTurnToO(); break;
        case 15: _t->changeTurnToX(); break;
        case 16: _t->changeModeToP2P(); break;
        case 17: _t->changeModeToP2C(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
