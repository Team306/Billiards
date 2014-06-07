// Copyright (C) 2014 Team306

#include <fstream>
#include "Referee.h"

Referee::Referee()
{

}

Referee::~Referee()
{
}

void Referee::init()
{
	// read config file
	std::ifstream fin;
	fin.open("config.txt");
	std::string str;
	while (fin >> str)
	{
		if (str == "ballRadius")
		{
			break;
		}
	}
	fin >> ballRadius;
	fin.close();
}

void Referee::chooseRule(std::string ruleName)
{
	// change state machine
}

std::vector<Ball> Referee::getBallsList() const
{
	// use rule here
	// read the file get config info
	std::ifstream fin;
	fin.open("config.txt");
	std::string str;
	while (fin >> str)
	{
		if (str == "ballsList")
		{
			break;
		}
	}
	int number;
	fin >> number;
	std::vector<Ball> ballsList;
	for (int i = 0; i < number; ++i)
	{
		float x, y;
		int R, G, B;
		std::string name;
		fin >> x;
		fin >> y;
		fin >> R;
		fin >> G;
		fin >> B;
		fin >> name;
		Ball ball = Ball(Vector2(x, y), ballRadius);
		ball.setColor(QColor(R, G, B));
		ball.setName(name);
		ballsList.push_back(ball);
	}
	fin.close();
	return ballsList;
}

Ball Referee::getCueBall() const
{
	// read config file
	std::ifstream fin;
	fin.open("config.txt");
	std::string str;
	while (fin >> str)
	{
		if (str == "cueBall")
		{
			break;
		}
	}
	float x, y;
	int R, G, B;
	fin >> x;
	fin >> y;
	fin >> R;
	fin >> G;
	fin >> B;
	fin.close();
	Ball cueBall(Vector2(x, y), ballRadius);
	cueBall.setColor(QColor(R, G, B));
	cueBall.setName("cueBall");
	return cueBall;
}

float Referee::getBallRadius() const
{
	return ballRadius;
}
