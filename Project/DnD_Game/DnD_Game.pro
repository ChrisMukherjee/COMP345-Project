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
    Dice.cpp \
    CharacterObserver.cpp \
    Character.cpp \
    Cell.cpp \
    Item.cpp \
    InputManager.cpp \
    InputEvent.cpp \
    GridContent.cpp \
    Grid.cpp \
    Fighter.cpp \
    Observable.cpp \
    GridObserver.cpp

HEADERS  += mainwindow.h \
    splashdialog.h \
    mapcreator.h \
    Dice.h \
    CharacterObserver.h \
    Character.h \
    Cell.h \
    Item.h \
    InputManager.h \
    InputEvent.h \
    GridObserver.h \
    GridContent.h \
    Grid.h \
    Fighter.h \
    Observer.h \
    Observable.h

FORMS    += mainwindow.ui \
    splashdialog.ui \
    mapcreator.ui

RESOURCES += \
    images.qrc
