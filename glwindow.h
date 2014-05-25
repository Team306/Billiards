// Copyright (C) 2014 Team306

#ifndef GLWINDOW_H
#define GLWINDOW_H 


#include <QGLWidget>
#include <QTimer>
#include "Game.h"

class GLWindow : public QGLWidget
{
	Q_OBJECT

public:
	GLWindow(QWidget *parent = 0);
	~GLWindow();

public slots:

protected:
	void initializeGL();
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

private slots:
	void MainLoop();

private:
	Game game;

	QPoint lastPos;
	QTimer timer;
};


#endif
