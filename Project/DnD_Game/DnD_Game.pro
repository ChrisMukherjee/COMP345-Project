#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T21:56:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DnD_Game
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    splashdialog.cpp \
    mapcreator.cpp \
    clicklabel.cpp \
    maphelpdialog.cpp \
    newgame.cpp \
    charcreator.cpp \
    TankFighterBuilder.cpp \
    Observable.cpp \
    NimbleFighterBuilder.cpp \
    Monster.cpp \
    InputManager.cpp \
    InputEvent.cpp \
    FighterDirector.cpp \
    Fighter.cpp \
    Dice.cpp \
    CharacterObserver.cpp \
    Character.cpp \
    Cell.cpp \
    BullyFighterBuilder.cpp \
    Item.cpp \
    GridObserver.cpp \
    GridContent.cpp \
    Grid.cpp \
    ContainerObserver.cpp \
    Driver.cpp \
    main.cpp

HEADERS  += mainwindow.h \
    splashdialog.h \
    mapcreator.h \
    clicklabel.h \
    maphelpdialog.h \
    newgame.h \
    charcreator.h \
    TankFighterBuilder.h \
    Observer.h \
    Observable.h \
    NimbleFighterBuilder.h \
    Monster.h \
    InputManager.h \
    InputEvent.h \
    FighterDirector.h \
    FighterBuilder.h \
    Fighter.h \
    Dice.h \
    CharacterObserver.h \
    Character.h \
    Item.h \
    GridObserver.h \
    GridContent.h \
    Grid.h \
    ContainerObserver.h \
    Cell.h \
    BullyFighterBuilder.h

FORMS    += mainwindow.ui \
    splashdialog.ui \
    mapcreator.ui \
    maphelpdialog.ui \
    newgame.ui \
    charcreator.ui

RESOURCES += \
    images.qrc
