#-------------------------------------------------
#
# Project created by QtCreator 2015-07-16T02:12:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = notifier
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        netw.cpp \
        mainwindow.cpp


HEADERS  += netw.h \
        mainwindow.h

