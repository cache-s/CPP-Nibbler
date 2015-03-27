//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Fri Mar 27 11:33:26 2015 Sebastien Cache-Delanos
//

#include	"Lib_SDL.hpp"

void		SDL::init(int x, int y)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
      std::cout << "Error : Init SDL : " << SDL_GetError() << std::endl;
      return;
    }
  TTF_Init();
  SDL_WM_SetCaption("Nibbler", "My Nibbler");
  _screen = SDL_SetVideoMode(x*32, y*32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
}

void		SDL::display(int **map, int w, int h)
{
  resetBackground(map, w, h);
  setSnake(map, w, h);
  SDL_Flip(_screen);
}

void		SDL::resetBackground(int **map, int X, int Y)
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
	    applySurface(x*32, y*32, bg, &clip[1]);
	  if (map[y][x] == 1)
	    applySurface(x*32, y*32, bg, &clip[0]);
	  if (map[y][x] == 6)
	    applySurface(x*32, y*32, bg, &clip[2]);
	  if (map[y][x] == 5)
	    applySurface(x*32, y*32, bg, &clip[3]);
	  /*	  applySurface(x*32, y*32, bg, screen, &clip[0]);
	  if (map[y][x] == 1)
	    applySurface(x*32, y*32, bg, screen, &clip[3]);
	  if (map[y][x] == 6)
	    applySurface(x*32, y*32, bg, screen, &clip[1]);
	  if (map[y][x] == 5)
	    applySurface(x*32, y*32, bg, screen, &clip[2]);
	  */
	}
    }
}

void		SDL::setSnake(int **map, int X, int Y)
{
  SDL_Surface	*snake;
  SDL_Rect	clip[3];

  if ((snake = IMG_Load("sources/SDL/sprites/snake.png")) == NULL)
    {
      std::cout << "Error loading Image" << std::endl;
      exit(-1);
    }
  clip[0].x = clip[1].x = clip[2].x = 0;
  clip[0].y = 0;
  clip[1].y = 32;
  clip[2].y = 64;
  clip[0].w = clip[1].w = clip[2].w = clip[0].h = clip[1].h = clip[2].h = 32;
  for (int y = 0; y < Y; y++)
    {
      for (int x = 0; x < X; x++)
	{
	  if (map[y][x] == 2)
	    applySurface(x*32, y*32, snake, screen, &clip[0]);
	  if (map[y][x] == 3)
	    applySurface(x*32, y*32, snake, screen, &clip[1]);
	  if (map[y][x] == 4)
	    applySurface(x*32, y*32, snake, screen, &clip[2]);
	}
    }
}

void		SDL::desc()
{
  std::cout << "Using SDL library !" << std::endl;
}

void		SDL::applySurface(int x, int y, SDL_Surface *src, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, clip, _screen, &offset);
}

int		SDL::eventHandler()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return -1;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
	  return -1;
	case SDLK_RIGHT:
	  return 1;
	case SDLK_LEFT:
	  return 0;
	default:
	  return 42;
	}
    default:
      return 42;
    }
  return (42);
}

extern "C"
{
  ILibrary *createLib()
  {
    return new SDL();
  }
}

void		SDL::quit()
{
//   SDL_FreeSurface((SDL_Surface*)_screen);
//   TTF_Quit();
//   SDL_Quit();
}
