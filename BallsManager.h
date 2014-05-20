// Copyright (C) 2014 Team306

#ifndef BALLSMANAGER_H
#define BALLSMANAGER_H 


#include <vector>
#include "Ball.h"

// detect all collisions in this class
// maybe can use singleton
class BallsManager
{
private:
	std::vector<Ball> ballsList;

public:
	BallsManager();
	~BallsManager();

	// update and draw
	void Update();
	void Draw();
};


#endif
