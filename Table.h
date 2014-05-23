// Copyright (C) 2014 Team306

#ifndef TABLE_H
#define TABLE_H 


#include <QPainter>
#include "Vector2.h"
#include "Ball.h"

class Table
{
private:
	// table size do not equal picture size
	Vector2 size;
	Vector2 picSize;

	Vector2 position;
	Vector2 picPosition;

public:
	Table(Vector2 position, Vector2 size, Vector2 picPosition, Vector2 picSize);
	~Table();

	// get and set method
	Vector2 getSize() const;
	
	// update and draw
	void Update();
	void Draw(QPainter &);

	// collision detection
	bool collidesWith(Ball &);
};


#endif
