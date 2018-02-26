#-------------------------------------------------
#
# Project created by QtCreator 2016-06-28T10:48:37
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = device_management
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    humanmanagement.cpp \
    devicecheck.cpp

HEADERS  += mainwindow.h \
    humanmanagement.h \
    devicecheck.h

FORMS    += mainwindow.ui \
    humanmanagement.ui \
    devicecheck.ui
