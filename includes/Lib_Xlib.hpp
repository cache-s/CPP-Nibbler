//
// Lib_Xlib.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Apr  2 12:50:51 2015 Sebastien Cache-Delanos
// Last update Thu Apr  2 12:53:53 2015 Sebastien Cache-Delanos
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
  virtual int	pause();

  void		setColor();
  void          draw_rect(const int, const int, const int, const int, const GC&);

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
