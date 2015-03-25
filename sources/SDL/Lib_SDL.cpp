//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Wed Mar 25 11:52:12 2015 Jordan Chazottes
//

#include	"Lib_SDL.hpp"

// void		SDL::init()
// {
//   if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
//     {
//       std::cout << "Error : Init SDL : " << SDL_GetError() << std::endl;
//       return;
//     }
//   TTF_Init();
//   SDL_putenv("SDL_VIDEODRIVER=directx");
// }

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
