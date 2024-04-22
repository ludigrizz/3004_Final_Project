#include "mainwindow.h"
//#include "digitalclock.h"
#include "pcwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    pcwindow pc;
    pc.show();


//    DigitalClock clock;
//    clock.show();
    return a.exec();
}
