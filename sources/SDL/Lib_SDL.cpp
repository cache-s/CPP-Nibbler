//
// lib_SDL.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:39:44 2015 Jordan Chazottes
// Last update Sat Apr  4 17:05:12 2015 Sebastien Cache-Delanos
//

#include	"Lib_SDL.hpp"

extern "C"
{
  ILibrary *createLib()
  {
    return new SDL();
  }
}

SDL::SDL()
{
}

SDL::SDL(const SDL &other)
{
  _font = other._font;
  _screen = other._screen;
  _bg = other._bg;
  _snake = other._snake;
  _tail = other._tail;
  _music = other._music;
  _point = other._point;
  _klaxon = other._klaxon;
  _gameOver = other._gameOver;
  _pause = other._pause;
  _width = other._width;
  _height = other._height;
  _curScore = other._curScore;
}

SDL::~SDL()
{
}

SDL		&SDL::operator=(const SDL &other)
{
  _font = other._font;
  _screen = other._screen;
  _bg = other._bg;
  _snake = other._snake;
  _tail = other._tail;
  _music = other._music;
  _point = other._point;
  _klaxon = other._klaxon;
  _gameOver = other._gameOver;
  _pause = other._pause;
  _width = other._width;
  _height = other._height;
  _curScore = other._curScore;
  return (*this);
}

void		SDL::init(int x, int y)
{
  _width = x;
  _height = y;
  try
    {
      if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	throw std::runtime_error("Error while initializing SDL");
      SDL_WM_SetCaption("Nibbler", "My Nibbler");
      _screen = SDL_SetVideoMode(x*32, y*32 + 32, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
      TTF_Init();
      initAudio();
      initSprites();
      initScore();
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "Exception : " << e.what() << std::endl;
      exit(-1);
    }
}

void		SDL::initScore()
{
  if ((_font = TTF_OpenFont("ressources/fonts/game_over.ttf", 64)) == NULL)
    throw std::runtime_error("Error loading font game_over.ttf");
  _curScore = 0;
  setScore(0);
}

void		SDL::initSprites()
{
  if ((_bg = IMG_Load("ressources/sprites/env.png")) == NULL)
    throw std::runtime_error("Error loading image env.png");
  if ((_snake = IMG_Load("ressources/sprites/nyan.png")) == NULL)
    throw std::runtime_error("Error loading image nyan.png");
  if ((_tail = IMG_Load("ressources/sprites/rainbow.png")) == NULL)
    throw std::runtime_error("Error loading image rainbow.png");
}

void		SDL::initAudio()
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
    throw std::runtime_error("Error while initializing Music mixer");
  if ((_music = Mix_LoadMUS("ressources/sounds/nyan.wav")) == NULL)
    throw std::runtime_error("Error while loading sound nyan.wav");
  if ((_klaxon = Mix_LoadWAV("ressources/sounds/klaxon.wav")) == NULL)
    throw std::runtime_error("Error while loading sound klaxon.wav");
  if ((_point = Mix_LoadWAV("ressources/sounds/coin.wav")) == NULL)
    throw std::runtime_error("Error while loading sound coin.wav");
  if ((_gameOver = Mix_LoadWAV("ressources/sounds/gameOver.wav")) == NULL)
    throw std::runtime_error("Error while loading sound gameOver.wav");
  if ((_pause = Mix_LoadWAV("ressources/sounds/pause.wav")) == NULL)
    throw std::runtime_error("Error while loading sound pause.wav");
  Mix_VolumeMusic(MIX_MAX_VOLUME/2);
  if (Mix_PlayMusic(_music, -1) == -1)
    throw std::runtime_error("Error while playing music");
  Mix_AllocateChannels(3);
}

void		SDL::display(const Data &d)
{
  resetBackground(d._map, _width, _height);
  setSnake(d._snake);
  setScore(d._score);
  setBoost(d._boost);
  SDL_Flip(_screen);
}

void		SDL::resetBackground(int **map, int X, int Y) const
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
	if (map[y][x] == WALL)
	  applySurface(x*32, y*32 + 32, _bg, &clip[3]);
	if (map[y][x] == OBSTACLE)
	  applySurface(x*32, y*32 + 32, _bg, &clip[1]);
	  if (map[y][x] == APPLE)
	    applySurface(x*32, y*32 + 32, _bg, &clip[2]);
      }
}

