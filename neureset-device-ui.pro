QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datetimedialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    LED.h \
    datetimedialog.h \
    deviceControl.h \
    deviceStates.h \
    deviceStates.h \
    mainwindow.h \
    sessionLog.h
    contoller.h \
    mainwindow.h \
    neuroHeadset.h \
    powerState.h \
    sessionLog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    LED.h \
    datetimedialog.h \
    deviceControl.h \
    deviceStates.h \
    mainwindow.h \
    sessionLog.h
    contoller.h \
    mainwindow.h \
    neuroHeadset.h \
    powerState.h \
    sessionLog.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
