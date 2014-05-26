// Copyright (C) 2014 Team306

#include "Game.h"

Game::Game()
{
	// initialize in init method
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
}

void Game::Update()
{
	// update
	table.Update();
	ballsManager.Update();
}

void Game::Draw(QPainter& painter)
{
	// draw all thing 
    table.Draw(painter);
    ballsManager.Draw(painter);
}
