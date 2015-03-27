//
// Lib_NCurses.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler/sources/NCurses
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Mar 26 17:56:48 2015 Sebastien Cache-Delanos
// Last update Fri Mar 27 11:36:10 2015 Sebastien Cache-Delanos
//

#include	"Lib_NCurses.hpp"

NCurses::NCurses()
{
}

NCurses::~NCurses()
{
}

WINDOW*		NCurses::createWin(int height, int width, int starty, int startx)
{
  _win = newwin(height, width, starty, startx);
  box(_win, 0 , 0);
  wrefresh(_win);
  return _win;
}

void		NCurses::init(int x, int y)
{
  int startx, starty, width, height;

  initscr();
  cbreak();
  keypad(stdscr, TRUE);

  height = y + 2;
  width = x + 2;
  starty = 0;
  startx = 0;
  refresh();
  _win = createWin(height, width, starty, startx);
  wclear(_win);
  wrefresh(_win);
}

void		NCurses::display(int **map, int w, int h)
{
  int		i;
  int		j;

  wclear(_win);
  for (i = 0; i < h; ++i)
    {
      for (j = 0; j < w; ++j)
	wprintw(_win, "%d", map[i][j]);
      wprintw(_win, "\n");
    }
  wrefresh(_win);
}

int		NCurses::eventHandler()
{
  return (42);
}

void		NCurses::desc()
{
  std::cout << "Using NCurses library !" << std::endl;
}

void		NCurses::quit()
{
  wborder(_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(_win);
  delwin(_win);
  endwin();
}

extern "C"
{
  ILibrary *createLib()
  {
    return new NCurses();
  }
}
