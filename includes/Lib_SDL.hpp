//
// lib_SDL.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:33:04 2015 Jordan Chazottes
// Last update Thu Mar 26 11:35:45 2015 Jordan Chazottes
//

#ifndef			LIB_SDL_HPP_
# define		LIB_SDL_HPP_

# include		<iostream>
# include		<SDL/SDL.h>
# include		<SDL/SDL_image.h>
# include		<SDL/SDL_ttf.h>
# include		"ILibrary.hpp"
# include		"game.hpp"

class SDL : public ILibrary
{
public:
  virtual void	*init(int, int);
  virtual void	display(void*, int**, int, int);
  void		resetBackground(void*, int**, int, int);
  void		setSnake(void*, int **, int, int);
  void		applySurface(int, int, SDL_Surface*, void*, SDL_Rect*);
  // void		quit(void*);
  virtual void desc();
private:
};

#endif			//LIB_SDL_HPP_
