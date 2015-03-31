//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Tue Mar 31 11:22:42 2015 Jordan Chazottes
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
  if ((_snake = IMG_Load("ressources/sprites/nyan.png")) == NULL)
    std::cout << "Error loading Image Snake" << std::endl;
  if ((_tail = IMG_Load("ressources/sprites/rainbow.png")) == NULL)
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
  setSnake(d.snake);
  setScore(d.score);
  setBoost(d.boost);
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

void		SDL::setSnake(std::vector<snk> snake)
{
  SDL_Rect      head[8];
  SDL_Rect      tail[16];

  for (int i = 0; i < 8; i++)
    head[i].w = head[i].h = 32;
  for (int i = 0; i < 16; i++)
    tail[i].w = tail[i].h = 32;
  head[0].x = 0;
  head[0].y = 0;
  head[1].x = 32;
  head[1].y = 0;
  head[2].x = 0;
  head[2].y = 32;
  head[3].x = 32;
  head[3].y = 32;
  head[4].x = 0;
  head[4].y = 64;
  head[5].x = 32;
  head[5].y = 64;
  head[6].x = 0;
  head[6].y = 96;
  head[7].x = 32;
  head[7].y = 96;

  tail[0].x = 0;
  tail[0].y = 0;
  tail[1].x = 32;
  tail[1].y = 0;
  tail[2].x = 64;
  tail[2].y = 0;

  tail[3].x = 0;
  tail[3].y = 32;
  tail[4].x = 64;
  tail[4].y = 32;

  tail[5].x = 0;
  tail[5].y = 64;
  tail[6].x = 32;
  tail[6].y = 64;
  tail[7].x = 64;
  tail[7].y = 64;

  tail[8].x = 0;
  tail[8].y = 96;
  tail[9].x = 32;
  tail[9].y = 96;
  tail[10].x = 64;
  tail[10].y = 96;

  tail[11].x = 0;
  tail[11].y = 128;
  tail[12].x = 64;
  tail[12].y = 128;

  tail[13].x = 0;
  tail[13].y = 160;
  tail[14].x = 32;
  tail[14].y = 160;
  tail[15].x = 64;
  tail[15].y = 160;

  if (snake[0].dir == DOWN)
    applySurface(snake[0].x*32, snake[0].y*32 + 32, _snake, &head[7]);
  if (snake[0].dir == UP)
    applySurface(snake[0].x*32, snake[0].y*32 + 32, _snake, &head[4]);
  if (snake[0].dir == LEFT)
    applySurface(snake[0].x*32, snake[0].y*32 + 32, _snake, &head[6]);
  if (snake[0].dir == RIGHT)
    applySurface(snake[0].x*32, snake[0].y*32 + 32, _snake, &head[5]);
  for (unsigned int i = 1; i < snake.size(); i++)
    {
      if (snake[i].dir == RIGHT)
	{
	  if ((i + 1) < snake.size() && snake[i + 1].dir == UP)
	    applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[8]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1].dir == DOWN)
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[5]);
	    else
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[9]);
	}
      if (snake[i].dir == LEFT)
	{
	  if ((i + 1) < snake.size() && snake[i + 1].dir == UP)
	    applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[2]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1].dir == DOWN)
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[15]);
	    else
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[1]);
	}
      if (snake[i].dir == UP)
	{
	  if ((i + 1) < snake.size() && snake[i + 1].dir == RIGHT)
	    applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[7]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1].dir == LEFT)
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[13]);
	    else
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[11]);
	}
      if (snake[i].dir == DOWN)
	{
	  if ((i + 1) < snake.size() && snake[i + 1].dir == RIGHT)
	    applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[10]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1].dir == LEFT)
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[0]);
	    else
	      applySurface(snake[i].x*32, snake[i].y*32 + 32, _tail, &tail[12]);
	}
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

void		SDL::setBoost(std::vector<int> boost)
{
  std::ostringstream	oss117;
  SDL_Color		color;
  SDL_Rect		pos;
  SDL_Surface		*txt;
  int			tmp = 0;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  for (unsigned int i = 0; i < boost.size(); i++)
    if (boost[i] == 1)
      tmp += 10;
  oss117 << "Boost : " << tmp;
  txt = TTF_RenderText_Blended(_font, oss117.str().c_str(), color);
  pos.x = 200;
  pos.y = 10;
  SDL_BlitSurface(txt, NULL, _screen, &pos);
  SDL_Flip(_screen);
}



int		SDL::waitPause()
{
  SDL_Event	event;

  sleep(1);
  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return -1;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{
	case SDLK_p:
	  return 42;
	case SDLK_ESCAPE:
	  return -1;
	default:
	  waitPause();
	}
    default:
      return waitPause();
    }
  return waitPause();
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
	case SDLK_z:
	  return 2;
	case SDLK_q:
	  return 3;
	case SDLK_s:
	  return 4;
	case SDLK_d:
	  return 5;
	case SDLK_p:
	  return waitPause();
	case SDLK_ESCAPE:
	  return -1;
	case SDLK_RIGHT:
	  return 1;
	case SDLK_LEFT:
	  return 0;
	case SDLK_SPACE:
	  return 6;
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

int		SDL::checkRestart()
{
  SDL_Event	event;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return 0;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{
	case SDLK_r:
	  return 1;
	case SDLK_q:
	  return 0;
	case SDLK_ESCAPE:
	  return 0;
	default:
	  return 42;
	}
    default:
      return 42;
    }
  return (42);
}

int		SDL::gameOver()
{
  std::ostringstream	oss117;
  SDL_Color		color;
  SDL_Rect		pos;
  SDL_Surface		*txt;
  int			ret;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  oss117 << "Game Over !\n Press R to Restart or Q to quit";
  txt = TTF_RenderText_Blended(_font, oss117.str().c_str(), color);
  pos.x = 100;
  pos.y = 150;
  SDL_BlitSurface(txt, NULL, _screen, &pos);
  SDL_Flip(_screen);
  while ((ret = checkRestart()) == 42);
  return ret;
}
