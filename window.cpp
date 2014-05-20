#include "window.h"

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Billiards by Team306"));
}

Window::~Window()
{

}
