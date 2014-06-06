// Copyright (C) 2014 Team306

#include "Game.h"

Game::Game()
{
	// initialize in init method
	// gameState = FREE_BALL;
	gameState = START_FRAME;
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
	ballsManager.Update(table, referee);

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
        	QColor miku_blue(00, 174, 255);
        	painter.setPen(miku_blue);

        	QFont font("Consolas", 100, 100, false);
        	painter.setFont(font);

        	painter.drawText(QRectF(100, 100, 1000, 250), "Billiards");
        	break;
    }

    // debug info
    QFont font;
    painter.setFont(font);
    painter.drawText(QRectF(420, 535, 250, 25), "mouse press elapsed time");
    painter.drawText(QRectF(580, 535, 50, 25), QString::number(elapsedTime));
}

void Game::setMousePosition(Vector2 position)
{
	mousePosition = position;
	// change text size below
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
        	gameState = FREE_BALL;
        	break;
	}
}

GAME_STATE Game::getGameState() const
{
	return gameState;
}
