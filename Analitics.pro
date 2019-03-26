#-------------------------------------------------
#
# Project created by QtCreator 2019-02-25T16:09:19
#
#-------------------------------------------------

QT       += core gui
QT += widgets
QT += multimediawidgets multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Analitics
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    moveitem.cpp \
    photo.cpp \
    info21.cpp \
    info01.cpp \
    info11.cpp \
    moveitem1.cpp \
    qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    moveitem.h \
    photo.h \
    qcustomplot.h \
    qcustomplot.h \
    info21.h \
    info01.h \
    info11.h \
    moveitem1.h

FORMS += \
        mainwindow.ui \
    info.ui \
    photo.ui \
    info1.ui \
    info2.ui \
    info21.ui \
    info01.ui \
    info11.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
