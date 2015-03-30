//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Mon Mar 30 15:59:13 2015 Sebastien Cache-Delanos
//

#include	"Lib_SDL.hpp"

extern "C"
{
  ILibrary *createLib()
  {
    return new SDL();
  }
}

void		SDL::init(int x, int y)
{
  _width = x;
  _height = y;
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
      std::cout << "Error : Init SDL : " << SDL_GetError() << std::endl;
      return;
    }
  SDL_WM_SetCaption("Nibbler", "My Nibbler");
  _screen = SDL_SetVideoMode(x*32, y*32 + 32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  TTF_Init();
  initAudio();
  initSprites();
  initScore();
}

void		SDL::initScore()
{
  if ((_font = TTF_OpenFont("ressources/fonts/FKV.ttf", 20)) == NULL)
    std::cout << "Error loading Font FKV" << std::endl;
  _curScore = 0;
  setScore(0);
}

void		SDL::initSprites()
{
  if ((_bg = IMG_Load("ressources/sprites/env.png")) == NULL)
    std::cout << "Error loading Image Env" << std::endl;
  if ((_snake = IMG_Load("ressources/sprites/snake2.png")) == NULL)
    std::cout << "Error loading Image Snake" << std::endl;
}

void		SDL::initAudio()
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    std::cout << "Error loading music mixer" << std::endl;
  _music = Mix_LoadMUS("ressources/sounds/nyan.wav");
  _point = Mix_LoadWAV("ressources/sounds/point.wav");
  Mix_VolumeMusic(MIX_MAX_VOLUME/2);
  Mix_PlayMusic(_music, -1);
  Mix_AllocateChannels(2);
}

void		SDL::display(data d)
{
  resetBackground(d.map, _width, _height);
  setSnake(d.map, _width, _height);
  setScore(d.score);
  SDL_Flip(_screen);
}

void		SDL::resetBackground(int **map, int X, int Y)
{
  SDL_Rect	clip[4];
  SDL_Surface	*overlay;
  SDL_Rect	tmp;

  tmp.x = 0;
  tmp.y = 0;
  clip[0].x = clip[1].x = clip[2].x = clip[3].x = 0;
  clip[0].y = 0;
  clip[1].y = 32;
  clip[2].y = 64;
  clip[3].y = 96;
  clip[0].w = clip[1].w = clip[2].w = clip[3].w =
    clip[0].h = clip[1].h = clip[2].h = clip[3].h = 32;

  overlay = SDL_CreateRGBSurface(SDL_HWSURFACE, X*32, 32, 32, 0, 0, 0, 0);
  SDL_FillRect(overlay, NULL, SDL_MapRGB(_screen->format, 128, 128, 128));
  SDL_BlitSurface(overlay, NULL, _screen, &tmp);

  for (int y = 0; y < Y; y++)
    for (int x = 0; x < X; x++)
      {
	applySurface(x*32, y*32 + 32, _bg, &clip[0]);
	if (map[y][x] == 1)
	  applySurface(x*32, y*32 + 32, _bg, &clip[3]);
	if (map[y][x] == 6)
	  applySurface(x*32, y*32 + 32, _bg, &clip[1]);
	  if (map[y][x] == 5)
	    applySurface(x*32, y*32 + 32, _bg, &clip[2]);
      }
}

void		SDL::setSnake(int **map, int X, int Y)
{
  SDL_Rect	clip[3];

  clip[0].x = clip[1].x = clip[2].x = 0;
  clip[0].y = 0;
  clip[1].y = 32;
  clip[2].y = 64;
  clip[0].w = clip[1].w = clip[2].w = clip[0].h = clip[1].h = clip[2].h = 32;
  for (int y = 0; y < Y; y++)
    for (int x = 0; x < X; x++)
      {
	if (map[y][x] == 2)
	  applySurface(x*32, y*32 + 32, _snake, &clip[0]);
	if (map[y][x] == 3)
	  applySurface(x*32, y*32 + 32, _snake, &clip[1]);
	if (map[y][x] == 4)
	  applySurface(x*32, y*32 + 32, _snake, &clip[2]);
      }
}

void		SDL::setScore(int score)
{
  std::ostringstream	oss117;
  SDL_Color		color;
  SDL_Rect		pos;
  SDL_Surface		*txt;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  oss117 << "Score : " << score;
  txt = TTF_RenderText_Blended(_font, oss117.str().c_str(), color);
  pos.x = 10;
  pos.y = 10;
  if (score != 0 && _curScore != score)
    Mix_PlayChannel(1, _point, 0);
  SDL_BlitSurface(txt, NULL, _screen, &pos);
  SDL_Flip(_screen);
  _curScore = score;
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
	case SDLK_SPACE:
	  return 4;
	default:
	  return 42;
	}
    default:
      return 42;
    }
  return (42);
}

void		SDL::applySurface(int x, int y, SDL_Surface *src, SDL_Rect *clip)
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, clip, _screen, &offset);
}

void		SDL::desc()
{
  std::cout << "Using SDL library !" << std::endl;
}

void		SDL::quit()
{
  SDL_FreeSurface(_bg);
  SDL_FreeSurface(_snake);
  SDL_FreeSurface(_screen);
  Mix_FreeMusic(_music);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
}

int		SDL::gameOver()
{
  return (0);
}
