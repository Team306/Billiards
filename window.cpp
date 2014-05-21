#include "window.h"

// lock fps in 60 fps
const int delay_time = 17;

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Billiards by Team306"));
    setFixedSize(1280, 720);

    // set renderArea
    renderArea = new RenderArea;
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(renderArea);
    setLayout(mainLayout);

    QPalette bgpal = palette();
    bgpal.setColor(QPalette::Background, QColor(0, 0, 0, 255));
    setPalette(bgpal);

    // set fps
    QTimer *timer = new QTimer(this);
    timer->start(delay_time);
    connect(timer, SIGNAL(timeout()), renderArea, SLOT(MainLoop()));
}

Window::~Window()
{

}
