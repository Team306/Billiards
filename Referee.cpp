// Copyright (C) 2014 Team306

#include <fstream>
#include "Referee.h"

Referee::Referee()
{
    scoreToadd = 0;
}

Referee::~Referee()
{
}


void Referee::init(int gameRule)
{
	// read config file
    gameRule = (GAME_RULE)gameRule;
    std::ifstream fin;
    switch(gameRule){
        case EIGHT_BALL:
            fin.open("config.txt");
            break;

        case NINE_BALL:
            fin.open("config1.txt");
            break;

        case SNOOKER:
            fin.open("config2.txt");
            break;

        default:
            fin.open("config.txt");
            break;
     }
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

//void Referee::chooseRule(std::string ruleName)
//{
	// change state machine
//}

std::vector<Ball> Referee::getBallsList() const
{
	// use rule here
	// read the file get config info
	std::ifstream fin;
    switch(game_rule){
        case EIGHT_BALL:
            fin.open("config.txt");
            break;

        case NINE_BALL:
            fin.open("config1.txt");
            break;

        case SNOOKER:
            fin.open("config2.txt");
            break;

        default:
            fin.open("config.txt");
            break;
     }
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
    switch(game_rule){
        case EIGHT_BALL:
            fin.open("config.txt");
            break;

        case NINE_BALL:
            fin.open("config1.txt");
            break;

        case SNOOKER:
            fin.open("config2.txt");
            break;

        default:
            fin.open("config.txt");
            break;
     }
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

JUDGE_RESULT Referee::judge(Player *_currentplayer, std::vector<Ball> _ballslist){
    switch(game_rule){
        case EIGHT_BALL:
            if(_currentplayer->getCueball_in()){       //cueball in
                judge_rusult = TO_FREE_BALL;
                break;
            }
            if(_currentplayer->getBalltype() == SMALL && _currentplayer->getFirsthit() != "one" && _currentplayer->getFirsthit() != "two"
                    && _currentplayer->getFirsthit() != "three" && _currentplayer->getFirsthit() != "four" && _currentplayer->getFirsthit() != "five"
                    &&_currentplayer->getFirsthit() != "six" &&_currentplayer->getFirsthit() != "seven"){
                judge_rusult = TO_EXCHANGE;
                break;
            }
            if(_currentplayer->getBalltype() == SMALL && _currentplayer->getFirsthit() != "one" && _currentplayer->getFirsthit() != "two"
                    && _currentplayer->getFirsthit() != "three" && _currentplayer->getFirsthit() != "four" && _currentplayer->getFirsthit() != "five"
                    &&_currentplayer->getFirsthit() != "six" &&_currentplayer->getFirsthit() != "seven"){
                judge_rusult = TO_EXCHANGE;
                break;
            }

    }
}

int Referee::getScoreToadd() const{
    return scoreToadd;
}
