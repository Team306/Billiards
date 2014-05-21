#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTimer>
#include <QVBoxLayout>
#include "renderarea.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

private:
    RenderArea *renderArea;
    QVBoxLayout *mainLayout;
    QTimer *timer;
};

#endif // WINDOW_H
