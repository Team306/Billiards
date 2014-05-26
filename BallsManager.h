// Copyright (C) 2014 Team306

#ifndef BALLSMANAGER_H
#define BALLSMANAGER_H 


#include <vector>
#include "Ball.h"
#include "Referee.h"

// detect all collisions in this class
// maybe can use singleton
class BallsManager
{
private:
	std::vector<Ball> ballsList;
    Ball cueBall;

public:
	BallsManager();
	~BallsManager();

	// init methods
	void init(Referee &);
	void reset(Referee &); // reset all balls position

	// update and draw
	void Update();
	void Draw(QPainter &);

	// get and set
	Ball& getCueBall();
};


#endif
