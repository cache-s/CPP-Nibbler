//
// snake.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:11 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 18:21:01 2015 Sebastien Cache-Delanos
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

//SETTERS
void				Snake::setX(int x)
{
  X = x;
}

void				Snake::setY(int y)
{
  Y = y;
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
