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
    computer.cpp \
    data.cpp \
    interface.cpp \
    list.cpp \
    person.cpp \
    mainwindow.cpp \
    welcome_widget.cpp \
    view_widget.cpp \
    update_widget.cpp \
    search_widget.cpp \
    remove_widget.cpp \
    discover_widget.cpp \
    add_widget.cpp \
    about_widget.cpp

HEADERS  += mainwindow.h \
    computer.h \
    data.h \
    interface.h \
    list.h \
    person.h \
    about_widget.h \
    add_widget.h \
    discover_widget.h \
    remove_widget.h \
    search_widget.h \
    update_widget.h \
    view_widget.h \
    welcome_widget.h \

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

RESOURCES += \
    hooper_resource.qrc
