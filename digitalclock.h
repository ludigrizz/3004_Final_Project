#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H
#include <QLCDNumber>
#include <QTimer>
#include <QTime>



class DigitalClock : public QLCDNumber
{
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);

private:
    QLCDNumber *sessTimer;

private slots:
    QTime showTime();
};

#endif // DIGITALCLOCK_H
