// Copyright (C) 2014 Team306

#include "Game.h"

Game::Game()
{
	// initialize in init method
	// gameState = WAIT_FOR_STROKE;
	gameState = FREE_BALL;
	// gameState = BALL_IS_RUNNING;
	elapsedTime = 0;
}

Game::~Game()
{
}

void Game::init()
{
	// init here
    referee.init();
    table.init(referee);
	ballsManager.init(referee);
	cue.init(referee);
}

void Game::Update()
{
	// update
	cue.Update(gameState, mousePosition);
	ballsManager.Update(table);

	switch (gameState)
	{
		case FREE_BALL:
			// check before set position
			ballsManager.getCueBall().setPosition(mousePosition);
			// chech if the position is legal
			// if the position is illegal 
			// just put the cue ball in the center of the kitchen(free ball area)
			// use TABLE method
			break;
		case BALL_IS_RUNNING:
			if (!ballsManager.isRunning())
			{
				gameState = WAIT_FOR_STROKE;
			}
			break;
	}
}

void Game::Draw(QPainter& painter)
{
	// draw all thing 
    table.Draw(painter);
    ballsManager.Draw(painter);

    // only display the cue when gameState == wait for stroke
    switch (gameState)
    {
    	case WAIT_FOR_STROKE:
    		cue.Draw(painter, ballsManager.getCueBall());
    		break;
    }

    // debug info
    painter.drawText(QRectF(420, 535, 250, 25), "mouse press elapsed time");
    painter.drawText(QRectF(580, 535, 50, 25), QString::number(elapsedTime));
}

void Game::setMousePosition(Vector2 position)
{
	mousePosition = position;
}

void Game::mousePress(int elapsed)
{
	// use in debug
	elapsedTime = elapsed;
	// do else thing
	switch (gameState)
	{
		case FREE_BALL:
			gameState = WAIT_FOR_STROKE;
			break;
		case WAIT_FOR_STROKE:
			gameState = BALL_IS_RUNNING;
			cue.Stroke(elapsed, ballsManager.getCueBall());
			break;
	}
}

GAME_STATE Game::getGameState() const
{
	return gameState;
}
