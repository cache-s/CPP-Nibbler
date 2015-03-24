//
// nibbler.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Mon Mar 23 15:48:25 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 14:43:41 2015 Jordan Chazottes
//

#include			"nibbler.hpp"
#include			"snake.hpp"

int				nibbler(unsigned int width, unsigned int height, void *lib)
{
  Snake				*s = new Snake(width, height, lib);

  std::cout << "Width : " << s->getWidth() << " Height : " << s->getHeight() << std::endl;

  delete s;
  return (0);
}
