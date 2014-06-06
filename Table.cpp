// Copyright (C) 2014 Team306

#include "Table.h"

Table::Table()
{
}

Table::~Table()
{
}

void Table::init(Referee& referee)
{
	// init method
    picPosition.setXY(0, 0);
    position.setXY(40, 40);
    picSize.setXY(1240, 720);
    size.setXY(1160, 640);
    pocketRadius = 40;

    p1.setXY(position.getX() + size.getX(), position.getY());
    p2.setXY(position.getX(), position.getY() + size.getY());
    p3.setXY(position.getX() + size.getX(), position.getY() + size.getY());

    //R1 to R6 is used to detect crash
    R1.setCoords(position.getX() + 35, position.getY(), position.getX() + size.getX() / 2 - 35,
                 position.getY() + referee.getBallRadius());//topleft

    R2.setCoords(position.getX() + size.getX() / 2 + 35, position.getY(), position.getX() + size.getX() - 35,
                 position.getY() + referee.getBallRadius());//topright

    R3.setCoords(position.getX() + 35, position.getY() + size.getY() - referee.getBallRadius(),
                 position.getX() + size.getX() / 2 - 35, position.getY() + size.getY());//bottomleft

    R4.setCoords(position.getX() + size.getX() / 2  + 35, position.getY() + size.getY() - referee.getBallRadius(),
                 position.getX() + size.getX() - 35,position.getY() + size.getY());//bottomright

    R5.setCoords(position.getX(), position.getY() + 35, position.getX() + referee.getBallRadius(),
                 position.getY() + size.getY() - 35);//left

    R6.setCoords(position.getX() + size.getX() - referee.getBallRadius(), position.getY() + 35,
                 position.getX() + size.getX(),position.getY() + size.getY() - 35);//right
    //R7 to R8 middle pocket
    R7.setCoords(position.getX() + size.getX() / 2 - 30,position.getY() - referee.getBallRadius(),
                 position.getX() + size.getX() / 2 + 30,position.getY());

    R8.setCoords(position.getX() + size.getX() / 2 - 30,position.getY() + size.getY(),
                 position.getX() + size.getX() / 2 + 30,position.getY() + size.getY() + referee.getBallRadius());
}

Vector2 Table::getSize() const
{
	return size;
}

// update and draw
void Table::Update()
{
	// update here
}

void Table::Draw(QPainter& painter)
{
	// draw here
    QColor blue_iro(66, 204, 255);
    painter.setBrush(QBrush(blue_iro));
    painter.setPen(QPen(QColor(0, 0, 255)));
	painter.drawRect(QRectF(picPosition.getX(), picPosition.getY(), picSize.getX(), picSize.getY()));

    painter.setPen(QPen(QColor(0, 0, 0)));
    painter.setBrush(QBrush(QColor(0,0,0)));
    painter.drawEllipse(QPoint(position.getX(), position.getY()),40,40);
    painter.drawEllipse(QPoint(position.getX()+size.getX(), position.getY()),40,40);
    painter.drawEllipse(QPoint(position.getX(), position.getY()+size.getY()),40,40);
    painter.drawEllipse(QPoint(position.getX()+size.getX(), position.getY()+size.getY()),40,40);
    painter.drawEllipse(QPoint(picPosition.getX()+picSize.getX()/2, picPosition.getY()+40),40,40);
    painter.drawEllipse(QPoint(picPosition.getX()+picSize.getX()/2, picPosition.getY()+size.getY()+40),40,40);

    painter.setPen(QPen(QColor(0, 0, 255)));
    painter.setBrush(QBrush(QColor(0, 255, 0)));
    painter.drawRoundRect(QRectF(position.getX(), position.getY(), size.getX(), size.getY()),7,14);

    painter.setPen(QPen(QColor(255,255,255)));
    painter.drawLine(position.getX()+300,position.getY(),position.getX()+300,position.getY()+size.getY());
    //test
    /*painter.setBrush(QBrush(QColor(100,100,100)));
    painter.drawRect(R1);
    painter.drawRect(R2);
    painter.drawRect(R3);
    painter.drawRect(R4);
    painter.drawRect(R5);
    painter.drawRect(R6);
    painter.drawRect(R7);
    painter.drawRect(R8);*/
}

// collision detection
bool Table::collidesWith(Ball& b)
{
	// detect collision here
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
    {
        b.setSpeed(Vector2(b.getSpeed().getX(),0 - b.getSpeed().getY()));
        return true;
    }

    if(R2.contains(b.getPosition().getX(),b.getPosition().getY(),false))
    {
        b.setSpeed(Vector2(b.getSpeed().getX(),0 - b.getSpeed().getY()));
        return true;
    }

    if(R3.contains(b.getPosition().getX(),b.getPosition().getY(),false))
    {
        b.setSpeed(Vector2(b.getSpeed().getX(),0 - b.getSpeed().getY()));
        return true;
    }

    if(R4.contains(b.getPosition().getX(),b.getPosition().getY(),false))
    {
        b.setSpeed(Vector2(b.getSpeed().getX(),0 - b.getSpeed().getY()));
        return true;
    }

    if(R5.contains(b.getPosition().getX(),b.getPosition().getY(),false))
    {
        b.setSpeed(Vector2(0 - b.getSpeed().getX(), b.getSpeed().getY()));
        return true;
    }

    if(R6.contains(b.getPosition().getX(),b.getPosition().getY(),false))
    {
        b.setSpeed(Vector2(0 - b.getSpeed().getX(), b.getSpeed().getY()));
        return true;
    }

    return false;
}

bool Table::positionIsLegal(Vector2 p,Referee &referee)
{
    QRect R(position.getX() + referee.getBallRadius(), position.getY() + referee.getBallRadius(),
            300 - 2 * referee.getBallRadius(),size.getY() - 2 * referee.getBallRadius());
    if(R.contains(p.getX(), p.getY(),true))
        return true;
    return false;
}

bool Table::checkPockets(Ball& ball)
{
    // if the ball is in the pocket return true;
    if(R7.contains(ball.getPosition().getX(), ball.getPosition().getY(), false)||
            R6.contains(ball.getPosition().getX(), ball.getPosition().getY(), false))
        return true;

    if((ball.getPosition().distanceBetween(position) <= 0.705 * pocketRadius )||
            (ball.getPosition().distanceBetween(p1) <= 0.705 * pocketRadius )||
            (ball.getPosition().distanceBetween(p2) <= 0.705 * pocketRadius )||
            (ball.getPosition().distanceBetween(p3) <= 0.705 * pocketRadius ))
        return true;
    return false;
}
