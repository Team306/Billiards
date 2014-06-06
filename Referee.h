// Copyright (C) 2014 Team306

#ifndef REFEREE_H
#define REFEREE_H 


#include <string>
#include <vector>
#include "Ball.h"

// define rule in it
// maybe can use embedded scripts to implement
class Referee
{
private:
	// in referee is a state machine, log the game state
	float ballRadius;

public:
	Referee();
	~Referee();

	// init method
	void init();
<<<<<<< HEAD
	void chooseRule(std::string ruleName);
=======
    void chooseRule(std::string ruleName);
>>>>>>> 240c69d4f8b75e53fe7893ee5916735db7ad69d5

	// get rule
	std::vector<Ball> getBallsList() const;
	Ball getCueBall() const;
	float getBallRadius() const;

	
};


#endif
