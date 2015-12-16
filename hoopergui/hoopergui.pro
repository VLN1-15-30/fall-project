#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T12:40:01
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hoopergui
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    welcome_widget.cpp \
    view_widget.cpp \
    update_widget.cpp \
    search_widget.cpp \
    remove_widget.cpp \
    discover_widget.cpp \
    add_widget.cpp \
    about_widget.cpp \
    Models/computer.cpp \
    Models/connection.cpp \
    Models/person.cpp \
    Repo/computerrepo.cpp \
    Repo/connectionrepo.cpp \
    Repo/personrepo.cpp \
    Services/list.cpp \
    UI/interface.cpp \
    Utilities/utils.cpp

HEADERS  += mainwindow.h \
    about_widget.h \
    add_widget.h \
    discover_widget.h \
    remove_widget.h \
    search_widget.h \
    update_widget.h \
    view_widget.h \
    welcome_widget.h \
    Models/computer.h \
    Models/connection.h \
    Models/person.h \
    Repo/computerrepo.h \
    Repo/connectionrepo.h \
    Repo/personrepo.h \
    Services/list.h \
    UI/interface.h \
    Utilities/utils.h

FORMS    += mainwindow.ui \
    about_widget.ui \
    add_widget.ui \
    discover_widget.ui \
    remove_widget.ui \
    search_widget.ui \
    update_widget.ui \
    view_widget.ui \
    welcome_widget.ui \

    about_widget.ui

INCLUDEPATH += Models \
    Repo \
    Interface \
    UI


RESOURCES += \
    hooper_resource.qrc
