//
// snake.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:11 2015 Sebastien Cache-Delanos
// Last update Sat Apr  4 16:51:03 2015 Jordan Chazottes
//

#include			"Snake.hpp"

Snake::Snake(int x, int y)
{
  _x = x;
  _y = y;
}

Snake::~Snake()
{

}

void				Snake::addDir(Direction dir)
{
  _dir.push_back(dir);
}

void				Snake::addDirFront(Direction dir)
{
  _dir.push_front(dir);
}

void				Snake::popDir()
{
  _dir.pop_front();
}

//SETTERS
void				Snake::setX(int x)
{
  _x = x;
}

void				Snake::setY(int y)
{
  _y = y;
}

void				Snake::setDirection(const std::deque<Direction> &dir)
{
  _dir = dir;
}

//GETTERS
int				Snake::getX() const
{
  return (_x);
}

int				Snake::getY() const
{
  return (_y);
}

const std::deque<Direction>	&Snake::getDirection() const
{
  return (_dir);
}

Direction			Snake::getDir() const
{
  return (_dir[0]);
}
