
#include "qtsnake.h"

int QtSnake::init(int height, int width)
{
    int argc;
    char **argv;


    QApplication app(argc, argv);

    QtSnake snake;
    snake.show();
    return app.exec();
}
