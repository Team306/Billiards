// Copyright (C) 2014 Team306

#include "Game.h"
#include <iostream>

Game::Game()
{
	// initialize in init method
	// gameState = FREE_BALL;
	gameState = START_FRAME;
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
            {
                ballsManager.getCueBall().setPosition(mousePosition);
            }
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
        case START_FRAME:
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
        case START_FRAME:
            QColor gray(100, 100, 100, 200);
            painter.setPen(gray);

            QFont font("Consolas", 100, 100, false);
            painter.setFont(font);
            
            painter.drawText(QRectF(108, 88, 1000, 250), "Billiards");

        	QColor miku_blue(00, 174, 255);
        	painter.setPen(miku_blue);

        	painter.drawText(QRectF(100, 80, 1000, 250), "Billiards");

            if (QRect(420, 300, 350, 50).contains(mousePosition.getX(), mousePosition.getY(), false))
            {
                font.setPointSize(50);
                font.setWeight(50);
                painter.setFont(font);
                painter.drawText(QRectF(360, 280, 500, 100), "Practice Mode");
            }
            else
            {
                font.setPointSize(30);
                font.setWeight(30);            
                painter.setFont(font);
                painter.drawText(QRectF(420, 300, 350, 50), "Practice Mode");
            }
            
            if (QRect(420, 400, 350, 50).contains(mousePosition.getX(), mousePosition.getY(), false))
            {
                font.setPointSize(50);
                font.setWeight(50);
                painter.setFont(font);
                painter.drawText(QRectF(360, 380, 500, 100), "Versus Mode");
            }
            else
            {
                font.setPointSize(30);
                font.setWeight(30);            
                painter.setFont(font);
                painter.drawText(QRectF(420, 400, 350, 50), "Versus Mode");
            }
            
            if (QRect(420, 500, 350, 50).contains(mousePosition.getX(), mousePosition.getY(), false))
            {
                font.setPointSize(50);
                font.setWeight(50);
                painter.setFont(font);
                painter.drawText(QRectF(360, 480, 500, 100), "Network Mode");
            }
            else
            {
                font.setPointSize(30);
                font.setWeight(30);            
                painter.setFont(font);
                painter.drawText(QRectF(420, 500, 350, 50), "Network Mode");
            }

            font.setPointSize(12);
            painter.setFont(font);
            painter.drawText(QRectF(800, 600, 250, 25), "Copyright (C) 2014 Team306");
        	break;
    }

    // debug info
    QFont font;
    painter.setFont(font);
    painter.drawText(QRectF(420, 600, 250, 25), "mouse press elapsed time");
    painter.drawText(QRectF(580, 600, 50, 25), QString::number(elapsedTime));
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
        case START_FRAME:
        	// decide game mode
            if (QRect(420, 300, 350, 50).contains(mousePosition.getX(), mousePosition.getY(), false))
            {
                gameState = FREE_BALL;
                gameMode = PRACTICE_MODE;
            }
            if (QRect(420, 400, 350, 50).contains(mousePosition.getX(), mousePosition.getY(), false))
            {
                gameState = FREE_BALL;
                gameMode = VERSUS_MODE;
            }
            if (QRect(420, 500, 350, 50).contains(mousePosition.getX(), mousePosition.getY(), false))
            {
                gameState = FREE_BALL;
                gameMode = NETWORK_MODE;
            }
        	break;
	}
}

GAME_STATE Game::getGameState() const
{
	return gameState;
}
