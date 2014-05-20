// Copyright (C) 2014 Team306

#ifndef BALL_H
#define BALL_H 


#include "Vector2.h"

class Ball
{
private:
	Vector2 position;
	Vector2 speed;

public:
	Ball(Vector2 position, Vector2 speed);
	~Ball();

	// get and set methods
	Vector2 getPosition() const;
	Vector2 getSpeed() const;

	// update and draw
	virtual void update();
	virtual void draw();
};


#endif
