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

	painter.setBrush(QBrush(QColor(0, 255, 0)));
	painter.drawRect(QRectF(position.getX(), position.getY(), size.getX(), size.getY()));
}

// collision detection
bool Table::collidesWith(Ball& b)
{
	// detect collision here

	// 
	return false;
}