void		SDL::initSnakeSpritesHead(snakeSprite *snakeSp) const
{
  snakeSp->head[0].x = 0;
  snakeSp->head[0].y = 0;
  snakeSp->head[1].x = 32;
  snakeSp->head[1].y = 0;
  snakeSp->head[2].x = 0;
  snakeSp->head[2].y = 32;
  snakeSp->head[3].x = 32;
  snakeSp->head[3].y = 32;
  snakeSp->head[4].x = 0;
  snakeSp->head[4].y = 64;
  snakeSp->head[5].x = 32;
  snakeSp->head[5].y = 64;
  snakeSp->head[6].x = 0;
  snakeSp->head[6].y = 96;
  snakeSp->head[7].x = 32;
  snakeSp->head[7].y = 96;
}

void            SDL::initSnakeSpritesTail(snakeSprite *snakeSp) const
{
  snakeSp->tail[0].x = 0;
  snakeSp->tail[0].y = 0;
  snakeSp->tail[1].x = 32;
  snakeSp->tail[1].y = 0;
  snakeSp->tail[2].x = 64;
  snakeSp->tail[2].y = 0;

  snakeSp->tail[3].x = 0;
  snakeSp->tail[3].y = 32;
  snakeSp->tail[4].x = 64;
  snakeSp->tail[4].y = 32;

  snakeSp->tail[5].x = 0;
  snakeSp->tail[5].y = 64;
  snakeSp->tail[6].x = 32;
  snakeSp->tail[6].y = 64;
  snakeSp->tail[7].x = 64;
  snakeSp->tail[7].y = 64;

  snakeSp->tail[8].x = 0;
  snakeSp->tail[8].y = 96;
  snakeSp->tail[9].x = 32;
  snakeSp->tail[9].y = 96;
  snakeSp->tail[10].x = 64;
  snakeSp->tail[10].y = 96;

  snakeSp->tail[11].x = 0;
  snakeSp->tail[11].y = 128;
  snakeSp->tail[12].x = 64;
  snakeSp->tail[12].y = 128;

  snakeSp->tail[13].x = 0;
  snakeSp->tail[13].y = 160;
  snakeSp->tail[14].x = 32;
  snakeSp->tail[14].y = 160;
  snakeSp->tail[15].x = 64;
  snakeSp->tail[15].y = 160;
}

void            SDL::initSnakeSprites(snakeSprite *snakeSp) const
{
  for (int i = 0; i < 8; i++)
    snakeSp->head[i].w = snakeSp->head[i].h = 32;
  for (int i = 0; i < 16; i++)
    snakeSp->tail[i].w = snakeSp->tail[i].h = 32;
  initSnakeSpritesHead(snakeSp);
  initSnakeSpritesTail(snakeSp);
}

void		SDL::setSnake(std::vector<Snk> snake) const
{
  snakeSprite	snakeSp;

  initSnakeSprites(&snakeSp);

  applySurface(snake[0]._x*32, snake[0]._y*32 + 32, _snake, &snakeSp.head[snake[0]._dir]);
  for (unsigned int i = 1; i < snake.size(); i++)
    {
      if (snake[i]._dir == RIGHT)
	{
	  if ((i + 1) < snake.size() && snake[i + 1]._dir == UP)
	    applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[8]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1]._dir == DOWN)
	      applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[5]);
	    else
	      if ((i + 1) == snake.size())
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[9]);
	      else
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[6]);
	}
      if (snake[i]._dir == LEFT)
	{
	  if ((i + 1) < snake.size() && snake[i + 1]._dir == UP)
	    applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[2]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1]._dir == DOWN)
	      applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[15]);
	    else
	      if ((i + 1) == snake.size())
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[14]);
	      else
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[1]);
	}
      if (snake[i]._dir == UP)
	{
	  if ((i + 1) < snake.size() && snake[i + 1]._dir == RIGHT)
	    applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[7]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1]._dir == LEFT)
	      applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[13]);
	    else
	      if ((i + 1) == snake.size())
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[11]);
	      else
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[4]);
	}
      if (snake[i]._dir == DOWN)
	{
	  if ((i + 1) < snake.size() && snake[i + 1]._dir == RIGHT)
	    applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[10]);
	  else
	    if ((i + 1) < snake.size() && snake[i + 1]._dir == LEFT)
	      applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[0]);
	    else
	      if ((i + 1) == snake.size())
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[12]);
	      else
		applySurface(snake[i]._x*32, snake[i]._y*32 + 32, _tail, &snakeSp.tail[3]);
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
  pos.x = 0;
  pos.y = 0;
  if (score != 0 && _curScore != score)
    Mix_PlayChannel(1, _point, 0);
  SDL_BlitSurface(txt, NULL, _screen, &pos);
  SDL_Flip(_screen);
  _curScore = score;
}

