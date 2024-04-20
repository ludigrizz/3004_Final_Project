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
#include "digitalclock.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      remainingTime(MAX_TIME),
      labelDateTime(ui->label),
      graph(0)
{
    ui->setupUi(this);
    QDate d = QDate::currentDate();
    devProfile = new deviceProfile(1,100.00, &d);
    powerLevel = devProfile->getBatteryLevel();

    //qpushbutton styling:
    int ledSize = 20;
    ui->redled->setFixedSize(ledSize, ledSize);
    ui->redled->setStyleSheet("QPushButton {background-color: grey; border-radius: 10; border: 2px solid black;}");
    ui->greenled->setFixedSize(ledSize, ledSize);
    ui->greenled->setStyleSheet("QPushButton {background-color: grey; border-radius: 10; border: 2px solid black;}");
    ui->blueled->setFixedSize(ledSize, ledSize);
    ui->blueled->setStyleSheet("QPushButton {background-color: grey; border-radius: 10; border: 2px solid black;}");

    // sessionTimer initialization
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateSessTimer()));
    ui->sessTimer->display(formatTime(remainingTime));
    //TBD: add ui->sessTimer->setHidden(true); => for the timeout usecase

    ui->redled->setStyleSheet("background-color: grey");
    ui->blueled->setStyleSheet("background-color: grey");
    ui->greenled->setStyleSheet("background-color: grey");


    //    bool hasContact = false;
    //SOMEFUNCTION THAT INITIALIZES THE CONTACT/STARTS SESSION WHICH MAKES...
    //    hasContact = true;
    //    on_redled_toggled(true);
    on_blueled_toggled(true);
    on_greenled_toggled(true);



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

    //initialize device date/time to be current
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &MainWindow::on_dateTimeEdit_dateTimeChanged);
    connect(ui->dateTimeEdit, &QDateTimeEdit::dateTimeChanged, this, &MainWindow::displayDateTime);

    ui->stackedWidget->setCurrentIndex(0); //makes sure its always on menu screen
}

MainWindow::~MainWindow()
{
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
    // TO DO: testing needs that after 2-3 treatments the battery is empty so we remove 1/3 of the battery each time this loops
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
    qDebug() << "remainging:" << remainingTime;
    if (remainingTime>0) {
        remainingTime--;
        ui->sessTimer->display(formatTime(remainingTime));

        // get remaining time
        int rtime = timer->remainingTime();

        qDebug() << "updatesession.." << rtime;

        int currtime = MAX_TIME-remainingTime;

        /* calculating dominant frequency, delivering 1-second feedback at
         * 1/16 of dominant + offset, rounds of therapy, and therapy */

        if (remainingTime == 30) {
            session->treatmentRound(5, 1);
            graph->updateGraph(currtime, 150);

        } else if (remainingTime == 25) {
            int freq = session->getDominantFrequency(0);
            graph->updateGraph(currtime, freq);

        } else if (remainingTime == 24) {
            session->treatmentRound(10, 2);
            graph->updateGraph(currtime, 150);

        } else if (remainingTime == 19) {
            int freq = session->getDominantFrequency(0);
            graph->updateGraph(currtime, freq);

        } else if (remainingTime == 18) {
            session->treatmentRound(15, 3);

            graph->updateGraph(currtime, 150);
        } else if (remainingTime == 13) {
            int freq = session->getDominantFrequency(0);
            graph->updateGraph(currtime, freq);

        } else if (remainingTime == 12) {
            session->treatmentRound(20, 4);
            graph->updateGraph(currtime, 150);

        } else if (remainingTime == 7) {
            int freq = session->getDominantFrequency(0);
            graph->updateGraph(currtime, freq);

        } else {
            int freq = session->getFrequency(0, currtime);
            graph->updateGraph(currtime, freq);
        }

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
    //ui->stackedWidget->setVisible(isPowerOn);
    isPowerOn = !isPowerOn; // Toggle the power state
    ui->stackedWidget->setVisible(isPowerOn); // Existing functionality
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
    ui->stackedWidget->setCurrentIndex(3);
    // go to new session view
    qDebug() << "Starting new session..."<< isPowerOn ;
    if (isPowerOn) {
        initializeGraph();

        //Same waves
        Wave alpha(9, 2, "alpha");
        Wave beta(15, 2, "beta");
        Wave delta(2, 2, "delta");
        Wave theta(4, 2, "theta");

        Wave alpha2(10, 2, "alpha");
        Wave beta2(14, 2, "beta");
        Wave delta2(1, 2, "delta");
        Wave theta2(5, 2, "theta");


        // Define sample electrodes
        Electrode electrodes[] = {
            Electrode(alpha, beta, delta, theta),
            Electrode(alpha, beta, delta, theta),
            Electrode(alpha, beta, delta, theta),
            Electrode(alpha, beta, delta, theta),
            Electrode(alpha2, beta2, delta2, theta2)// Sample electrode 1
            //        {15, 25, 35, 45, 55, 65, 75, 85}, // Sample electrode 2
            // Add more sample electrodes as needed
        };
        int numElectrodes = sizeof(electrodes) / sizeof(electrodes[0]);

        //    Electrode [] *elctrodesPtr = &

        // Create a session object
        session = new Session(electrodes, numElectrodes);

    }
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

    timer->start(1000); // 1.30 min
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


void MainWindow::on_redled_toggled(bool lostContact)
{
    QTimer *redTimer = new QTimer(this);
    //    QObject *redObj = ui->redled;

    if (lostContact) {
        connect(redTimer, &QTimer::timeout, [this]() {
            static bool isOn = true;
            ui->redled->setStyleSheet(isOn ? "background-color: red" : "background-color: grey");
            isOn= !isOn;
        });
        redTimer->start(500);
    } else {
        timer->stop();
        ui->redled->setStyleSheet("background-color: grey");
    }
}


void MainWindow::on_blueled_toggled(bool hasContact)
{
    if (hasContact) {
        ui->blueled->setStyleSheet("background-color: blue");
    } else {
        ui->blueled->setStyleSheet("background-color: grey");
        on_redled_toggled(hasContact);
    }
}


void MainWindow::on_greenled_toggled(bool lostContact)
{
    QTimer *greemTimer = new QTimer(this);

    if (lostContact) {
        connect(greemTimer, &QTimer::timeout, [this]() {
            static bool isOn = true;
            ui->greenled->setStyleSheet(isOn ? "background-color: green" : "background-color: grey");
            isOn= !isOn;
        });
        greemTimer->start(500);
    } else {
        timer->stop();
        ui->greenled->setStyleSheet("background-color: grey");
    }
}


void MainWindow::initializeGraph() {
    if (!graph) {  // Ensure graph is only initialized once
        // Check if the customPlot widget from the UI file is correctly initialized
        if (!ui->customPlot) {
            qWarning() << "CustomPlot widget is not initialized!";
            return;
        }

        // Create the Graph object using the customPlot widget
        graph = new Graph(ui->customPlot, this);

        // Check if the Graph object was created successfully
        if (!graph) {
            qWarning() << "Failed to create Graph object!";
            return;
        }
    } else {
        qDebug() << "Graph is already initialized.";
    }

}
//void MainWindow::clearGraph() {
//    if (graph) {
//        // Depending on your design, you might delete the graph or simply hide it
//       // graph->clearData(); // You might need to implement this method in your Graph class
//        graph->setVisible(false);
//    }
//}
