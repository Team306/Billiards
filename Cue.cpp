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
	painter.setBrush(QColor(0, 0, 0));
    painter.drawEllipse(QPoint(mousePosition.getX(), mousePosition.getY()), ballRadius, ballRadius);

    Vector2 cuePosition = cueBall.getPosition();
	painter.drawLine(cuePosition.getX(), cuePosition.getY(), mousePosition.getX(), mousePosition.getY());
}
