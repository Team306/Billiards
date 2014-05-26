// Copyright (C) 2014 Team306

#include <QMouseEvent>
#include <QTimer>
#include <QDesktopWidget>
#include <QApplication>
#include "glwindow.h"

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE 0x809D
#endif

// fps
const int msPerFrame = 16;

GLWindow::GLWindow(QWidget *parent)
	: QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
	timer.setSingleShot(false);
	connect(&timer, SIGNAL(timeout()), this, SLOT(MainLoop()));
	timer.start(msPerFrame);

	setFixedSize(1280, 720);
    setWindowTitle(tr("Billiards by Team306"));

    // put the window in center
    QDesktopWidget *desktop = QApplication::desktop();
    if (desktop->width() != 1366 && desktop->height() != 768)
    {
    	move((1920 - 1280) / 2, (1080 - 720) / 2);
    }
    else
    {
   	    move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) / 2);
    }
}

GLWindow::~GLWindow()
{
}

void GLWindow::initializeGL()
{
	glEnable(GL_MULTISAMPLE);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // temp put init here
    game.init();
}

void GLWindow::mousePressEvent(QMouseEvent *event)
{
	// 
}

void GLWindow::mouseMoveEvent(QMouseEvent *event)
{
	//
}

void GLWindow::paintEvent(QPaintEvent *event)
{
	makeCurrent();
	glClear(GL_COLOR_BUFFER_BIT);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
    game.Draw(painter);
	painter.end();
}

void GLWindow::MainLoop()
{
	game.Update();
	// call repaint
    update();
    // updateGL();
}

void GLWindow::paintGL()
{
    makeCurrent();
    glClear(GL_COLOR_BUFFER_BIT);
}
