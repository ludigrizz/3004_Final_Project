/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Application;
    QGraphicsView *graphicsView_5;
    QFrame *line;
    QTextEdit *textEdit;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *sessionLogBtn;
    QPushButton *newSessionBtn;
    QPushButton *dateAndTimeBtn;
    QWidget *page_2;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *confirmChangeBtn;
    QPushButton *cancelChangeBtn;
    QPushButton *backBtn;
    QLabel *label;
    QWidget *page_3;
    QPushButton *backBtn_2;
    QListView *listView_2;
    QWidget *page_4;
    QPushButton *stopBtn_2;
    QPushButton *startBtn_2;
    QPushButton *pauseBtn_2;
    QPushButton *backBtn_3;
    QLCDNumber *sessTimer;
    QCustomPlot *customPlot;
    QWidget *page_5;
    QPushButton *powerBtn;
    QProgressBar *battery;
    QPushButton *greenled;
    QPushButton *blueled;
    QPushButton *redled;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(433, 660);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(169,169,169);"));
        Application = new QWidget(MainWindow);
        Application->setObjectName(QString::fromUtf8("Application"));
        graphicsView_5 = new QGraphicsView(Application);
        graphicsView_5->setObjectName(QString::fromUtf8("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(30, 410, 161, 151));
        line = new QFrame(Application);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(100, 290, 20, 121));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        textEdit = new QTextEdit(Application);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(60, 450, 104, 70));
        stackedWidget = new QStackedWidget(Application);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 20, 331, 271));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(135,206,250);"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        sessionLogBtn = new QPushButton(page);
        sessionLogBtn->setObjectName(QString::fromUtf8("sessionLogBtn"));
        sessionLogBtn->setGeometry(QRect(80, 120, 171, 41));
        newSessionBtn = new QPushButton(page);
        newSessionBtn->setObjectName(QString::fromUtf8("newSessionBtn"));
        newSessionBtn->setGeometry(QRect(80, 60, 171, 41));
        dateAndTimeBtn = new QPushButton(page);
        dateAndTimeBtn->setObjectName(QString::fromUtf8("dateAndTimeBtn"));
        dateAndTimeBtn->setGeometry(QRect(80, 180, 171, 41));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        dateTimeEdit = new QDateTimeEdit(page_2);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(70, 40, 194, 26));
        confirmChangeBtn = new QPushButton(page_2);
        confirmChangeBtn->setObjectName(QString::fromUtf8("confirmChangeBtn"));
        confirmChangeBtn->setGeometry(QRect(110, 90, 111, 25));
        cancelChangeBtn = new QPushButton(page_2);
        cancelChangeBtn->setObjectName(QString::fromUtf8("cancelChangeBtn"));
        cancelChangeBtn->setGeometry(QRect(130, 130, 71, 25));
        backBtn = new QPushButton(page_2);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(30, 220, 71, 25));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 180, 281, 17));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        backBtn_2 = new QPushButton(page_3);
        backBtn_2->setObjectName(QString::fromUtf8("backBtn_2"));
        backBtn_2->setGeometry(QRect(10, 230, 51, 25));
        listView_2 = new QListView(page_3);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));
        listView_2->setGeometry(QRect(30, 50, 261, 161));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stopBtn_2 = new QPushButton(page_4);
        stopBtn_2->setObjectName(QString::fromUtf8("stopBtn_2"));
        stopBtn_2->setGeometry(QRect(90, 220, 51, 25));
        startBtn_2 = new QPushButton(page_4);
        startBtn_2->setObjectName(QString::fromUtf8("startBtn_2"));
        startBtn_2->setGeometry(QRect(230, 220, 71, 25));
        pauseBtn_2 = new QPushButton(page_4);
        pauseBtn_2->setObjectName(QString::fromUtf8("pauseBtn_2"));
        pauseBtn_2->setGeometry(QRect(160, 220, 51, 25));
        backBtn_3 = new QPushButton(page_4);
        backBtn_3->setObjectName(QString::fromUtf8("backBtn_3"));
        backBtn_3->setGeometry(QRect(20, 220, 51, 25));
        sessTimer = new QLCDNumber(page_4);
        sessTimer->setObjectName(QString::fromUtf8("sessTimer"));
        sessTimer->setGeometry(QRect(100, 20, 131, 41));
        customPlot = new QCustomPlot(page_4);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(39, 69, 261, 131));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);
        powerBtn = new QPushButton(Application);
        powerBtn->setObjectName(QString::fromUtf8("powerBtn"));
        powerBtn->setGeometry(QRect(310, 0, 51, 21));
        battery = new QProgressBar(Application);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(230, 0, 61, 21));
        battery->setStyleSheet(QString::fromUtf8("QProgressBar::chunk {\n"
"	background-color: #ff0000;\n"
"	width: 10px;\n"
"	margin: 0.5px;\n"
"}"));
        battery->setValue(24);
        greenled = new QPushButton(Application);
        greenled->setObjectName(QString::fromUtf8("greenled"));
        greenled->setGeometry(QRect(120, 0, 31, 16));
        blueled = new QPushButton(Application);
        blueled->setObjectName(QString::fromUtf8("blueled"));
        blueled->setGeometry(QRect(80, 0, 31, 16));
        redled = new QPushButton(Application);
        redled->setObjectName(QString::fromUtf8("redled"));
        redled->setGeometry(QRect(40, 0, 31, 16));
        MainWindow->setCentralWidget(Application);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 433, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">EEG HEADSET</p></body></html>", nullptr));
        sessionLogBtn->setText(QCoreApplication::translate("MainWindow", "SESSION LOG", nullptr));
        newSessionBtn->setText(QCoreApplication::translate("MainWindow", "NEW SESSION", nullptr));
        dateAndTimeBtn->setText(QCoreApplication::translate("MainWindow", "DATE AND TIME", nullptr));
        confirmChangeBtn->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        cancelChangeBtn->setText(QCoreApplication::translate("MainWindow", "CANCEL", nullptr));
        backBtn->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        backBtn_2->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        stopBtn_2->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        startBtn_2->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        pauseBtn_2->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        backBtn_3->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        powerBtn->setText(QCoreApplication::translate("MainWindow", "ON/OFF", nullptr));
        greenled->setText(QString());
        blueled->setText(QString());
        redled->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
