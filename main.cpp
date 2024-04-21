#include "mainwindow.h"
//#include "digitalclock.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    DigitalClock clock;
//    clock.show();
    return a.exec();
}
