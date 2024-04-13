#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "datetimedialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pauseBtn, SIGNAL(released()), this, SLOT(pauseSession()));
    connect(ui->startBtn, SIGNAL(released()), this, SLOT(resumeSession()));
    connect(ui->newSessionBtn, SIGNAL(released()), this, SLOT(startNewSession()));
    connect(ui->sessionLogBtn, SIGNAL(released()), this, SLOT(getSessionLogs()));

//    connect(ui->dateAndTimeBtn, &QPushButton::clicked, this, &MainWindow::openDateTimeDialog);
    connect(ui->dateAndTimeBtn, SIGNAL(released()), this, SLOT(openDateTimeDialog()));

    connect(ui->stopBtn, SIGNAL(released()), this, SLOT(stopSession()));
    connect(ui->powerBtn, SIGNAL(released()), this, SLOT(togglePower()));

    isPowerOn = false;
    ui->powerBtn->setText("Turn On");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startNewSession() {
    qInfo("user pressed new session");
}

void MainWindow::resumeSession() {
    qInfo("user pressed resume/start session");
}

void MainWindow::pauseSession() {
    qInfo("user pressed pause session");
}

void MainWindow::getSessionLogs() {
    qInfo("user pressed session logs");
}

void MainWindow::openDateTimeDialog() {
    qInfo("user pressed date and time to set date and time");
//    DateTimeDialog dialog(this);
//    connect(&dialog, &DateTimeDialog::dateTimeSelected, this, &MainWindow::updateDateTime);
//    dialog.exec();

}

//void MainWindow::updateDateTime(const QDateTime &dateTime) {
//    qDebug() << "New date and time selected: " << dateTime.toString();
//}

void MainWindow::stopSession() {
    qInfo("user pressed stop session");
}

void MainWindow::togglePower() {
    qInfo("user pressed power button");

     //

    //this->toggleBlueLight();
    //this->toggleGreenLight();
    //this->toggleRedlight();
}

void MainWindow::toggleBlueLight() {
//    if (getPowerState() == ON) {
//        ui->blueLight->setStyleSheet("background-color: blue;");
//    } else {
//        ui->blueLight->setStyleSheet("background-color: darkGray;");
//    }
}

void MainWindow::toggleGreenLight() {
    //    if (getPowerState() == ON && treatment is applied) {
    //        ui->blueLight->setStyleSheet("background-color: green;");
    //    } else {
    //        ui->blueLight->setStyleSheet("background-color: darkGray;");
    //    }
}

void MainWindow::toggleRedLight() {
    //    if (getPowerState() == ON && getConnectionState() == DISCONNECTED) {
    //        ui->blueLight->setStyleSheet("background-color: red;");
    //    } else {
    //        ui->blueLight->setStyleSheet("background-color: darkGray;");
    //    }
}


