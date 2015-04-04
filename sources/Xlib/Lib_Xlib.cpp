//
// Lib_Xlib.cpp for  in /home/charie_p/rendu/cpp_nibbler/sources
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Thu Apr  2 17:08:53 2015 Pierre Charié
// Last update Sat Apr  4 15:29:06 2015 Pierre Charié
//

#include	<sstream>
#include        <stdexcept>

#include	"Lib_Xlib.hpp"

extern "C"
{
  ILibrary *createLib()
  {
    return new Xlib();
  }
}

Xlib::Xlib() throw()
{
}

Xlib::Xlib(Xlib const &other) throw()
{
  _width = other._width;
  _height = other._height;
  _disp = other._disp;
  _win = other._win;
  _report = other._report;
  _colormap = other._colormap;
  _gcGround = other._gcGround;
  _gcWall = other._gcWall;
  _gcObst = other._gcObst;
  _gcHead = other._gcHead;
  _gcBody = other._gcBody;
  _gcTail = other._gcTail;
  _gcApple = other._gcApple;
  _colGround = other._colGround;
  _colWall = other._colWall;
  _colObst = other._colObst;
  _colHead = other._colHead;
  _colBody = other._colBody;
  _colTail = other._colTail;
  _colApple = other._colApple;
  _oldScore = other._oldScore;
}

Xlib &Xlib::operator=(const Xlib &other) throw()
{
  _width = other._width;
  _height = other._height;
  _disp = other._disp;
  _win = other._win;
  _report = other._report;
  _colormap = other._colormap;
  _gcGround = other._gcGround;
  _gcWall = other._gcWall;
  _gcObst = other._gcObst;
  _gcHead = other._gcHead;
  _gcBody = other._gcBody;
  _gcTail = other._gcTail;
  _gcApple = other._gcApple;
  _colGround = other._colGround;
  _colWall = other._colWall;
  _colObst = other._colObst;
  _colHead = other._colHead;
  _colBody = other._colBody;
  _colTail = other._colTail;
  _colApple = other._colApple;
  _oldScore = other._oldScore;
  return (*this);
}

Xlib::~Xlib() throw()
{
}

void		Xlib::setColor()
{
  int	err = 0;

  _gcGround = XCreateGC(_disp, _win, 0, 0);
  _gcWall = XCreateGC(_disp, _win, 0, 0);
  _gcObst = XCreateGC(_disp, _win, 0, 0);
  _gcHead = XCreateGC(_disp, _win, 0, 0);
  _gcBody = XCreateGC(_disp, _win, 0, 0);
  _gcTail = XCreateGC(_disp, _win, 0, 0);
  _gcApple = XCreateGC(_disp, _win, 0, 0);

  if (XParseColor(_disp, _colormap, "yellow green", &_colGround) == 0)
    err++;
  if (XParseColor(_disp, _colormap, "rgb:0/0/0", &_colWall) == 0)
    err++;
  if (XParseColor(_disp, _colormap, "rgb:AB/AB/AB", &_colObst) == 0)
    err++;
  if ( XParseColor(_disp, _colormap, "rgb:FF/00/FA", &_colHead) == 0)
    err++;
  if (XParseColor(_disp, _colormap, "rgb:FA/BA/0", &_colBody) == 0)
    err++;
  if (XParseColor(_disp, _colormap, "rgb:FC/FA/0", &_colTail) == 0)
    err++;
  if (XParseColor(_disp, _colormap, "rgb:FF/0/0", &_colApple) == 0)
    err++;
  if (err > 0)
    throw std::runtime_error("Error : can't load color");

  if (XAllocColor(_disp, _colormap, &_colGround) == 0)
    err++;
  if (XAllocColor(_disp, _colormap, &_colWall) == 0)
    err++;
  if (XAllocColor(_disp, _colormap, &_colObst) == 0)
    err++;
  if (XAllocColor(_disp, _colormap, &_colHead) == 0)
    err++;
  if (XAllocColor(_disp, _colormap, &_colBody) == 0)
    err++;
  if (XAllocColor(_disp, _colormap, &_colTail) == 0)
    err++;
  if (XAllocColor(_disp, _colormap, &_colApple) == 0)
    err++;

  if (err > 0)
    throw std::runtime_error("Error : can't allocate color");

  XSetForeground(_disp, _gcGround, _colGround.pixel);
  XSetForeground(_disp, _gcWall, _colWall.pixel);
  XSetForeground(_disp, _gcObst, _colObst.pixel);
  XSetForeground(_disp, _gcHead, _colHead.pixel);
  XSetForeground(_disp, _gcBody, _colBody.pixel);
  XSetForeground(_disp, _gcTail, _colTail.pixel);
  XSetForeground(_disp, _gcApple, _colApple.pixel);
}

