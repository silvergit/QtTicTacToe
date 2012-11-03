/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      43,   41,   11,   11, 0x08,
      60,   41,   11,   11, 0x08,
      77,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,
     149,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     221,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     275,   11,   11,   11, 0x08,
     293,   11,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     326,   11,   11,   11, 0x08,
     342,   11,   11,   11, 0x08,
     357,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     386,   11,   11,   11, 0x08,
     399,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0check4UpdateVersion(QString)\0"
    "s\0getTurn(QString)\0getMode(QString)\0"
    "on_btn1_clicked()\0on_btn2_clicked()\0"
    "on_btn3_clicked()\0on_btn4_clicked()\0"
    "on_btn5_clicked()\0on_btn6_clicked()\0"
    "on_btn7_clicked()\0on_btn8_clicked()\0"
    "on_btn9_clicked()\0clearStatistics()\0"
    "changeModeToP2P()\0changeModeToP2C()\0"
    "showStatistics()\0changeTurnToO()\0"
    "changeTurnToX()\0check4Update()\0"
    "updateScores()\0showOptions()\0clearBoard()\0"
    "showAbout()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->check4UpdateVersion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->getTurn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->getMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_btn1_clicked(); break;
        case 4: _t->on_btn2_clicked(); break;
        case 5: _t->on_btn3_clicked(); break;
        case 6: _t->on_btn4_clicked(); break;
        case 7: _t->on_btn5_clicked(); break;
        case 8: _t->on_btn6_clicked(); break;
        case 9: _t->on_btn7_clicked(); break;
        case 10: _t->on_btn8_clicked(); break;
        case 11: _t->on_btn9_clicked(); break;
        case 12: _t->clearStatistics(); break;
        case 13: _t->changeModeToP2P(); break;
        case 14: _t->changeModeToP2C(); break;
        case 15: _t->showStatistics(); break;
        case 16: _t->changeTurnToO(); break;
        case 17: _t->changeTurnToX(); break;
        case 18: _t->check4Update(); break;
        case 19: _t->updateScores(); break;
        case 20: _t->showOptions(); break;
        case 21: _t->clearBoard(); break;
        case 22: _t->showAbout(); break;
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
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
