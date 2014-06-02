// Copyright (C) 2014 Team306

#include "Ball.h"

Ball::Ball()
{
	rightRotation = 0;
	upRotation = 0;

	ballState = STILL;
}

Ball::Ball(Vector2 position, float radius)
    : position(position), radius(radius)
{
	// init rotation value
    Ball();
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
	if (speed.getX() > 0 || speed.getY() > 0)
	{
		ballState = RUNNING;
	}
	else
	{
		ballState = STILL;
	}
}

float Ball::getRadius() const
{
	return radius;
}

int Ball::getBallState() const
{
	return ballState;
}

std::string Ball::getName() const
{
	return name;
}

void Ball::setName(std::string n)
{
	name = n;
}

void Ball::setColor(QColor c)
{
	color = c;
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
	if (ballState == ON_THE_POCKET)
	{
		return;
	}

	// draw itself
	painter.setBrush(color);
    painter.drawEllipse(QPoint(position.getX(), position.getY()), radius, radius);
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
