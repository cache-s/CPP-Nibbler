#include "ground.h"
#include <unistd.h>

snakeField::snakeField(QWidget *parent) :
    QWidget(parent)
{

    setPalette(QPalette(QColor(220, 250, 200)));
    setAutoFillBackground(true);
    this->setFixedSize(640,480);
    //this->display(NULL, 0, 0);
}

void    snakeField::display(int **map, int width, int height)
{
    this->map = map;
    this->width = width;
    this->height = height;
    QWidget::update();
}

void    snakeField::paintEvent(QPaintEvent *event)
{
    (void)event;
    int x = 0;
    int y = 0;
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    while (y < this->height)
    {
        while (x  < this->width)
        {
            switch (this->map[x][y]){
                case 0:
                    break;
                case 1: //mur
                    painter.setBrush(Qt::black);
                    break;
                case 2: //tête
                    painter.setBrush(Qt::blue);
                    break;
                case 3: //corps
                    painter.setBrush(Qt::cyan);
                    break;
                case 4: //queue
                    painter.setBrush(Qt::darkCyan);
                    break;
                case 5: //pomme
                    painter.setBrush(Qt::green);
                    break;
                case 6: //obstacle
                    painter.setBrush(Qt::darkGray);
                    break;
            }
            QRect rectSnake(y*20,x*20,20,20);
            painter.drawRect(rectSnake);

            x++;
        }
     x = 0;
     y++;
    }
}

void snakeField::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
            //setDirection(0);
            break;
        case Qt::Key_Right:
            //setDirection(1);
            break;
        case Qt::Key_Q:
    //        setDirection(0);
            break;
        case Qt::Key_D:
    //        setDirection(1);
            break;
        case Qt::Key_4:
    //        setDirection(0);
        case Qt::Key_6:
    //        setDirection(1);
            break;
        case Qt::Key_P:
    //        paused=!paused;
            break;
        case Qt::Key_R:
    //        retry();
            break;
        case Qt::Key_Escape:
    //        emit quit();
            break;
    //case Qt::Key_D:
    //    changeNextLevel();
        break;
    }}
