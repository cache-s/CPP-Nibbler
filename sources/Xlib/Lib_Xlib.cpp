//
// Lib_Xlib.cpp for  in /home/charie_p/rendu/cpp_nibbler/sources/Xlib
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Mon Mar 30 15:04:02 2015 Pierre Charié
// Last update Thu Apr  2 11:43:16 2015 Pierre Charié
//

#include	<sstream>

#include	"Lib_Xlib.hpp"

extern "C"
{
  ILibrary *createLib()
  {
    return new Xlib();
  }
}

Xlib::Xlib()
{
}

Xlib::Xlib(Xlib const &other)
{
  this->width = other.width;
  this->height = other.height;
  this->disp = other.disp;
  this->win = other.win;
  this->report = other.report;
  this->colormap = other.colormap;
  this->gcGround = other.gcGround;
  this->gcWall = other.gcWall;
  this->gcObst = other.gcObst;
  this->gcHead = other.gcHead;
  this->gcBody = other.gcBody;
  this->gcTail = other.gcTail;
  this->gcApple = other.gcApple;
  this->colGround = other.colGround;
  this->colWall = other.colWall;
  this->colObst = other.colObst;
  this->colHead = other.colHead;
  this->colBody = other.colBody;
  this->colTail = other.colTail;
  this->colApple = other.colApple;
}

Xlib &Xlib::operator=(const Xlib &other)
{
  this->width = other.width;
  this->height = other.height;
  this->disp = other.disp;
  this->win = other.win;
  this->report = other.report;
  this->colormap = other.colormap;
  this->gcGround = other.gcGround;
  this->gcWall = other.gcWall;
  this->gcObst = other.gcObst;
  this->gcHead = other.gcHead;
  this->gcBody = other.gcBody;
  this->gcTail = other.gcTail;
  this->gcApple = other.gcApple;
  this->colGround = other.colGround;
  this->colWall = other.colWall;
  this->colObst = other.colObst;
  this->colHead = other.colHead;
  this->colBody = other.colBody;
  this->colTail = other.colTail;
  this->colApple = other.colApple;
  return (*this);
}

Xlib::~Xlib()
{
}

void		Xlib::setColor()
{
  int	err = 0;

  this->gcGround = XCreateGC(this->disp, this->win, 0, 0);
  this->gcWall = XCreateGC(this->disp, this->win, 0, 0);
  this->gcObst = XCreateGC(this->disp, this->win, 0, 0);
  this->gcHead = XCreateGC(this->disp, this->win, 0, 0);
  this->gcBody = XCreateGC(this->disp, this->win, 0, 0);
  this->gcTail = XCreateGC(this->disp, this->win, 0, 0);
  this->gcApple = XCreateGC(this->disp, this->win, 0, 0);

  if (XParseColor(this->disp, this->colormap, "yellow green", &colGround) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:0/0/0", &colWall) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:AB/AB/AB", &colObst) == 0)
    err++;
  if ( XParseColor(this->disp, this->colormap, "rgb:FF/00/FA", &colHead) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:FA/BA/0", &colBody) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:FC/FA/0", &colTail) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:FF/0/0", &colApple) == 0)
    err++;

  XAllocColor(this->disp, this->colormap, &colGround);
  XAllocColor(this->disp, this->colormap, &colWall);
  XAllocColor(this->disp, this->colormap, &colObst);
  XAllocColor(this->disp, this->colormap, &colHead);
  XAllocColor(this->disp, this->colormap, &colBody);
  XAllocColor(this->disp, this->colormap, &colTail);
  XAllocColor(this->disp, this->colormap, &colApple);

  XSetForeground(this->disp, this->gcGround, this->colGround.pixel);
  XSetForeground(this->disp, this->gcWall, this->colWall.pixel);
  XSetForeground(this->disp, this->gcObst, this->colObst.pixel);
  XSetForeground(this->disp, this->gcHead, this->colHead.pixel);
  XSetForeground(this->disp, this->gcBody, this->colBody.pixel);
  XSetForeground(this->disp, this->gcTail, this->colTail.pixel);
  XSetForeground(this->disp, this->gcApple, this->colApple.pixel);
  if (err > 0)
    {
      std::cerr << "ERROR : can't load color" << std::endl;
      //TODO throw exception
    }
}

