//
// nibbler.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Mon Mar 23 15:48:25 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 18:19:36 2015 Jordan Chazottes
//

#include			"nibbler.hpp"
#include			"snake.hpp"
#include			"ILibrary.hpp"

int				nibbler(unsigned int width, unsigned int height, void *lib)
{
  Snake				*s = new Snake(width, height, lib);
  ILibrary			*(*external_creator)();
  ILibrary			*SDL;

  external_creator = reinterpret_cast<ILibrary* (*)()>(dlsym(lib, "createLib"));
  SDL = external_creator();
  if (external_creator == NULL)
    std::cout << "Problem loading external function" << std::endl;

  SDL->desc();

  std::cout << "Width : " << s->getWidth() << " Height : " << s->getHeight() << std::endl;

  delete s;
  return (0);
}
