/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 9 16:59:41 2012
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      25,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     140,   11,   11,   11, 0x08,
     158,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     194,   11,   11,   11, 0x08,
     212,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     262,   11,   11,   11, 0x08,
     280,   11,   11,   11, 0x08,
     300,  298,   11,   11, 0x08,
     317,  298,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0clearBoard()\0showAbout()\0"
    "showOptions()\0showStatistics()\0"
    "on_btn1_clicked()\0on_btn2_clicked()\0"
    "on_btn3_clicked()\0on_btn4_clicked()\0"
    "on_btn5_clicked()\0on_btn6_clicked()\0"
    "on_btn7_clicked()\0on_btn8_clicked()\0"
    "on_btn9_clicked()\0changeTurnToO()\0"
    "changeTurnToX()\0changeModeToP2P()\0"
    "changeModeToP2C()\0s\0getTurn(QString)\0"
    "getMode(QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->clearBoard(); break;
        case 1: _t->showAbout(); break;
        case 2: _t->showOptions(); break;
        case 3: _t->showStatistics(); break;
        case 4: _t->on_btn1_clicked(); break;
        case 5: _t->on_btn2_clicked(); break;
        case 6: _t->on_btn3_clicked(); break;
        case 7: _t->on_btn4_clicked(); break;
        case 8: _t->on_btn5_clicked(); break;
        case 9: _t->on_btn6_clicked(); break;
        case 10: _t->on_btn7_clicked(); break;
        case 11: _t->on_btn8_clicked(); break;
        case 12: _t->on_btn9_clicked(); break;
        case 13: _t->changeTurnToO(); break;
        case 14: _t->changeTurnToX(); break;
        case 15: _t->changeModeToP2P(); break;
        case 16: _t->changeModeToP2C(); break;
        case 17: _t->getTurn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->getMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
