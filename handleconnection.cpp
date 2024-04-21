#include "handleconnection.h"
#include <QMessageBox>

HandleConnection::HandleConnection(QObject *parent)
    : QObject(parent), contactEstablished(true) {
    countDownTimer = new QTimer(this);
    connect(countDownTimer, &QTimer::timeout, this, &HandleConnection::handleExtendedContactLoss);
}

void HandleConnection::contactLost() {
    if (countDownTimer->isActive()) {
        countDownTimer->stop();
    }

    qDebug() << "Contact lost: flashing red light and starting beeping.";
    emit updateLED("red", true);
    startBeeping();
    contactEstablished = false;
    countDownTimer->start(1000*60*5); // 5 minutes
}

void HandleConnection::contactRegained() {
    if (countDownTimer->isActive()) {
        qDebug() << "Contact regained: stopping red light and beeping.";
        emit updateLED("red", false);
        stopBeeping();
        contactEstablished = true;
        countDownTimer->stop();
    }
}

void HandleConnection::startBeeping() {
    qDebug() << "Beeping started.";
    // Add actual code to start beeping here
}

void HandleConnection::stopBeeping() {
    qDebug() << "Beeping stopped.";
    // Add actual code to stop beeping here
}

void HandleConnection::handleExtendedContactLoss() {
    qDebug() << "No contact for 5 minutes: turning off device and erasing session.";
    stopBeeping();
    // Add actual code to turn off the device and erase the session here
}
