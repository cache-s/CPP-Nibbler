//
// lib_SDL.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:33:04 2015 Jordan Chazottes
// Last update Fri Apr  3 10:30:24 2015 Jordan Chazottes
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
# include		"Game.hpp"

class SDL : public ILibrary
{
public:

  virtual void	init(int, int);
  virtual void	display(const data &d);
  virtual void	quit();
  virtual Event	eventHandler();
  virtual int	gameOver();
  virtual Event	pause();
  virtual void	muteGame();

private:
  typedef struct	snakeSprite
  {
    SDL_Rect		head[8];
    SDL_Rect		tail[16];
  }			snakeSprite;
  void		resetBackground(int**, int, int);
  void		setSnake(std::vector<snk> snake);
  void		applySurface(int, int, SDL_Surface*, SDL_Rect*);
  void		setScore(int);
  int		checkRestart();
  void		setBoost(int);
  void		initSprites();
  void		initAudio();
  void		initScore();
  void		initSnakeSprites(snakeSprite*);
  void		initSnakeSpritesHead(snakeSprite*);
  void		initSnakeSpritesTail(snakeSprite*);
  TTF_Font	*_font;
  SDL_Surface*	_screen;
  SDL_Surface*	_bg;
  SDL_Surface*	_snake;
  SDL_Surface*	_tail;
  Mix_Music*	_music;
  Mix_Chunk*	_point;
  Mix_Chunk*	_klaxon;
  Mix_Chunk*	_gameOver;
  Mix_Chunk*	_pause;
  int		_width;
  int		_height;
  int		_curScore;
};

#endif			//LIB_SDL_HPP_
