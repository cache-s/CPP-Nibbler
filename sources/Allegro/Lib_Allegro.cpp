//
// Lib_Allegro.cpp for  in /home/charie_p/rendu/cpp_nibbler/sources/Allegro
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Mon Mar 30 11:09:51 2015 Pierre Charié
// Last update Mon Mar 30 13:11:03 2015 Pierre Charié
//

#include "allegro5/Headers/allegro5/allegro.h"
#include "Lib_Allegro.hpp"

Aleg::Aleg()
{
}

Aleg::~Aleg()
{
}

void    Aleg::init(int w, int h)
{
  // if ((this->allib = dlopen("./includes/allegro5/liballegro.so.5.0.11", RTLD_LAZY)) == NULL)
  //   std::cout << "Error while opening the library vasygros!" << std::endl;
  std::cout << "ALLEGRO LOADED\n";
  (void)w;
  (void)h;
}

void	Aleg::display(int **map, int score, std::vector<int> boost)
{
  (void)map;
  (void)score;
  (void)boost;
}

void	Aleg::desc()
{
  std::cout << "Using Allegro library !" << std::endl;
}

void	Aleg::quit()
{

}

int	Aleg::gameOver()
{
  return (0);
}

extern "C"
{
  ILibrary *createLib()
  {
    return new Aleg();
  }
}
