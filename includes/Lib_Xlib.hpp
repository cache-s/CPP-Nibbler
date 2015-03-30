//
// lib_SDL.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
//
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
//
// Started on  Tue Mar 24 15:33:04 2015 Jordan Chazottes
// Last update Mon Mar 30 19:12:06 2015 Pierre Charié
//

#ifndef			LIB_XLIB_HPP_
# define		LIB_XLIB_HPP_

# define		PIXSIZE 10

# include		<X11/Xlib.h>
# include		<X11/Xutil.h>
# include		<X11/Xos.h>
# include		<X11/Xatom.h>
# include		<X11/keysym.h>

#include <unistd.h> //TODO delete pour sleep

# include		"ILibrary.hpp"
# include		"game.hpp"

class Xlib : public ILibrary
{
public:
  Xlib();
  ~Xlib();
  virtual void	init(int, int);
  virtual void	display(data);
  virtual void	quit();
  virtual void	desc();
  virtual int	eventHandler();
  virtual int	gameOver();

  void		draw_bg(int **);
  void		setColor();
  void          draw_rect(int, int, int, int, GC);

private:
  int		width;
  int		height;

  Display	*disp;
  Window	win;
  XEvent	report;
  Colormap	colormap;
  GC		gcGround;
  GC		gcWall;
  GC		gcObst;
  GC		gcHead;
  GC		gcBody;
  GC		gcTail;
  GC		gcApple;
  XColor	colGround;
  XColor	colWall;
  XColor	colObst;
  XColor	colHead;
  XColor	colBody;
  XColor	colTail;
  XColor	colApple;
};

#endif			//LIB_Xlib_HPP_