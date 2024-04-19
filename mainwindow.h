#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include "deviceprofile.h"
#include <QMessageBox>
//#include "digitalclock.h"
#include <QLCDNumber>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;
    QLabel *redLED;

private:
    Ui::MainWindow *ui;
    bool isPowerOn;
    deviceProfile* devProfile;
//    DigitalClock* sessionClock; -> alternate i tried bc i thought i was being slick about states but i wasnt lol
//    DigitalClock* connectionClock();
    QString formatTime(int totalSeconds);
    int remainingTime;
    QTimer *sTimer;
    int powerLevel;

    void togglePower();
    // battery level functions
    void drainBattery();
    void batteryDangerNotice();
    void chargeBattery();
    void updateBattery(int);
    void treatment();

    //date/time
    void setNewDate();
    void setCurrentDate();
    void getCurrentDate();

private slots:
    // session timers
    void updateSessTimer();

    void toggleLED(QLabel *LED);
    void turnOnLED(QLabel *LED);
    void turnOffLED(QLabel *redLED);
//    void updateDateTime(const QDateTime &dateTime);
    void on_newSessionBtn_clicked();
    void on_sessionLogBtn_clicked();
    void on_dateAndTimeBtn_clicked();
    void on_backBtn_clicked();
    void on_backBtn_2_clicked();
    void on_backBtn_3_clicked();
    void on_cancelChangeBtn_clicked();
    void on_powerBtn_released();

    // pause/start controls
    void on_stopBtn_2_clicked();
    void on_pauseBtn_2_clicked();
    void on_startBtn_2_clicked();
};
#endif // MAINWINDOW_H
