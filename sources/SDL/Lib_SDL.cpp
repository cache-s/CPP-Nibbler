//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Thu Mar 26 12:40:54 2015 Jordan Chazottes
//

#include	"Lib_SDL.hpp"

void		*SDL::init(int x, int y)
{
  SDL_Surface	*screen;

  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
      std::cout << "Error : Init SDL : " << SDL_GetError() << std::endl;
      return NULL;
    }
  TTF_Init();
  SDL_WM_SetCaption("Nibbler", "My Nibbler");
  screen = SDL_SetVideoMode(x*32, y*32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  return ((void*)screen);
}

void		SDL::display(void *screen, int **map, int w, int h)
{
  resetBackground(screen, map, w, h);
  setSnake(screen, map, w, h);
  SDL_Flip((SDL_Surface*)screen);
}

void		SDL::resetBackground(void *screen, int **map, int X, int Y)
{
  SDL_Surface	*bg;
  SDL_Rect	clip[4];

  if ((bg = IMG_Load("sources/SDL/sprites/env.png")) == NULL)
    std::cout << "Error loading Image" << std::endl;
  clip[0].x = clip[1].x = clip[2].x = clip[3].x = 0;
  clip[0].y = 0;
  clip[1].y = 32;
  clip[2].y = 64;
  clip[3].y = 96;
  clip[0].w = clip[1].w = clip[2].w = clip[3].w =
    clip[0].h = clip[1].h = clip[2].h = clip[3].h = 32;
  for (int y = 0; y < Y; y++)
    {
      for (int x = 0; x < X; x++)
	{
	  if (map[y][x] == 0)
	    applySurface(x*32, y*32, bg, screen, &clip[1]);
	  if (map[y][x] == 1)
	    applySurface(x*32, y*32, bg, screen, &clip[0]);
	  if (map[y][x] == 6)
	    applySurface(x*32, y*32, bg, screen, &clip[2]);
	  if (map[y][x] == 5)
	    applySurface(x*32, y*32, bg, screen, &clip[3]);
	}
    }
}

void		SDL::setSnake(void *screen, int **map, int X, int Y)
{
  SDL_Surface	*snake;
  SDL_Rect	clip[2];

  if ((snake = IMG_Load("sources/SDL/sprites/snake.png")) == NULL)
    std::cout << "Error loading Image" << std::endl;    
  clip[0].x = clip[1].x = 0;
  clip[0].y = 0;
  clip[1].x = 32;
  clip[0].w = clip[1].w = clip[0].h = clip[1].h = 32;
  for (int y = 0; y < Y; y++)
    {
      for (int x = 0; x < X; x++)
	{
	  if (map[y][x] == 2)
	    applySurface(x*32, y*32, snake, screen, &clip[0]);
	  if (map[y][x] == 3 || map[y][x] == 4)
	    applySurface(x*32, y*32, snake, screen, &clip[1]);
	}
    }
}

void		SDL::desc()
{
  std::cout << "Using SDL library !" << std::endl;
}

void		SDL::applySurface(int x, int y, SDL_Surface *src, void *screen, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, clip, (SDL_Surface*)screen, &offset);
}

extern "C"
{
  ILibrary *createLib()
  {
    return new SDL();
  }
}

// void		SDL::quit(void *screen)
// {
//   SDL_FreeSurface((SDL_Surface*)screen);
//   TTF_Quit();
//   SDL_Quit();
// }
