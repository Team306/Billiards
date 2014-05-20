// Copyright (C) 2014 Team306

#include "Ball.h"

Ball::Ball(Vector2 position, Vector2 speed, float radius)
	: position(position), speed(speed), radius(radius)
{
}

Ball::~Ball()
{
}

Vector2 Ball::getPosition() const
{
	return position;
}

Vector2 Ball::getSpeed() const
{
	return speed;
}

void Ball::Update()
{
	position += speed;
	// speed should slow down because of friction
	// speed -= friction;
}

void Ball::Draw(QPainter& painter)
{
	// draw itself here
}
