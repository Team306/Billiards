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
    R1.setCoords(position.getX() + 40, position.getY(), position.getX() + size.getX() / 2 - 40,
                 position.getY() + referee.getBallRadius());

    R2.setCoords(position.getX() + size.getX() / 2 + 40, position.getY(), position.getX() + size.getX() - 40,
                 position.getY() + referee.getBallRadius());

    R3.setCoords(position.getX() + 40, position.getY() + size.getY() - referee.getBallRadius(),
                 position.getX() + size.getX() / 2 - 40, position.getY() + size.getY());

    R4.setCoords(position.getX() + size.getX() / 2  +40, position.getY() + size.getY() - referee.getBallRadius(),
                 position.getX() + size.getX() - 40,position.getY() + size.getY());

    R5.setCoords(position.getX(), position.getY() + 40, position.getX() + referee.getBallRadius(),
                 position.getY() + size.getY() - 40);

    R6.setCoords(position.getX() + size.getX() - referee.getBallRadius(), position.getY() + 40,
                 position.getX() + size.getX(),position.getY() + size.getY() - 40);
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
    painter.drawRect(R6);*/
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