void		SDL::setBoost(int boost) const
{
  std::ostringstream	oss117;
  SDL_Color		color;
  SDL_Rect		pos;
  SDL_Surface		*txt;
  int			tmp = 0;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  tmp = 10 * boost;
  oss117 << "Boost : " << tmp;
  txt = TTF_RenderText_Blended(_font, oss117.str().c_str(), color);
  pos.x = 200;
  pos.y = 0;
  SDL_BlitSurface(txt, NULL, _screen, &pos);
  SDL_Flip(_screen);
}

void		SDL::muteGame()
{
  if (Mix_PausedMusic() != 1)
    {
      Mix_Volume(-1, 0);
      Mix_PauseMusic();
    }
  else
    {
      Mix_Volume(-1, 128);
      Mix_ResumeMusic();
    }
}

Event	SDL::pause()
{
  SDL_Event	event;

  if (Mix_PausedMusic() != 1)
    {
      Mix_PauseMusic();
      Mix_PlayChannel(1, _pause, -1);
    }
  usleep(10000);
  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return QUIT;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{
	case SDLK_p:
	  Mix_Pause(-1);
	  Mix_ResumeMusic();
	  return DEFAULT;
	case SDLK_ESCAPE:
	  return QUIT;
	default:
	  return UNKNOWN;
	}
    default:
      return UNKNOWN;
    }
  return UNKNOWN;
}

Event	SDL::eventHandler()
{
  SDL_Event	event;
  Event	ret = UNKNOWN;

  SDL_PollEvent(&event);
  switch (event.type)
    {
    case SDL_QUIT:
      return QUIT;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym)
	{
	case SDLK_z:
	  return Z_UP;
	case SDLK_q:
	  return Q_LEFT;
	case SDLK_s:
	  return S_DOWN;
	case SDLK_d:
	  return D_RIGHT;
	case SDLK_p:
	  while (ret != DEFAULT && ret != QUIT)
	    ret = pause();
	  return ret;
	case SDLK_m:
	  muteGame();
	  return DEFAULT;
	case SDLK_k:
	  Mix_PlayChannel(1, _klaxon, 0);
	  return DEFAULT;
	case SDLK_ESCAPE:
	  return QUIT;
	case SDLK_RIGHT:
	  return ARROW_RIGHT;
	case SDLK_LEFT:
	  return ARROW_LEFT;
	case SDLK_SPACE:
	  return BOOST;
	case SDLK_F2:
	  return L_XLIB;
	case SDLK_F3:
	  return L_NCURSES;
	default:
	  return DEFAULT;
	}
    default:
      return DEFAULT;
    }
  return (DEFAULT);
}

void		SDL::applySurface(int x, int y, SDL_Surface *src, SDL_Rect *clip) const
{
  SDL_Rect	offset;

  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(src, clip, _screen, &offset);
}

void		SDL::quit()
{
  SDL_FreeSurface(_bg);
  SDL_FreeSurface(_snake);
  SDL_FreeSurface(_screen);
  SDL_FreeSurface(_tail);

  Mix_FreeMusic(_music);
  Mix_FreeChunk(_point);
  Mix_FreeChunk(_klaxon);
  Mix_FreeChunk(_gameOver);
  Mix_FreeChunk(_pause);
  Mix_CloseAudio();

  TTF_CloseFont(_font);
  TTF_Quit();

  SDL_Quit();
}

int		SDL::checkRestart() const
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
  std::string	text = "Game Over !";
  std::string	text2 = "Press R to Restart or Q to Quit";
  SDL_Color	color;
  SDL_Rect	pos[2];
  SDL_Surface	*txt;
  SDL_Surface	*txt2;
  int		ret;

  Mix_HaltMusic();
  Mix_PlayChannel(1, _gameOver, 0);

  color.r = 255;
  color.g = 255;
  color.b = 255;
  txt = TTF_RenderText_Blended(_font, text.c_str(), color);
  txt2 = TTF_RenderText_Blended(_font, text2.c_str(), color);
  pos[0].x = (_width*32)/2 - 70;
  pos[0].y = (_height*32)/2;
  pos[1].x = (_width*32)/2 - 170;
  pos[1].y = (_height*32)/2 + 50;
  SDL_BlitSurface(txt, NULL, _screen, &pos[0]);
  SDL_BlitSurface(txt2, NULL, _screen, &pos[1]);
  SDL_Flip(_screen);
  while ((ret = checkRestart()) == 42);
  Mix_Pause(-1);
  return ret;
}
