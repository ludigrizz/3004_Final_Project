#include "digitalclock.h"
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

DigitalClock::DigitalClock(QWidget *parent)
    : QLCDNumber(parent)
{
    setSegmentStyle(Filled);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::showTime);
    timer->start(1000);
    showTime();
//    setWindowTitle("DigitalCLock");
    resize(150,60);


}

QTime DigitalClock::showTime() {
    QTime timefrom = QTime(01,00);
    QString text = timefrom.toString("hh:mm:ss");
    if ((timefrom.second()%2) == 0) {
        text[2] =' ';
    return timefrom;
    }
    return timefrom;
}
