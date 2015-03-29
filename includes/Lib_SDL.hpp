//
// lib_SDL.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:33:04 2015 Jordan Chazottes
// Last update Sun Mar 29 17:50:19 2015 Jordan Chazottes
//

#ifndef			LIB_SDL_HPP_
# define		LIB_SDL_HPP_

# include		<iostream>
# include		<SDL/SDL.h>
# include		<SDL/SDL_image.h>
# include		<SDL/SDL_ttf.h>
# include		<SDL/SDL_mixer.h>
# include		<sstream>
# include		"ILibrary.hpp"
# include		"game.hpp"

class SDL : public ILibrary
{
public:
  virtual void	init(int, int);
  virtual void	display(int**, int);
  virtual void	quit();
  virtual void	desc();
  virtual int	eventHandler();
  void		resetBackground(int**, int, int);
  void		setSnake(int **, int, int);
  void		applySurface(int, int, SDL_Surface*, SDL_Rect*);
  void		setScore(int);
  void		initSprites();
  void		initAudio();
private:
  TTF_Font	*_font;
  SDL_Surface*	_screen;
  SDL_Surface*	_bg;
  SDL_Surface*	_snake;
  Mix_Music*	_music;
  Mix_Chunk*	_point;
  int		_width;
  int		_height;
  int		_curScore;
};

#endif			//LIB_SDL_HPP_
