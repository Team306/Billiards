// Copyright (C) 2014 Team306

#ifndef VECTOR2_H
#define VECTOR2_H 


class Vector2
{
private:
	int x;
	int y;

public:
	Vector2(int x = 0, int y = 0);
	~Vector2();

	int getX() const;
	int getY() const;
	bool setXY(int, int);

	// override operators
};


#endif
