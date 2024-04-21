QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LED.cpp \
    batteryprogressbar.cpp \
    batteryprogressbar.cpp \
    datetimedialog.cpp \
    deviceprofile.cpp \
    digitalclock.cpp \
    electrode.cpp \
    graph.cpp \
    handleconnection.cpp \
    ledindicator.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    session.cpp \
    test.cpp \
    wave.cpp
    pcwindow.cpp


HEADERS += \
    LED.h \
    batteryprogressbar.h \
    datetimedialog.h \
    deviceControl.h \
    deviceprofile.h \
    digitalclock.h \
    electrode.h \
    graph.h \
    handleconnection.h \
    ledindicator.h \
    mainwindow.h \
    qcustomplot.h \
    session.h \
    wave.h
    pcwindow.h


FORMS += \
    mainwindow.ui \
    pcwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    icons/Screenshot 2024-04-17 at 2.33.06 PM.png \
    icons/blue.png \
    icons/green.png \
    icons/red.png
