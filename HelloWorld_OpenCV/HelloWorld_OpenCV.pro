#-------------------------------------------------
#
# Project created by QtCreator 2014-08-01T12:45:41
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = HelloWorld_OpenCV
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include(../opencv/opencv.pri)
