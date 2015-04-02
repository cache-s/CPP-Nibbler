//
// Lib_Xlib.hpp for  in /home/charie_p/rendu/cpp_nibbler
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Thu Apr  2 11:29:01 2015 Pierre Charié
// Last update Thu Apr  2 12:16:03 2015 Pierre Charié
//

#ifndef			LIB_XLIB_HPP_
# define		LIB_XLIB_HPP_

# define		PIXSIZE 10

# include		<X11/Xlib.h>
# include		<X11/Xutil.h>
# include		<X11/Xos.h>
# include		<X11/Xatom.h>
# include		<X11/keysym.h>

# include		"ILibrary.hpp"
# include		"Game.hpp"

class Xlib : public ILibrary
{
public:
  Xlib();
  Xlib(Xlib const &);
  Xlib &operator=(const Xlib &);
  ~Xlib();


  virtual void	init(const int, const int);
  virtual void	display(const data);
  virtual void	quit();
  virtual int	eventHandler();
  virtual int	gameOver();

  void		setColor();
  void          draw_rect(const int, const int, const int, const int, const GC&);
  void		waitPause();

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
