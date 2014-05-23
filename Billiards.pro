#-------------------------------------------------
#
# Project created by QtCreator 2014-05-20T14:03:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Billiards
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    renderarea.cpp \
    Game.cpp \
    Ball.cpp \
    Vector2.cpp \
    BallsManager.cpp

HEADERS  += window.h \
    renderarea.h \
    Ball.h \
    BallsManager.h \
    Cue.h \
    Game.h \
    Vector2.h
