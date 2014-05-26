// Copyright (C) 2014 Team306

#include "Referee.h"

Referee::Referee()
{

}

Referee::~Referee()
{
}

void Referee::init()
{
	// read file or use lua script
	ballRadius = 30;
}

void Referee::chooseRule(std::string ruleName)
{
	// change state machine
}

std::vector<Ball> Referee::getBallsList() const
{
	// use rule here

	// just for test
	QColor kagamine_iro(255, 252, 0);
	std::vector<Ball> ballsList;
	
	Ball ball = Ball(Vector2(150, 150), ballRadius);
	ball.setColor(QColor(kagamine_iro));
	ballsList.push_back(ball);
	
	ball = Ball(Vector2(130, 490), ballRadius);
	ball.setColor(QColor(kagamine_iro));
	ballsList.push_back(ball);
	
	ball = Ball(Vector2(530, 590), ballRadius);
	ball.setColor(QColor(kagamine_iro));
	ballsList.push_back(ball);
	
	ball = Ball(Vector2(330, 290), ballRadius);
	ball.setColor(QColor(kagamine_iro));
	ballsList.push_back(ball);
	
	ball = Ball(Vector2(930, 470), ballRadius);
	ball.setColor(QColor(kagamine_iro));
	ballsList.push_back(ball);

	return ballsList;
}

Ball Referee::getCueBall() const
{
	Ball cueBall(Vector2(500, 500), ballRadius);
	cueBall.setName("cueBall");
	cueBall.setColor(QColor(255, 0, 255));

	return cueBall;
}

float Referee::getBallRadius() const
{
	return ballRadius;
}
