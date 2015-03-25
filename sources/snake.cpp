//
// snake.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:11 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 16:16:39 2015 Sebastien Cache-Delanos
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
