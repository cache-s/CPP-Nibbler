#ifndef GROUND_H
#define GROUND_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QTime>
#include <QString>

class snakeField : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Direction)
public:

    explicit snakeField(QWidget *parent = 0);
    void     display(int **map, int width, int height);

signals:
    void snakeLength(int length);
    void snakeRound(int round);
    void quit();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void paintMap();

private:
    bool paused;
    bool isOver;
    bool allowDirectionChange;
    int height;
    int width;
    int **map;
};

#endif // GROUND_H

