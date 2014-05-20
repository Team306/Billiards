#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{

}

// lock size in 1280 x 720
QSize RenderArea::sizeHint() const
{
    return QSize(1280, 720);
}
