// Copyright (C) 2014 Team306

#include "BallsManager.h"

BallsManager::BallsManager()
{
    Ball ball(Vector2(50, 50), Vector2(5, 3), 30);
    ballsList.push_back(ball);
    Ball ball1(Vector2(1000, 500), Vector2(-2, -4), 30);
    ballsList.push_back(ball1);
}

BallsManager::~BallsManager()
{
}

void BallsManager::init()
{

}

void BallsManager::reset()
{

}

void BallsManager::Update()
{
	for (std::vector<Ball>::iterator iter = ballsList.begin(); iter != ballsList.end(); ++iter)
	{
		// Update each ball here;
		iter->Update();
	}
}

void BallsManager::Draw(QPainter& painter)
{
	for (std::vector<Ball>::iterator iter = ballsList.begin(); iter != ballsList.end(); ++iter)
	{
		// Draw each ball here;
		iter->Draw(painter);
	}
}
