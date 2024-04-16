#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>
#include <QLabel>

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

private slots:
    void startNewSession();
    void getSessionLogs();
    void openDateTimeDialog();
    void pauseSession();
    void stopSession();
    void resumeSession();
    void togglePower();
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
};
#endif // MAINWINDOW_H
