// Copyright (C) 2014 Team306

#include "Ball.h"

Ball::Ball(Vector2 position, Vector2 speed)
	: position(position), speed(speed)
{
}

Ball::~Ball()
{
}

Vector2 getPosition() const
{
	return position;
}

Vector2 getSpeed() const
{
	return speed;
}
