#-------------------------------------------------
#
# Project created by QtCreator 2014-05-20T14:03:25
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Billiards
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
