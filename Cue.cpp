// Copyright (C) 2014 Team306

#include "Cue.h"

Cue::Cue()
{
}

Cue::~Cue()
{
}

void Cue::init(Referee& referee)
{
	ballRadius = referee.getBallRadius();
	cueLength = 50;
}

void Cue::Update()
{
	// Update here

}

void Cue::Draw(QPainter& painter, Vector2 mousePosition, Ball& cueBall)
{
	// Draw here
	QColor frontSightColor(255, 255, 255, 200);
	painter.setPen(frontSightColor);
	painter.setBrush(frontSightColor);
    painter.drawEllipse(QPoint(mousePosition.getX(), mousePosition.getY()), ballRadius, ballRadius);

    Vector2 cuePosition = cueBall.getPosition();
    QColor lineColor(0, 0, 0);
    painter.setPen(lineColor);
	painter.drawLine(cuePosition.getX(), cuePosition.getY(), mousePosition.getX(), mousePosition.getY());
}
