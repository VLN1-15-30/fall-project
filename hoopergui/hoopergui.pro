#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T12:40:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hoopergui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    data.cpp \
    interface.cpp \
    list.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    computer.h \
    data.h \
    interface.h \
    list.h \
    person.h

FORMS    += mainwindow.ui
