#-------------------------------------------------
#
# Project created by QtCreator 2013-11-03T19:42:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtTest2
TEMPLATE = app


SOURCES += main.cpp\
        gcharacterobserver.cpp \
    Observable.cpp \
    Item.cpp \
    Fighter.cpp \
    Dice.cpp \
    CharacterObserver.cpp \
    Character.cpp

HEADERS  += gcharacterobserver.h \
    Observer.h \
    Observable.h \
    Item.h \
    Fighter.h \
    Dice.h \
    CharacterObserver.h \
    Character.h

FORMS    += gcharacterobserver.ui
