#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T21:56:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DnD_Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    splashdialog.cpp \
    mapcreator.cpp \
    clicklabel.cpp \
    maphelpdialog.cpp \
    newgame.cpp \
    charcreator.cpp

HEADERS  += mainwindow.h \
    splashdialog.h \
    mapcreator.h \
    clicklabel.h \
    maphelpdialog.h \
    newgame.h \
    charcreator.h

FORMS    += mainwindow.ui \
    splashdialog.ui \
    mapcreator.ui \
    maphelpdialog.ui \
    newgame.ui \
    charcreator.ui

RESOURCES += \
    images.qrc
