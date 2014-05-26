// Copyright (C) 2014 Team306

#include "BallsManager.h"

BallsManager::BallsManager()
{
}

BallsManager::~BallsManager()
{
}

void BallsManager::init(Referee& referee)
{
	// call referee for balls' info
	ballsList = referee.getBallsList();
	cueBall = referee.getCueBall();
}

void BallsManager::reset(Referee& referee)
{
	// reset and init maybe the same
}

void BallsManager::Update(Table& table)
{
	// Update each ball
    cueBall.Update();
	for (std::vector<Ball>::iterator iter = ballsList.begin(); iter != ballsList.end(); ++iter)
	{
		iter->Update();
	}

    // detect collision
    if (table.collidesWith(cueBall))
    {
    	// change speed or sth else

    }
    for (unsigned i = 0; i < ballsList.size(); ++i)
    {
    	// first detect cue ball
		if (cueBall.collidesWith(ballsList[i]))
		{
			// change speed or sth else

		}

		// and then detect the balls with table
		if (table.collidesWith(ballsList[i]))
		{
			// change speed or sth else

		}

		// finally detect other ball
    	for (unsigned j = i + 1; j < ballsList.size(); ++j)
    	{
    		if (ballsList[i].collidesWith(ballsList[j]))
    		{
    			// change speed or sth else

    		}
    	}
    }

}

void BallsManager::Draw(QPainter& painter)
{
	for (std::vector<Ball>::iterator iter = ballsList.begin(); iter != ballsList.end(); ++iter)
	{
		// Draw each ball here;
		iter->Draw(painter);
	}
    cueBall.Draw(painter);
}

Ball& BallsManager::getCueBall()
{
	return cueBall;
}
