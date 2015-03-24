//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Tue Mar 24 15:43:20 2015 Jordan Chazottes
//

#include	"Lib_SDL.hpp"

void		SDL::desc() const
{
  std::cout << "Using SDL library !" << std::endl;
}

extern "C"
{
  ILibrary *createLib()
  {
    return new SDL();
  }
}
