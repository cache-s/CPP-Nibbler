//
// Lib_Xlib.cpp for  in /home/charie_p/rendu/cpp_nibbler/sources/Xlib
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Mon Mar 30 15:04:02 2015 Pierre Charié
// Last update Mon Mar 30 19:54:10 2015 Pierre Charié
//

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

Xlib::~Xlib()
{
}

void		Xlib::setColor()
{
  int	err = 0;

  this->gcGround = XCreateGC(this->disp, this->win, 0, 0);
  this->gcWall = XCreateGC(this->disp, this->win, 0, 0); //X ne retiens pas les couleurs de bases : stockage;
  this->gcObst = XCreateGC(this->disp, this->win, 0, 0);
  this->gcHead = XCreateGC(this->disp, this->win, 0, 0);
  this->gcBody = XCreateGC(this->disp, this->win, 0, 0);
  this->gcTail = XCreateGC(this->disp, this->win, 0, 0);
  this->gcApple = XCreateGC(this->disp, this->win, 0, 0);

  if (XParseColor(this->disp, this->colormap, "rgb:0/255/0", &colGround) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:0/0/0", &colWall) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:144/144/144", &colObst) == 0)
    err++;
  if ( XParseColor(this->disp, this->colormap, "rgb:255/0/0", &colHead) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:200/100/0", &colBody) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:255/200/0", &colTail) == 0)
    err++;
  if (XParseColor(this->disp, this->colormap, "rgb:255/0/0", &colApple) == 0)
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

void		Xlib::init(int x, int y)
{


  this->height = y;
  this->width = x;
  this->disp = XOpenDisplay(NULL);

  int blackColor = BlackPixel(this->disp, DefaultScreen(this->disp));
  int whiteColor = WhitePixel(this->disp, DefaultScreen(this->disp));
  (void)whiteColor;

  this->win = XCreateSimpleWindow(this->disp, RootWindow(this->disp, 0), 0, 0, this->width * PIXSIZE,
				  this->height * PIXSIZE, 0, blackColor, blackColor);
  this->colormap = DefaultColormap(disp, 0); //met la colormap par defaut (ecran, numero ecran)
  XSelectInput(this->disp, this->win, ExposureMask | KeyPressMask | ButtonPressMask | StructureNotifyMask); //grep les touches
  XMapWindow(this->disp, this->win);
  this->setColor();
  while (42) //on attend que la map soit prete. on boucle tant que le signal est pas le bon
    {
      XEvent e;
      XNextEvent(this->disp, &e);
      if (e.type == MapNotify)
      	break;
    }


  Atom wmDelete=XInternAtom(disp, "WM_DELETE_WINDOW", True);
  XSetWMProtocols(disp, win, &wmDelete, 1);
  //

  //

  //
  // XSetForeground(this->disp, this->gcGround, whiteColor);
  // XDrawLine(this->disp, this->win, this->gcApple, 10, 60, 180, 20);
  // XFlush(this->disp);
  //
  //
  // sleep(10);
}


void		Xlib::display(data d)
{
  (void)d;
  static int	i = 0;
  i += 10;
  for (int y = 0; y < this->height; y++)
    for (int x = 0; x < this->width; x++)
      {
        if (d.map[y][x] == 0)
	  this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			  x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcGround);
        if (d.map[y][x] == 1)
	  this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			  x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcWall);
	if (d.map[y][x] == 2)
	  {
	    this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			    x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcHead);
	    std::cout << "case = " << d.map[y][x] << std::endl;
	  }
	if (d.map[y][x] == 3)
	  this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			  x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcBody);
	if (d.map[y][x] == 4)
	  this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			  x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcTail);
	if (d.map[y][x] == 5)
	  this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			  x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcApple);
	if (d.map[y][x] == 6)
	  this->draw_rect(x * PIXSIZE, y * PIXSIZE,
			  x * PIXSIZE + PIXSIZE, y * PIXSIZE + PIXSIZE, gcObst);
      }
  XFlush(this->disp);
}

void		Xlib::draw_rect(int x1, int y1, int x2, int y2, GC color)
{
  XDrawRectangle(this->disp, this->win, color, x1, y1, x2, y2);
  XFillRectangle(this->disp, this->win, color, x1, y1, x2, y2);

}

int		Xlib::eventHandler()
{
  // while (1)
  //   {
  std::cout << "waitin...\n";
      XNextEvent(this->disp, &this->report);
  std::cout << "end!...\n";
      switch (report.type)
  	{
  	case ClientMessage:
  	  break; //TODO exception
  	case KeyPress:
	  std::cout << "case!\n";
	  if (report.type == KeyPress)
	    {
	      if (XLookupKeysym(&report.xkey, 0) == XK_Escape)
		break; //TODO fermeture
	      if (XLookupKeysym(&report.xkey, 0) == XK_Left)
		return 0;
	      if (XLookupKeysym(&report.xkey, 0) == XK_Right)
		return 1;
	      return 42;
	    }
	default:
	  return 42;
  	}
    //   break;
    // }
  return 42;
}


void		Xlib::desc()
{
  std::cout << "Using Xlib library !" << std::endl;
}

void		Xlib::quit()
{
}


int		Xlib::gameOver()
{
  return (0);
}
