//
// snake.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:11 2015 Sebastien Cache-Delanos
// Last update Thu Mar 26 12:25:21 2015 Sebastien Cache-Delanos
//

#include			"snake.hpp"

Snake::Snake(int x, int y)
{
  X = x;
  Y = y;
}

Snake::~Snake()
{

}

Direction			Snake::getDir()
{
  Direction			tmp;

  tmp = _dir[0];
  _dir.pop_front();
  return (tmp);
}

void				Snake::addDir(Direction dir)
{
  _dir.push_back(dir);
}

void				Snake::addDirFront(Direction dir)
{
  _dir.push_front(dir);
}

//SETTERS
void				Snake::setX(int x)
{
  X = x;
}

void				Snake::setY(int y)
{
  Y = y;
}

void				Snake::setDirection(std::deque<Direction> dir)
{
  _dir = dir;
}

//GETTERS
int				Snake::getX() const
{
  return (X);
}

int				Snake::getY() const
{
  return (Y);
}

std::deque<Direction>		Snake::getDirection() const
{
  return (_dir);
}
