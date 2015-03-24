//
// snake.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Tue Mar 24 11:29:36 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 15:02:48 2015 Jordan Chazottes
//

#include				"snake.hpp"

Snake::Snake(unsigned int width, unsigned int height, void *lib)
{
  std::cout << "Snake class instance created" << std::endl;
  _width = width;
  _height = height;
  _lib = lib;
}

Snake::~Snake()
{
  std::cout << "Snake class instance destroyed" << std::endl;
}

unsigned int				Snake::getHeight() const
{
  return (_height);
}

unsigned int				Snake::getWidth() const
{
  return (_width);
}

void					*Snake::getLib() const
{
  return (_lib);
}
