// Copyright (C) 2014 Team306

#ifndef REFEREE_H
#define REFEREE_H 


#include <string>
#include <vector>

// define rule in it
// maybe can use embedded scripts to implement
class Referee
{
private:
	// in referee is a state machine, log the game state

public:
	Referee();
	~Referee();

	// init method
	void init();
	void chooseRule(std::string ruleName);

	// get rule
	
};


#endif
