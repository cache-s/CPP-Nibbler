//
// nibbler.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:38:54 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 12:39:19 2015 Sebastien Cache-Delanos
//

#include			"nibbler.hpp"
#include			"game.hpp"
#include			"ILibrary.hpp"

int				nibbler(unsigned int width, unsigned int height, void *lib)
{
  Game				*s = new Game(width, height, lib);

  /*
    ILibrary			*(*external_creator)();
    ILibrary			*SDL;

    external_creator = reinterpret_cast<ILibrary* (*)()>(dlsym(lib, "createLib"));
    SDL = external_creator();
    if (external_creator == NULL)
    std::cout << "Problem loading external function" << std::endl;
    SDL->desc();
    std::cout << "Width : " << s->getWidth() << " Height : " << s->getHeight() << std::endl;
  */

  delete s;
  return (0);
}
