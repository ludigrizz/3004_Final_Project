#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "datetimedialog.h"
#include <QDebug>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
// THESE COMMENTS ARE FOR REFIXING THE SLOTS AFTER SWITCHING TO STACKED WIDGETS - SOFIA
//    connect(ui->pauseBtn, SIGNAL(released()), this, SLOT(pauseSession()));
//    connect(ui->startBtn, SIGNAL(released()), this, SLOT(resumeSession()));
//    connect(ui->newSessionBtn, SIGNAL(released()), this, SLOT(startNewSession()));
//    connect(ui->sessionLogBtn, SIGNAL(released()), this, SLOT(getSessionLogs()));

////    connect(ui->dateAndTimeBtn, &QPushButton::clicked, this, &MainWindow::openDateTimeDialog);
//    connect(ui->dateAndTimeBtn, SIGNAL(released()), this, SLOT(openDateTimeDialog()));

//    connect(ui->stopBtn, SIGNAL(released()), this, SLOT(stopSession()));
//    connect(ui->powerBtn, SIGNAL(released()), this, SLOT(togglePower()));
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

