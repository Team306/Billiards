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

void BallsManager::Update(Table& table, Referee& referee)
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

    	// test
        //cueBall.setSpeed(Vector2());
        // cueBall.setSpeed(Vector2());
    }
    for (unsigned i = 0; i < ballsList.size(); ++i)
    {
    	// first detect cue ball
		if (cueBall.collidesWith(ballsList[i]))
		{
			// change speed or sth else
			
			// test

            //cueBall.setSpeed(Vector2());

            // cueBall.setSpeed(Vector2());
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

    // after detect collision, check if the ball is into the pocket
    if (table.checkPockets(cueBall))
    {
    	// call the referee, and next turn game change to free ball
        // cueBall.setSpeed(Vector2((0 - cueBall.getSpeed().getX()), (0 - cueBall.getSpeed().getY())));
        cueBall.setSpeed(Vector2(0, 0));
    }
    for (unsigned i = 0; i < ballsList.size(); ++i)
    {
    	if (table.checkPockets(ballsList[i]))
    	{
    		// if ball is into the pocket, delete the ball
    		ballsList[i] = ballsList[ballsList.size() - 1];
    		ballsList.pop_back();
    		// call the referee

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

bool BallsManager::isRunning() const
{
	int flag = 0;
    for (unsigned i = 0; i < ballsList.size(); ++i)
	{
		if (ballsList[i].getBallState() == RUNNING)
		{
			flag = 1;
		}
	}
	if (cueBall.getBallState() == RUNNING)
	{
		flag = 1;
	}
	if (flag == 0)
	{
		return false;
	}
	return true;
}
