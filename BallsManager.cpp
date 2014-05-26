// Copyright (C) 2014 Team306

#include "BallsManager.h"

BallsManager::BallsManager()
    : cueBall(Vector2(), Vector2(), 30)
{
    Ball ball(Vector2(50, 50), Vector2(5, 3), 30);
    ballsList.push_back(ball);
    Ball ball1(Vector2(1000, 500), Vector2(-2, -4), 30);
    ballsList.push_back(ball1);
}

BallsManager::~BallsManager()
{
}

void BallsManager::init(Referee& referee)
{
	// call referee for balls' info

}

void BallsManager::reset(Referee& referee)
{
	// reset and init maybe the same
}

void BallsManager::Update()
{
	for (std::vector<Ball>::iterator iter = ballsList.begin(); iter != ballsList.end(); ++iter)
	{
		// Update each ball here;
		iter->Update();
	}
    cueBall.Update();
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
