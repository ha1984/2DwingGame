#-------------------------------------------------
#
# Project created by QtCreator 2016-10-25T15:16:21
#
#-------------------------------------------------

QT       += core gui \
         multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tutorial1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp \
    Player.cpp

HEADERS  += mainwindow.h \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    health.h \
    Player.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
