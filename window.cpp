#include "window.h"
#include "renderarea.h"
#include <QVBoxLayout>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Billiards by Team306"));

    RenderArea *renderArea = new RenderArea;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(renderArea);
    setLayout(mainLayout);

    QPalette bgpal = palette();
    bgpal.setColor(QPalette::Background, QColor(0, 0, 0, 255));
    setPalette(bgpal);
}

Window::~Window()
{

}