void		Xlib::init(int const x, int const y)
{


  this->height = y;
  this->width = x;
  this->disp = XOpenDisplay(NULL);

  int blackColor = BlackPixel(this->disp, DefaultScreen(this->disp));
  XColor bgcol;

  this->colormap = DefaultColormap(this->disp, 0);
  XParseColor(this->disp, this->colormap, "yellow green", &bgcol);
  XAllocColor(this->disp, this->colormap, &bgcol);

  this->win = XCreateSimpleWindow(this->disp, RootWindow(this->disp, 0), 0, 0, this->width * PIXSIZE,
				  this->height * PIXSIZE, 0, blackColor, bgcol.pixel);
  XSelectInput(this->disp, this->win, ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask);
  XMapWindow(this->disp, this->win);
  this->setColor();
  while (42)
    {
      XEvent e;
      XNextEvent(this->disp, &e);
      if (e.type == MapNotify)
      	break;
    }
  XFlush(this->disp);
}

void            Xlib::display(data const d)
{
  for (int y = 0; y < this->height; y++)
    for (int x = 0; x < this->width; x++)
      {
        switch (d.map[y][x])
          {
          case 0:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcGround);
	    break;
          case 1:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcWall);
	    break;
          case 2:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcHead);
	    break;
          case 3:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcBody);
	    break;
          case 4:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcTail);
	    break;
          case 5:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcApple);
	    break;
          case 6:
            this->draw_rect(x * PIXSIZE, y * PIXSIZE,
                            x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, this->gcObst);
	    break;
	  default:
	    break;
          }
      }

  std::ostringstream oss;

  oss << "Score : " << d.score;
  XDrawString(this->disp, this->win, this->gcObst, 10, 9, oss.str().c_str(), strlen(oss.str().c_str()));
  XFlush(this->disp);
}

void		Xlib::draw_rect(int const x1, int const y1, int const x2, int const y2, GC const &color)
{
  XDrawRectangle(this->disp, this->win, color, x1, y1, x2, y2);
  XFillRectangle(this->disp, this->win, color, x1, y1, x2, y2);
}

void		Xlib::waitPause()
{
  while (42)
    {
      XEvent e;
      XNextEvent(this->disp, &e);
      if (e.type == KeyPress)
      	break;
    }
}

int		Xlib::eventHandler()
{
  this->report.type = Expose;
  XCheckWindowEvent(this->disp, this->win, KeyPressMask, &this->report);
    switch (this->report.type)
      {
      case Expose :
	break;
      case KeyPress:
	switch (XLookupKeysym(&report.xkey, 0))
	  {
	  case XK_Escape :
	    return -1;
	  case XK_Left :
	    return 0;
	  case XK_Right :
	    return 1;
	  case XK_space :
	    return 6;
	  case XK_z:
	    return 2;
	  case XK_q:
	    return 3;
	  case XK_s:
	    return 4;
	  case XK_d:
	    return 5;
	  case XK_p:
	    this->waitPause();
	  default:
	    return 42;
	  }
      default:
	return 42;
      }
  return 42;
}


void		Xlib::quit()
{
  XUnmapWindow(this->disp, this->win);
  XDestroyWindow(this->disp, this->win);
  XCloseDisplay(this->disp);
}


int		Xlib::gameOver()
{
  std::string buffer = "Game Over !";
  std::string buffer2 = "Press ";
  std::string buffer3 = "\"r\" to try again";
  std::string buffer4 = "or \"q\" to leave";

  XDrawString(this->disp, this->win, this->gcWall, 30, 50, " ", 1);
  XDrawString(this->disp, this->win, this->gcWall, 30, 50, buffer.c_str(), strlen(buffer.c_str()));
  usleep(1000);
  XDrawString(this->disp, this->win, this->gcWall, 30, 70, buffer2.c_str(), strlen(buffer2.c_str()));
  usleep(1000);
  XDrawString(this->disp, this->win, this->gcWall, 30, 90, buffer3.c_str(), strlen(buffer3.c_str()));
  XDrawString(this->disp, this->win, this->gcWall, 30, 110, buffer4.c_str(), strlen(buffer3.c_str()));
  XFlush(this->disp);
  while (42)
    {
      XEvent e;
      XNextEvent(this->disp, &e);
      if (e.type == KeyPress)
	{
	  if (XLookupKeysym(&e.xkey, 0)  == XK_r)
	    {
	      XUnmapWindow(this->disp, this->win);
	      XDestroyWindow(this->disp, this->win);
	      XCloseDisplay(this->disp);
	      return 1;
	    }
	  if (XLookupKeysym(&e.xkey, 0)  == XK_q)
	    break;
	}
    }
  XFlush(this->disp);
  return (0);
}
