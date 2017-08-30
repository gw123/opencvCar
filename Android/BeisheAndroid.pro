#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T22:01:48
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeisheAndroid
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclient.cpp

HEADERS  += mainwindow.h \
    tcpclient.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
