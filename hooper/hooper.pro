QT = core gui sql

TARGET = hooper
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    list.cpp \
    interface.cpp \
    computer.cpp \
    data.cpp

HEADERS += \
    person.h \
    list.h \
    interface.h \
    computer.h \
    data.h

