//
// Lib_Xlib.hpp for  in /home/charie_p/rendu/cpp_nibbler
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Thu Apr  2 16:59:04 2015 Pierre Charié
// Last update Sat Apr  4 16:58:09 2015 Sebastien Cache-Delanos
//

#ifndef			LIB_XLIB_HPP_
# define		LIB_XLIB_HPP_

# define		PIXSIZE 20

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

  virtual void		init(const int, const int);
  virtual void		display(const Data&);
  virtual void		quit();
  virtual Event		eventHandler();
  virtual int		gameOver();
  virtual void		muteGame();
  virtual Event		pause();

private:
  void			setColor();
  void			draw_rect(const int, const int, const GC&) const;
  int			_width;
  int			_height;
  int			_oldScore;

  Display		*_disp;
  Window		_win;
  XEvent		_report;

  Colormap		_colormap;
  GC			_gcGround;
  GC			_gcWall;
  GC			_gcObst;
  GC			_gcHead;
  GC			_gcBody;
  GC			_gcTail;
  GC			_gcApple;
  XColor		_colGround;
  XColor		_colWall;
  XColor		_colObst;
  XColor		_colHead;
  XColor		_colBody;
  XColor		_colTail;
  XColor		_colApple;
};

#endif			//LIB_XLIB_HPP_
