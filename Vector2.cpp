// Copyright (C) 2014 Team306

#include "Vector2.h"

Vector2::Vector2(float x = 0, float y = 0)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

// get and set methods
float Vector2::getX() const
{
	return x;
}

float Vector2::getY() const
{
	return y;
}

void Vector2::setXY(float x, float y)
{
	this->x = x;
	this->y = y;
}

// override operators
Vector2 Vector2::operator+(Vector2& v)
{
	Vector2 result;
	result.x = this->x + v.x;
	result.y = this->y + v.y;
	return result;
}
	
Vector2 Vector2::operator-(Vector2& v)
{
	Vector2 opposite(-v.getX(), -v.getY());
	Vector2 result = *this + opposite;
	return result;
}

float Vector2::dotProduct(Vector2& v)
{
	float result = this->x * v.x + this->y * v.y;
	return result;
}

Vector2 Vector2::operator+=(Vector2& v)
{
	Vector2 result = *this + v;
	this->x = result->x;
	this->y = result->y;
	return result;
}

Vector2 Vector2::operator-=(Vector2& v)
{
	Vector2 result = *this - v;
	this->x = result.x;
	this->y = result.y;
	return result;
}
