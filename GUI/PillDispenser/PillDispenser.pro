#-------------------------------------------------
#
# Project created by QtCreator 2015-04-17T11:56:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PillDispenser
TEMPLATE = app

PRECOMPILED_HEADER += database.h

SOURCES += database.cpp \
    main.cpp\
    mainwindow.cpp \
    rename.cpp \
    acceptpopup.cpp \
    errorwindow.cpp \
    idle.cpp \
    adduser.cpp \
    person.cpp \
    pills.cpp \
    changepills.cpp

HEADERS  += database.h \
    mainwindow.h \
    rename.h \
    acceptpopup.h \
    errorwindow.h \
    idle.h \
    adduser.h \
    person.h \
    pills.h \
    changepills.h

FORMS    += mainwindow.ui
