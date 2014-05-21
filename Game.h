// Copyright (C) 2014 Team306

#ifndef GAME_H
#define GAME_H 


#include <QPainter>

// control all logic in this class
// such as initialize a new game
// change game state, etc.
// in a Game must have a cue and a ballsManager
class Game
{
public:
	Game();
	~Game();

	void init(); // do all init here

	// update and draw
	void Update();
	void Draw(QPainter &);
	
};


#endif
