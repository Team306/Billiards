// Copyright (C) 2014 Team306

#include "Game.h"

Game::Game()
{
	// initialize in init method
	gameState = WAIT_FOR_STROKE;
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
	table.Update(); // is needed?
	ballsManager.Update(table);
}

void Game::Draw(QPainter& painter)
{
	// draw all thing 
    table.Draw(painter);
    ballsManager.Draw(painter);

    // only display the cue when gameState == wait for stroke
    if (gameState == WAIT_FOR_STROKE)
    {
    	cue.Draw(painter, mousePosition, ballsManager.getCueBall());
    }
}

void Game::setMousePosition(Vector2 position)
{
	mousePosition = position;
}
