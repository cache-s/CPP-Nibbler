//
// Lib_NCurses.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler/sources/NCurses
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Thu Mar 26 17:56:48 2015 Sebastien Cache-Delanos
// Last update Thu Apr  2 16:51:26 2015 Sebastien Cache-Delanos
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

void		NCurses::initColors()
{
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_GREEN);
  init_pair(2, COLOR_WHITE, COLOR_WHITE);
  init_pair(3, COLOR_RED, COLOR_YELLOW);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  init_pair(5, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(6, COLOR_RED, COLOR_GREEN);
  init_pair(7, COLOR_BLUE, COLOR_GREEN);
  init_pair(8, COLOR_BLUE, COLOR_BLACK);
  init_pair(9, COLOR_WHITE, COLOR_BLACK);
  init_pair(10, COLOR_GREEN, COLOR_BLACK);
  init_pair(11, COLOR_RED, COLOR_BLACK);
}

void		NCurses::init(int x, int y)
{
  int startx, starty, width, height;

  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  _w = x;
  _h = y;
  _score = 0;
  height = y + 2;
  width = x + 2;
  starty = (LINES - height) / 2;
  startx = (COLS - width) / 2;
  initColors();
  refresh();
  _win = createWin(height, width, starty, startx);
  wclear(_win);
  wrefresh(_win);
}

void		NCurses::display(data d)
{
  int		i;
  int		j;

  if (d.score != _score)
    beep();
  _score = d.score;
  wclear(_win);
  wprintw(_win, "Score : %d\nBoost : ", _score);
  for (i = 0; i < 10; ++i)
    {
      if (d.boost-- > 0)
	waddch(_win, ACS_DIAMOND | COLOR_PAIR(8));
      else
	waddch(_win, ACS_DIAMOND | COLOR_PAIR(9));
    }
  wprintw(_win, "\n");
  for (i = 0; i < _h; ++i)
    {
      for (j = 0; j < _w; ++j)
	{
	  if (d.map[i][j] == 0)
	    waddch(_win, ACS_BLOCK | COLOR_PAIR(1));
	  else if (d.map[i][j] == 1)
	    waddch(_win, ACS_BLOCK | COLOR_PAIR(2));
	  else if (d.map[i][j] == 2)
	    waddch(_win, ACS_PI | A_BLINK | COLOR_PAIR(3));
	  else if (d.map[i][j] == 3 || d.map[i][j] == 4)
	    waddch(_win, ACS_BLOCK | COLOR_PAIR(5));
	  else if (d.map[i][j] == 5)
	    waddch(_win, ACS_DIAMOND | COLOR_PAIR(6));
	  else if (d.map[i][j] == 6)
	    waddch(_win, ACS_BOARD | A_BOLD | COLOR_PAIR(7));
	  else
	    wprintw(_win, "%d", d.map[i][j]);
	}
      wprintw(_win, "\n");
    }
  wrefresh(_win);
}

Game::Event	NCurses::eventHandler()
{
  int		ch;

  nodelay(stdscr, TRUE);
  if ((ch = getch()) == ERR)
    return (Game::DEFAULT);
  switch (ch)
    {
    case 27:
      return (Game::QUIT);
    case KEY_LEFT:
      return (Game::ARROW_LEFT);
    case KEY_RIGHT:
      return (Game::ARROW_RIGHT);
    case 'z':
    case 'Z':
      return (Game::Z_UP);
    case 'q':
    case 'Q':
      return (Game::Q_LEFT);
    case 's':
    case 'S':
      return (Game::S_DOWN);
    case 'd':
    case 'D':
      return (Game::D_RIGHT);
    case 'p':
    case 'P':
      return (Game::PAUSE);
    case 32:
      return (Game::BOOST);
    default:
      return (Game::DEFAULT);
    }
  return (Game::DEFAULT);
}

void		NCurses::quit()
{
  wborder(_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(_win);
  delwin(_win);
  curs_set(1);
  endwin();
}

int		NCurses::gameOver()
{
  int		ch;

  wclear(_win);
  wprintw(_win, "  Your score : %d\n\n", _score);
  waddch(_win, ACS_DIAMOND | COLOR_PAIR(10));
  wprintw(_win, " Press r to retry ");
  waddch(_win, ACS_DIAMOND | COLOR_PAIR(10));
  wprintw(_win, "\n");
  waddch(_win, ACS_DIAMOND | COLOR_PAIR(11));
  wprintw(_win, " Press q to quit  ");
  waddch(_win, ACS_DIAMOND | COLOR_PAIR(11));
  wrefresh(_win);
  nodelay(stdscr, FALSE);
  while (42)
    {
      if ((ch = getch()) == ERR)
	return (42);
      switch (ch)
	{
	case 'r':
	case 'R':
	  return (1);
	case 'q':
	case 'Q':
	  return (0);
	}
    }
  wrefresh(_win);
  return (0);
}

Game::Event	NCurses::pause()
{
  return (Game::UNKNOWN);
}

extern "C"
{
  ILibrary *createLib()
  {
    return new NCurses();
  }
}
