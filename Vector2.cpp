// Copyright (C) 2014 Team306

#include "Vector2.h"

Vector2::Vector2(int x = 0, int y = 0)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

int Vector2::getX() const
{
	return x;
}

int Vector2::getY() const
{
	return y;
}
