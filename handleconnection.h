//#ifndef HANDLECONNECTION_H
//#define HANDLECONNECTION_H

//#include <QObject>
//#include <QTimer>
//#include <QDebug>
//#include <QMessageBox>

//class HandleConnection : public QObject {
//    Q_OBJECT

//public:
//    explicit HandleConnection(QObject *parent = nullptr) : QObject(parent), contactEstablished(true) {
//        // Setup timers and signals for handling contact loss
//        countDownTimer = new QTimer(this);
//        //contactLossTimer->setInterval(300000); // 5 minutes
//        connect(countDownTimer, &QTimer::timeout, this, &HandleConnection::handleExtendedContactLoss);

//    }

//    void contactLost() {
//        if (countDownTimer->isActive()) {
//            countDownTimer->stop();
//         }

//        qDebug() << "Contact lost: flashing red light and starting beeping.";
//        emit updateLED("red", true);  // Simulate red light flashing
//        startBeeping();  // Start device beeping
//        contactEstablished = false;
//        countDownTimer->start(1000*60*5); // 5min



//    }

//    void contactRegained() {
//        if (countDownTimer->isActive()) {
//            qDebug() << "Contact regained: stopping red light and beeping.";
//            emit updateLED("red", false);  // Stop red light flashing
//            stopBeeping();  // Stop device beeping
//            contactEstablished = true;
//            countDownTimer->stop();  // Stop the timer
//         }
//    }

//signals:
//    void updateLED(const QString &color, bool active);

//private:
//    QTimer *countDownTimer;
//    bool contactEstablished;

//    void startBeeping() {
//        qDebug() << "Beeping started.";
//        // Code to start beeping
//    }

//    void stopBeeping() {
//        qDebug() << "Beeping stopped.";
//        // Code to stop beeping
//    }

//    void handleExtendedContactLoss() {
//        qDebug() << "No contact for 5 minutes: turning off device and erasing session.";
//        stopBeeping();
//        // Code to turn off the device and erase the session
//    }
//};

// HandleConnection.h
#ifndef HANDLECONNECTION_H
#define HANDLECONNECTION_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class HandleConnection : public QObject {
    Q_OBJECT

public:
    explicit HandleConnection(QObject *parent = nullptr);
    void contactLost();
    void contactRegained();

signals:
    void updateLED(const QString &color, bool active);

private:
    QTimer *countDownTimer;
    bool contactEstablished;

    void startBeeping();
    void stopBeeping();
    void handleExtendedContactLoss();
};

#endif // HANDLECONNECTION_H
