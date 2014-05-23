#include <QPainter>
#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{
    // init game
    game.init();
}

void RenderArea::MainLoop()
{
    // Main loop
    game.Update();
    // call Qt redraw a frame
    update();
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // draw a frame
    game.Draw(painter);
}

