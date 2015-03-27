//
// Lib_NCurses.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler/sources/NCurses
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Mar 26 17:56:48 2015 Sebastien Cache-Delanos
// Last update Fri Mar 27 15:34:45 2015 Sebastien Cache-Delanos
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
  curs_set(0);
  height = y + 2;
  width = x + 2;
  starty = 0;
  startx = 0;
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_GREEN);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  init_pair(3, COLOR_RED, COLOR_YELLOW);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(6, COLOR_RED, COLOR_GREEN);
  init_pair(7, COLOR_BLUE, COLOR_GREEN);
  refresh();
  _win = createWin(height, width, starty, startx);
  wclear(_win);
  wrefresh(_win);
}

void		NCurses::display(int **map, int w, int h, int score)
{
  int		i;
  int		j;

  _score = score;
  wclear(_win);
  wprintw(_win, "Score : %d\n", _score);
  for (i = 0; i < h; ++i)
    {
      for (j = 0; j < w; ++j)
	{
	  if (map[i][j] == 0)
	    waddch(_win, ACS_BLOCK | COLOR_PAIR(1));
	  else if (map[i][j] == 1)
	    waddch(_win, ACS_BLOCK | COLOR_PAIR(2));
	  else if (map[i][j] == 2)
	    waddch(_win, ACS_PI | A_BLINK | COLOR_PAIR(3));
	  else if (map[i][j] == 3 || map[i][j] == 4)
	    waddch(_win, ACS_BLOCK | COLOR_PAIR(5));
	  else if (map[i][j] == 5)
	    waddch(_win, ACS_DIAMOND | COLOR_PAIR(6));
	  else if (map[i][j] == 6)
	    waddch(_win, ACS_BOARD | A_BOLD | COLOR_PAIR(7));
	  else
	    wprintw(_win, "%d", map[i][j]);
	}
      wprintw(_win, "\n");
    }
  wrefresh(_win);
}

int		NCurses::eventHandler()
{
  int		ch;

  nodelay(stdscr, TRUE);
  if ((ch = getch()) == ERR)
    return (42);
  else
    {
      switch (ch)
	{
	case KEY_LEFT:
	  return (0);
	case KEY_RIGHT:
	  return (1);
	default:
	  return (42);
	}
    }
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
  curs_set(1);
  endwin();
}

extern "C"
{
  ILibrary *createLib()
  {
    return new NCurses();
  }
}
