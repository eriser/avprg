QT += core
QT -= gui

CONFIG += c++11

TARGET = ClassesAndObjects
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    example.cpp \
    context.cpp \
    strategycontext.cpp

HEADERS += \
    example.h \
    context.h \
    strategycontext.h
