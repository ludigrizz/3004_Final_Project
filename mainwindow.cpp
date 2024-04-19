#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "datetimedialog.h"
#include <QDebug>
#include <QLabel>
#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QWidget>
#include "deviceprofile.h"
//#include "ledindicator.cpp"
#include <QDateEdit>
//#include "digitalclock.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      remainingTime(60),
      labelDateTime(ui->label)
{
    ui->setupUi(this);
    QDate d = QDate::currentDate();
    devProfile = new deviceProfile(1,100.00, &d);
    powerLevel = devProfile->getBatteryLevel();

    // sessionTimer initialization
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSessTimer()));
    ui->sessTimer->display(formatTime(remainingTime));
    //TBD: add ui->sessTimer->setHidden(true); => for the timeout usecase


//    DigitalClock *digitalClock = new DigitalClock(ui->lcdTimer);

//    connect(ui->lcdTimer, SIGNAL)
    setCurrentDate();
//    LedIndicator *ledIndicator = new LedIndicator(this);

//    setCentralWidget(ledIndicator);
    isPowerOn = false;
    togglePower();

//    ledIndicator->changeToRed();


    //initialize the default battery
    ui->battery->setStyleSheet("QProgressBar::chunk {background-color: #00ff00; width: 10px; margin: 0.5px;}");
    ui->battery->setOrientation(Qt::Horizontal);
    ui->battery->setRange(0,100);
    ui->battery->setValue(99);

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

    //initialize device date/time to be current
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &MainWindow::on_dateTimeEdit_dateTimeChanged);
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &MainWindow::displayDateTime);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getCurrentDate() {
    ui->dateTimeEdit->dateTime();

}

void MainWindow::setCurrentDate() {
    QDate date = QDate::currentDate();
    QString dateString = date.toString();
    ui->dateTimeEdit->setDate(date);
    qDebug() << "Date String: " << dateString;
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

QString MainWindow::formatTime(int totalSeconds) {
    int mins = totalSeconds/60;
    int secs =totalSeconds%60;
    return QString("%1:%2").arg(mins,2,10,QChar('0')).arg(secs,2,10,QChar('0'));
}



void MainWindow::updateSessTimer() {
    if (remainingTime>0) {
        remainingTime--;
        ui->sessTimer->display(formatTime(remainingTime));
    } else{
        on_stopBtn_2_clicked();
    }
}

//void MainWindow::openDateTimeDialog() {
//    qInfo("user pressed date and time to set date and time");
////    DateTimeDialog dialog(this);
////    connect(&dialog, &DateTimeDialog::dateTimeSelected, this, &MainWindow::updateDateTime);
////    dialog.exec();

//}

//void MainWindow::(const QDateTime &dateTime) {
//    qDebug() << "New date and time selected: " << dateTime.toString();
//}

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



void MainWindow::on_stopBtn_2_clicked()
{
    qInfo("stOP");
    timer->stop();
    remainingTime = 60;
    ui->sessTimer->display(formatTime(remainingTime));
}


void MainWindow::on_pauseBtn_2_clicked()
{
    qInfo("pause");
    timer->stop();
}

void MainWindow::on_startBtn_2_clicked()
{
    qInfo("start");
    timer->start(1000);
}

void MainWindow::displayDateTime(const QDateTime &dateTime) {
    QString formattedStrDateTime = dateTime.toString("yyyy-MM-dd HH:mm:ss");
    qDebug() << "User changed date/time to: " << formattedStrDateTime;
    ui->label->setText("Date/Time Set: " + formattedStrDateTime);
}


void MainWindow::on_dateTimeEdit_dateTimeChanged(const QDateTime &newDateTime)
{
    qDebug() << "User changed date/time to: " << newDateTime.toString("yyyy-MM-dd HH:mm:ss");
    // this should probably be stored to something to be added to the sessionInfo/ sessiontxt file
    // to view later via the session Log or PC log
    displayDateTime(newDateTime);

}


void MainWindow::on_confirmChangeBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

