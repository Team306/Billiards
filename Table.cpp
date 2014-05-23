// Copyright (C) 2014 Team306

#include "Table.h"

Table::Table(Vector2 position, Vector2 size, Vector2 picPosition, Vector2 picSize)
	: position(position), size(size), picPosition(picPosition), picSize(picSize)
{
}

Table::~Table()
{
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

	painter.drawRect(QRectF(position.getX(), position.getY(), size.getX(), size.getX()));
}

// collision detection
bool Table::collidesWith(Ball& b)
{
	// detect collision here

	// 
	return false;
}
