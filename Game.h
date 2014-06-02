// Copyright (C) 2014 Team306

#ifndef GAME_H
#define GAME_H 


#include <QPainter>
#include "BallsManager.h"
#include "Table.h"
#include "Cue.h"

// control all logic in this class
// such as initialize a new game
// change game state, etc.

enum GAME_STATE { WAIT_FOR_STROKE, FREE_BALL, BALL_IS_RUNNING };

class Game
{
private:
	BallsManager ballsManager;
	Table table;
	Referee referee;
	Cue cue;
	Vector2 mousePosition;
	// Player player1;
	// Player player2;

	// Game state
	GAME_STATE gameState;

	// debug variables
	int elapsedTime;

public:
	Game();
	~Game();

	void init(); // do all init here

	// update and draw
	void Update();
	void Draw(QPainter &);

	// deal with mouse event
	void setMousePosition(Vector2);
	void mousePress(int elapsed);

	GAME_STATE getGameState() const;
};


#endif
