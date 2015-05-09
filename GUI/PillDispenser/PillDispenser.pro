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
    database.cpp \
    acceptpopup.cpp \
    errorwindow.cpp \

HEADERS  += mainwindow.h \
    rename.h \
    database.h \
    acceptpopup.h \
    errorwindow.h \

FORMS    += mainwindow.ui
