#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "datetimedialog.h"
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include "deviceprofile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    devProfile = new deviceProfile(1,100.00);
    powerLevel = devProfile->getBatteryLevel();
    isPowerOn = false;
    togglePower();

    //initialize the default battery
    ui->battery->setStyleSheet("QProgressBar::chunk {background-color: #00ff00; width: 10px; margin: 0.5px;}");
    ui->battery->setOrientation(Qt::Horizontal);
    ui->battery->setRange(0,100);
    ui->battery->setValue(99);
// THESE COMMENTS ARE FOR REFIXING THE SLOTS AFTER SWITCHING TO STACKED WIDGETS - SOFIA
//    connect(ui->pauseBtn, SIGNAL(released()), this, SLOT(pauseSession()));
//    connect(ui->startBtn, SIGNAL(released()), this, SLOT(resumeSession()));
//    connect(ui->newSessionBtn, SIGNAL(released()), this, SLOT(startNewSession()));
//    connect(ui->sessionLogBtn, SIGNAL(released()), this, SLOT(getSessionLogs()));

////    connect(ui->dateAndTimeBtn, &QPushButton::clicked, this, &MainWindow::openDateTimeDialog);
//    connect(ui->dateAndTimeBtn, SIGNAL(released()), this, SLOT(openDateTimeDialog()));

//    connect(ui->stopBtn, SIGNAL(released()), this, SLOT(stopSession()));
//    isPowerOn = false;
//    ui->powerBtn->setText("Turn On");

//    QLabel *redLED = new QLabel(ui->redLEDos);
//    redLED->setFixedSize(24,24);
//    redLED->setStyleSheet("border-radius: 12px; background-color: red;");

//    QTimer *timer = new QTimer(ui->redLEDos);
//    connect(timer, &QTimer::timeout, this, &MainWindow::toggleLED);
//    timer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::treatment() {
    qInfo("Some treatment is happening");
    // testing needs that after 2-3 treatments the battery is empty so we remove 1/3 of the battery each time this loops
    // ... treatment logic
    drainBattery();
}

void MainWindow::batteryDangerNotice() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Caution: Low Battery","Low Battery! Your device will die soon, do you want to save, exit and charge your device?",
                                  QMessageBox::YesToAll | QMessageBox::NoToAll| QMessageBox::Ignore);
    if (reply == QMessageBox::YesToAll) {
        qDebug() << "Yes was clicked";
    }
    if (reply == QMessageBox::NoToAll) {
        qDebug() << "No was clicked";
    }
    if (reply == QMessageBox::Ignore) {
        qDebug() << "Ignore was clicked";
    }
}

void MainWindow::chargeBattery() {
    int newBatteryLevel = 100;
    qInfo("battery charged");
    updateBattery(newBatteryLevel);
}

void MainWindow::updateBattery(int newBatteryLevel) {
    QString low = "QProgressBar::chunk {background-color: #ff0000; width: 10px; margin: 0.5px;}";
    QString high = "QProgressBar::chunk {background-color: #00ff00; width: 10px; margin: 0.5px;}";
    QString medium = "QProgressBar::chunk {background-color: #ffff00; width: 10px; margin: 0.5px;}";

    if (newBatteryLevel <= 0) {
        ui->battery->setValue(0);
        powerLevel = 0;
        togglePower();
        ui->battery->setStyleSheet(low);
    } else if (newBatteryLevel > 0 && newBatteryLevel <=30) {
        ui->battery->setValue(newBatteryLevel);
        powerLevel = newBatteryLevel;
        ui->battery->setStyleSheet(low);
        batteryDangerNotice();
    } else if (newBatteryLevel > 30 && newBatteryLevel <=60) {
        ui->battery->setValue(newBatteryLevel);
        ui->battery->setStyleSheet(medium);
        powerLevel = newBatteryLevel;
    } else if (newBatteryLevel > 60 && newBatteryLevel <=100) {
        ui->battery->setValue(newBatteryLevel);
        ui->battery->setStyleSheet(high);
        powerLevel = newBatteryLevel;
    }else if (newBatteryLevel > 100) {
        ui->battery->setValue(100);
        powerLevel = 100;
        ui->battery->setStyleSheet(high);
    }
}

void MainWindow::drainBattery() {
    QString low = "QProgressBar::chunk {background-color: #ff0000; width: 10px; margin: 0.5px;}";
    QString high = "QProgressBar::chunk {background-color: #00ff00; width: 10px; margin: 0.5px;}";
    QString medium = "QProgressBar::chunk {background-color: #ffff00; width: 10px; margin: 0.5px;}";
    int currentBatteryLevel = ui->battery->value();
    int newBatteryLevel = currentBatteryLevel - 30;
    if (newBatteryLevel <= 0) {
        ui->battery->setValue(0);
        powerLevel = 0;
        isPowerOn = false;
        togglePower();
        ui->battery->setStyleSheet(low);
    } else if (newBatteryLevel > 0 && newBatteryLevel <=30) {
        ui->battery->setValue(newBatteryLevel);
        powerLevel = newBatteryLevel;
        ui->battery->setStyleSheet(low);
        batteryDangerNotice();
    } else if (newBatteryLevel > 30 && newBatteryLevel <=60) {
        ui->battery->setValue(newBatteryLevel);
        ui->battery->setStyleSheet(medium);
        powerLevel = newBatteryLevel;
    } else if (newBatteryLevel > 60 && newBatteryLevel <=100) {
        ui->battery->setValue(newBatteryLevel);
        ui->battery->setStyleSheet(high);
        powerLevel = newBatteryLevel;
    }else if (newBatteryLevel > 100) {
        ui->battery->setValue(100);
        powerLevel = 100;
        ui->battery->setStyleSheet(high);
    }
}

void MainWindow::toggleLED(QLabel* redLED) {
    static bool isOn = false;
    if (isOn) {
        turnOnLED(redLED);
    } else {
        turnOffLED(redLED);
    }
    isOn = !isOn;
}

void MainWindow::turnOnLED(QLabel *redLED) {
    redLED->setStyleSheet("border-radius: 12px; background-color: red;");
}

void MainWindow::turnOffLED(QLabel *redLED) {
    redLED->setStyleSheet("border-radius: 12px; background-color: grey;");
}

void MainWindow::resumeSession() {
    qInfo("user pressed resume/start session");
}

void MainWindow::pauseSession() {
    qInfo("user pressed pause session");
}

//void MainWindow::openDateTimeDialog() {
//    qInfo("user pressed date and time to set date and time");
////    DateTimeDialog dialog(this);
////    connect(&dialog, &DateTimeDialog::dateTimeSelected, this, &MainWindow::updateDateTime);
////    dialog.exec();

//}

//void MainWindow::updateDateTime(const QDateTime &dateTime) {
//    qDebug() << "New date and time selected: " << dateTime.toString();
//}
void MainWindow::stopSession() {
    qInfo("user pressed stop session");
}

void MainWindow::togglePower() {
    ui->stackedWidget->setVisible(isPowerOn);
}


void MainWindow::on_dateAndTimeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1); // go to date/time page view
}

void MainWindow::on_sessionLogBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2); // go to session log view
}

void MainWindow::on_newSessionBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); // go to new session view
}


void MainWindow::on_backBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // return home
}



void MainWindow::on_backBtn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // return home
}


void MainWindow::on_backBtn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // return home
}


void MainWindow::on_cancelChangeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0); // return home
}


void MainWindow::on_powerBtn_released()
{
    if (isPowerOn == true) {
        isPowerOn = false;
    } else if (isPowerOn == false) {
        isPowerOn = true;
    }
    togglePower();
}


