#-------------------------------------------------
#
# Project created by QtCreator 2014-07-15T19:38:24
#
#-------------------------------------------------

QT       += core gui widgets



TARGET = ColorProcessor
TEMPLATE = app


SOURCES += main.cpp\
        videoplayer.cpp \
    colorprocessor.cpp

HEADERS  += videoplayer.h \
    colorprocessor.h

FORMS    += videoplayer.ui

include(../opencv/videoengine.pri)
