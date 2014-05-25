// Copyright (C) 2014 Team306

#ifndef GAME_H
#define GAME_H 


#include <QPainter>
#include "BallsManager.h"
#include "Table.h"

// control all logic in this class
// such as initialize a new game
// change game state, etc.
// in a Game must have a cue and a ballsManager
class Game
{
private:
	BallsManager ballsManager;
	Table table;
	// Cue cue;
	// Player player1;
	// Player player2;
	// Referee referee; 

	// other like Game state
	// GameState gameState;

public:
	Game();
	~Game();

	void init(); // do all init here

	// update and draw
	void Update();
	void Draw(QPainter &);
	
};


#endif
