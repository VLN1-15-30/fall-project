QT += core
QT -= gui

TARGET = hooper
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    list.cpp \
    interface.cpp

HEADERS += \
    person.h \
    list.h \
    interface.h

