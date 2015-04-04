//
// Lib_NCurses.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Mar 26 17:59:37 2015 Sebastien Cache-Delanos
// Last update Sat Apr  4 14:31:31 2015 Sebastien Cache-Delanos
//

#ifndef			LIB_NCURSES_HPP_
# define		LIB_NCURSES_HPP_

# include		<iostream>
# include		<ncurses/curses.h>
# include		"ILibrary.hpp"
# include		"Game.hpp"

# define	SPACE	32
# define	ESC	27

class			NCurses : public ILibrary
{
public:
  NCurses();
  NCurses(const NCurses& other);
  virtual		~NCurses();
  NCurses		&operator=(const NCurses& other);

  virtual void		init(int x, int y);
  virtual void		display(const data &d);
  virtual void		quit();
  virtual Event		eventHandler();
  virtual int		gameOver();
  virtual Event		pause();
  virtual void		muteGame();

private:
  void			initColors() const;
  WINDOW*		createWin(int height, int width, int starty, int startx);

  WINDOW*		_win;
  int			_score;
  int			_w;
  int			_h;
  bool			_muted;
};

#endif			//LIB_NCURSES_HPP_
