// Copyright (C) 2014 Team306

#include "Game.h"

Game::Game()
	:table(Vector2(10, 10), Vector2(1000, 700), Vector2(0, 0), Vector2(1000, 700))
{
	// initialize in init method
}

Game::~Game()
{
}

void Game::init()
{
	// init here
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
