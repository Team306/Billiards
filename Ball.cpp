// Copyright (C) 2014 Team306

#include "Ball.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius)
	: position(position), speed(speed), radius(radius)
{
	// init rotation value
	rightRotation = 0;
	upRotation = 0;
}

Ball::~Ball()
{
}

Vector2 Ball::getPosition() const
{
	return position;
}

void Ball::setPosition(Vector2 v)
{
	position = v;
}

Vector2 Ball::getSpeed() const
{
	return speed;
}

void Ball::setSpeed(Vector2 v)
{
	speed = v;
}

void Ball::Update()
{
	position += speed;
	// speed should slow down because of friction
	// speed -= friction;

	// DO NOT DETECK COLLISION HERE!
}

void Ball::Draw(QPainter& painter)
{
	// draw itself
	QColor kagamine_iro(255, 252, 0);
	painter.setBrush(kagamine_iro);
    painter.drawEllipse(QPoint(position.getX() - radius, position.getY() - radius), radius, radius);
}

// only return if 2 balls collide
bool Ball::collidesWith(Ball& b)
{
	float distance = this->position.distanceBetween(b.position);
	if (distance - this->radius - b.radius <= 0)
	{
		return true;
	}
	return false;
}
