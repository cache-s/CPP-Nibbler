//
// Lib_NCurses.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Mar 26 17:59:37 2015 Sebastien Cache-Delanos
// Last update Fri Mar 27 14:47:01 2015 Sebastien Cache-Delanos
//

#ifndef			LIB_NCURSES_HPP_
# define		LIB_NCURSES_HPP_

# include		<iostream>
# include		<ncurses/curses.h>
# include		"ILibrary.hpp"
# include		"game.hpp"

class			NCurses : public ILibrary
{
public:
  NCurses();
  ~NCurses();

  virtual void		init(int x, int y);
  virtual void		display(int** map, int w, int h, int score);
  virtual void		desc();
  virtual void		quit();
  virtual int		eventHandler();

  WINDOW*		createWin(int height, int width, int starty, int startx);
private:
  WINDOW*		_win;
  int			_score;
};

#endif			//LIB_NCURSES_HPP_
