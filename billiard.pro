#-------------------------------------------------
#
# Project created by QtCreator 2014-06-07T10:01:58
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = billiard
TEMPLATE = app


SOURCES += \
    Ball.cpp \
    BallsManager.cpp \
    Cue.cpp \
    Game.cpp \
    glwindow.cpp \
    main.cpp \
    Player.cpp \
    Referee.cpp \
    Table.cpp \
    MyMath.cpp \
    CollideEngine.cpp

HEADERS  += \
    Ball.h \
    BallsManager.h \
    Cue.h \
    Game.h \
    glwindow.h \
    Player.h \
    Referee.h \
    Table.h \
    MyMath.h \
    CollideEngine.h

FORMS    +=
