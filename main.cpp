#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    int aa,b,c;
    double d;

    b=10;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
