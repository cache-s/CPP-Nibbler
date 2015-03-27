//
// lib_SDL.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:33:04 2015 Jordan Chazottes
// Last update Fri Mar 27 11:35:23 2015 Sebastien Cache-Delanos
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
  virtual void	init(int, int);
  virtual void	display(int**, int, int);
  void		resetBackground(int**, int, int);
  void		setSnake(int **, int, int);
  void		applySurface(int, int, SDL_Surface*, SDL_Rect*);
  virtual void	quit();
  virtual void	desc();
  virtual int	eventHandler();
private:
  SDL_Surface*	_screen;
};

#endif			//LIB_SDL_HPP_
