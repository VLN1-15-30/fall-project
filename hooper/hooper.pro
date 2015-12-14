QT = core gui sql

TARGET = hooper
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    UI/interface.cpp \
    Models/computer.cpp \
    Models/connection.cpp \
    Models/person.cpp \
    Services/list.cpp \
    Repo/personrepo.cpp \
    Utilities/utils.cpp \
    Repo/computerrepo.cpp \
    Repo/connectionrepo.cpp

HEADERS += \
    UI/interface.h \
    Models/computer.h \
    Models/connection.h \
    Models/person.h \
    Services/list.h \
    Repo/personrepo.h \
    Utilities/utils.h \
    Repo/computerrepo.h \
    Repo/connectionrepo.h

INCLUDEPATH += Models \
    Repo \
    Repo \
    UI
