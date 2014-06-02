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
    picSize.setXY(1280, 720);
    size.setXY(1200, 640);
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
}

// collision detection
bool Table::collidesWith(Ball& b)
{
	// detect collision here
    QRect R1(position.getX()+b.getRadius(),position.getY()+b.getRadius(),size.getX()-2*b.getRadius(),size.getY()-2*b.getRadius());
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    R1.setCoords(position.getX(),position.getY(),position.getX()+40,position.getY()+40);
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    R1.setCoords(position.getX(),position.getY()+size.getY()-40,position.getX()+40,position.getY()+size.getY());
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    R1.setCoords(position.getX()+size.getX()-40,position.getY(),position.getX()+size.getX(),position.getY()+40);
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    R1.setCoords(position.getX()+size.getX()-40,position.getY()+size.getY()-40,position.getX()+size.getX(),position.getY()+size.getY());
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    R1.setCoords(position.getX()+size.getX()/2-40,position.getY(),position.getX()+size.getX()/2+40,position.getY()+40);
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    R1.setCoords(position.getX()+size.getX()/2-40,position.getY()+size.getY()-40,position.getX()+size.getX()/2+40,position.getY()+size.getY());
    if(R1.contains(b.getPosition().getX(),b.getPosition().getY(),false))
        return false;

    return true;
	// 
    //return false;
}