void		Xlib::init(int const x, int const y)
{
  int		blackColor;
  XColor	bgcol;

  _height = y;
  _width = x;
  _disp = XOpenDisplay(NULL);
  _oldScore = -1;
  blackColor = BlackPixel(_disp, DefaultScreen(_disp));
  _colormap = DefaultColormap(_disp, 0);
  if (XParseColor(_disp, _colormap, "yellow green", &bgcol) == 0)
    throw std::runtime_error("Error : can't load color");
  if (XAllocColor(_disp, _colormap, &bgcol) == 0)
    throw std::runtime_error("Error : can't allocate color");
  _win = XCreateSimpleWindow(_disp, RootWindow(_disp, 0), 0, 0, _width * PIXSIZE,
				  _height * PIXSIZE, 0, blackColor, bgcol.pixel);
  XSelectInput(_disp, _win, ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask);
  XMapWindow(_disp, _win);
  this->setColor();
  while (42)
    {
      XEvent e;
      XNextEvent(_disp, &e);
      if (e.type == MapNotify)
      	break;
    }
}

void            Xlib::display(const data &d) throw()
{
  std::ostringstream oss;

  for (int y = 0; y < _height; y++)
    for (int x = 0; x < _width; x++)
      {
	switch (d.map[y][x])
	  {
	  case EMPTY:
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE, _gcGround);
	    break;
	  case WALL:
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE, _gcWall);
	    break;
	  case HEAD:
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE, _gcHead);
	    break;
	  case BODY:
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE, _gcBody);
	    break;
	  case TAIL:
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE, _gcTail);
	    break;
	  case APPLE:
	    this->draw_rect((x * PIXSIZE), (y * PIXSIZE), _gcApple);
	    break;
	  case OBSTACLE:
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE, _gcObst);
	    break;
	  default:
	    break;
	  }
      }
  XSync(_disp, false);
  oss << "Score : " << d.score << "             Boost " << d.boost * 10;
  XDrawString(_disp, _win, _gcObst, 10, 9, oss.str().c_str(), strlen(oss.str().c_str()));
  _oldScore = d.score;
  XSync(_disp, false);
}

void		Xlib::draw_rect(int const x1, int const y1, GC const &color)
{
  XDrawRectangle(_disp, _win, color, x1, y1, PIXSIZE, PIXSIZE);
  XFillRectangle(_disp, _win, color, x1, y1, PIXSIZE, PIXSIZE);
}

Event	Xlib::pause()
{
  while (42)
    {
      XEvent e;
      XNextEvent(_disp, &e);
      if (e.type == KeyPress)
      	break;
    }
  return (UNKNOWN);
}

Event	Xlib::eventHandler()
{
  _report.type = Expose;
  XCheckWindowEvent(_disp, _win, KeyPressMask, &_report);
    switch (_report.type)
      {
      case Expose :
	break;
      case KeyPress:
	switch (XLookupKeysym(&_report.xkey, 0))
	  {
	  case XK_Escape :
	    return QUIT;
	  case XK_Left :
	    return ARROW_LEFT;
	  case XK_Right :
	    return ARROW_RIGHT;
	  case XK_space :
	    return BOOST;
	  case XK_z:
	    return Z_UP;
	  case XK_q:
	    return Q_LEFT;
	  case XK_s:
	    return S_DOWN;
	  case XK_d:
	    return D_RIGHT;
	  case XK_p:
	    this->pause();
	  default:
	    return DEFAULT;
	  case XK_F1:
	    return (L_SDL);
	    break;
	  case XK_F3:
	    return (L_NCURSES);
	    break;
	  }
      default:
	return DEFAULT;
      }
  return DEFAULT;
}


void		Xlib::quit()
{
  XUnmapWindow(_disp, _win);
  XDestroyWindow(_disp, _win);
  XCloseDisplay(_disp);
}


int		Xlib::gameOver()
{
  std::string buffer = "Game Over !";
  std::string buffer2 = "Press ";
  std::string buffer3 = "\"r\" to try again";
  std::string buffer4 = "or \"q\" to leave";

  XDrawString(_disp, _win, _gcWall, 30, 50, " ", 1);
  XDrawString(_disp, _win, _gcWall, _width * PIXSIZE / 2 - 10, _height * PIXSIZE / 2 - 55 + 50, buffer.c_str(), strlen(buffer.c_str()));
  usleep(1000);
  XDrawString(_disp, _win, _gcWall, _width * PIXSIZE / 2 - 10, _height * PIXSIZE / 2 - 55 + 70, buffer2.c_str(), strlen(buffer2.c_str()));
  usleep(1000);
  XDrawString(_disp, _win, _gcWall, _width * PIXSIZE / 2 - 10, _height * PIXSIZE / 2 - 55 + 90, buffer3.c_str(), strlen(buffer3.c_str()));
  XDrawString(_disp, _win, _gcWall, _width * PIXSIZE / 2 - 10, _height * PIXSIZE / 2 - 55 + 110, buffer4.c_str(), strlen(buffer3.c_str()));
  XFlush(_disp);
  while (42)
    {
      XEvent e;
      XNextEvent(_disp, &e);
      if (e.type == KeyPress)
	{
	  if (XLookupKeysym(&e.xkey, 0)  == XK_r)
	    {
	      XUnmapWindow(_disp, _win);
	      XDestroyWindow(_disp, _win);
	      XCloseDisplay(_disp);
	      return 1;
	    }
	  if (XLookupKeysym(&e.xkey, 0)  == XK_q)
	    break;
	}
    }
  XFlush(_disp);
  return (0);
}

void		Xlib::muteGame() throw()
{

}
