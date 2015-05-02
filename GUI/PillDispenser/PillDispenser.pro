#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T11:56:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PillDispenser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rename.cpp \
    Database.cpp \
    acceptpopup.cpp \
    errorwindow.cpp \
    adduser.cpp

HEADERS  += mainwindow.h \
    rename.h \
    Database.hpp \
    acceptpopup.h \
    errorwindow.h \
    adduser.h

FORMS    += mainwindow.ui
