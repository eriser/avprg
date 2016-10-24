#-------------------------------------------------
#
# Project created by QtCreator 2014-08-04T12:43:08
#
#-------------------------------------------------

QT       += core gui widgets multimedia


TARGET = WavePlayer
TEMPLATE = app

INCLUDEPATH += ../audioEngine
SOURCES += main.cpp\
        mainwindow.cpp\

HEADERS  += mainwindow.h \
    audiofile.h\

FORMS    += mainwindow.ui

include(../audioEngine/audioengine.pri)
