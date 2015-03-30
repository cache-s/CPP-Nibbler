#ifndef QTSNAKE
#define QTSNAKE

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>

#include "ground.h"

class QtSnake : public QWidget
{
public:
    QtSnake(QWidget *parent = 0);
    int init(int height, int width);
};

#endif // QTSNAKE
