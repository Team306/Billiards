// Copyright (C) 2014 Team306

#include "Game.h"
#include <iostream>

Game::Game()
{
	// initialize in init method
	// gameState = WAIT_FOR_STROKE;
	gameState = FREE_BALL;
	// gameState = BALL_IS_RUNNING;
	elapsedTime = 0;
    player1.init();
    player2.init();
    player1.setPlayerflag(LOCAL);
    player2.setPlayerflag(GUEST);
    current_player = &player1;
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
    ballsManager.Update(table, current_player);

    if(player1.getBalltype() == NOTDEF || player2.getBalltype() == NOTDEF){
        if(current_player->getBalltype() == SMALL){
            if(current_player->getPlayerflag() == LOCAL){
                player2.setBalltype(BIG);
            }
            else player1.setBalltype(BIG);
        }
        else{
            if(current_player->getBalltype() == BIG){
                if(current_player->getPlayerflag() == LOCAL){
                    player2.setBalltype(SMALL);
                }
                else player1.setBalltype(SMALL);
            }
        }
    }



	switch (gameState)
	{
		case FREE_BALL:
			// check before set position
            if(table.positionIsLegal(mousePosition,referee))
                ballsManager.getCueBall().setPosition(mousePosition);
			// chech if the position is legal
			// if the position is illegal 
			// just put the cue ball in the center of the kitchen(free ball area)
			// use TABLE method
			break;
		case BALL_IS_RUNNING:
			if (!ballsManager.isRunning())
			{
                if(current_player->getCueball_in()){
                    gameState = FREE_BALL;
                    if(current_player->getPlayerflag() == LOCAL){
                        current_player->update();
                        current_player = &player2;
                        break;
                    }
                    else{
                        current_player->update();
                        current_player = &player1;
                    }
                }
                gameState = WAIT_FOR_STROKE;
				// call the referee
			}
			break;
        case WAIT_FOR_STROKE:

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
        case FREE_BALL:
            break;
        case BALL_IS_RUNNING:
            break;
    }

    // debug info
    painter.drawText(QRectF(420, 535, 250, 25), "mouse press elapsed time");
    painter.drawText(QRectF(580, 535, 50, 25), QString::number(elapsedTime));
    painter.drawText(QRectF(200,535,100,100),QString::number(current_player->getPlayerflag()));
    //std::cout<<getPlayerflag()<<std::endl;
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
            cue.Stroke(elapsed, ballsManager.getCueBall());
            gameState = BALL_IS_RUNNING;
			break;
        case BALL_IS_RUNNING:
            break;
	}
}

GAME_STATE Game::getGameState() const
{
	return gameState;
}
