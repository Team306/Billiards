#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "Game.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);

signals:

public slots:
    void MainLoop();

protected:
    void paintEvent(QPaintEvent *);

private:
    Game game;
};

#endif // RENDERAREA_H
