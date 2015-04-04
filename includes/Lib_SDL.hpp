//
// lib_SDL.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:33:04 2015 Jordan Chazottes
// Last update Sat Apr  4 15:22:36 2015 Jordan Chazottes
//

#ifndef			LIB_SDL_HPP_
# define		LIB_SDL_HPP_

# include		<iostream>
# include		<SDL/SDL.h>
# include		<SDL/SDL_image.h>
# include		<SDL/SDL_ttf.h>
# include		<SDL/SDL_mixer.h>
# include		<sstream>
# include		<stdexcept>
# include		"ILibrary.hpp"
# include		"Game.hpp"

class			SDL : public ILibrary
{
public:
  SDL();
  SDL(const SDL& other);
  virtual		~SDL();
  SDL&			operator=(const SDL& other);
  virtual void		init(int, int);
  virtual void		display(const data &d);
  virtual void		quit();
  virtual Event		eventHandler();
  virtual int	       	gameOver();
  virtual Event		pause();
  virtual void		muteGame();

private:
  typedef struct	snakeSprite
  {
    SDL_Rect		head[8];
    SDL_Rect		tail[16];
  }			snakeSprite;

  void			setScore(int);
  void			setBoost(int) const;
  void			setSnake(std::vector<snk>) const;
  void			initAudio();
  void			initScore();
  void			initSprites();
  void			initSnakeSprites(snakeSprite*) const;
  void			initSnakeSpritesHead(snakeSprite*) const;
  void			initSnakeSpritesTail(snakeSprite*) const;
  int			checkRestart() const;
  void			resetBackground(int**, int, int) const;
  void			applySurface(int, int, SDL_Surface*, SDL_Rect*) const;

  TTF_Font*		_font;

  SDL_Surface*		_screen;
  SDL_Surface*		_bg;
  SDL_Surface*		_snake;
  SDL_Surface*		_tail;

  Mix_Music*		_music;

  Mix_Chunk*		_point;
  Mix_Chunk*		_klaxon;
  Mix_Chunk*		_gameOver;
  Mix_Chunk*		_pause;

  int			_width;
  int			_height;
  int			_curScore;
};

#endif			//LIB_SDL_HPP_
