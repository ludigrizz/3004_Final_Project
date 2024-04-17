//#include "batteryprogressbar.h"
//#include <QPainter>
//#include <QWidget>

//batteryProgressBar::batteryProgressBar(QWidget *parent) : QProgressBar(parent)
//{
//    batteryLevel = 100;
//    setRange(0,100);
//    setValue(batteryLevel);
//}

//void batteryProgressBar::drainBattery(int amount) {
//    batteryLevel -=amount;
//    if (batteryLevel <= 0) {
//        batteryLevel = 0;
//    }
//    setValue(batteryLevel);
//    emit batteryLevelChanged(batteryLevel);
//}

//void batteryProgressBar::rechargeBattery(int amount) {
//    batteryLevel +=amount;
//    if (batteryLevel >= 100) {
//        batteryLevel = 100;
//    }
//    setValue(batteryLevel);
//    emit batteryLevelChanged(batteryLevel);
//}

//void batteryProgressBar::paintEvent(QPaintEvent *e) {
//    Q_UNUSED(e);

//    QPainter painter(this);
//    QRectF rect = QRectF(0,0,width(),height());
//    QColor colour;

//    if (batteryLevel <= 25) {
//        colour = QColor(Qt::red);
//    } else if (batteryLevel >25 && batteryLevel <= 75) {
//        colour = QColor(Qt::yellow);
//    } else if (batteryLevel >75) {
//        colour = QColor(Qt::green);
//    }

//    painter.fillRect(rect,Qt::white);
//    painter.fillRect(rect.adjusted(2,2,-2,-2),colour);

//    QString text = QString("%1").arg(batteryLevel);
//    painter.drawText(rect, Qt::AlignCenter, text);
//}
