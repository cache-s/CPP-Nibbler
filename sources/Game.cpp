//
// game.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Fri Mar 27 11:27:59 2015 Sebastien Cache-Delanos
// Last update Sat Apr  4 17:06:11 2015 Sebastien Cache-Delanos
//

#include				"Game.hpp"

//CONSTRUCTOR
Game::Game(int width, int height, void *lib) : _width(width), _height(height), _lib(lib)
{
  _speed = 200000;
  _dir = RIGHT;
  _isAlive = true;
  _score = 0;
  _boosted = false;
  _boost = 10;
  _quit = false;
  initMap();
}

Game::Game(const Game& game) : _width(game._width), _height(game._height)
{
  _boosted = game._boosted;
  _boost = game._boost;
  _isAlive = game._isAlive;
  _quit = game._quit;
  _speed = game._speed;
  _snake = game._snake;
  _score = game._score;
  _dir = game._dir;
  _lib = game._lib;
  _map = game._map;
  _external_creator = game._external_creator;
  _curLib = game._curLib;
}

//DESTRUCTOR
Game::~Game()
{
  int					i;

  for(i = 0; i < _height; ++i)
    delete [] _map[i];
  delete [] _map;
  for (i = 0; i < (int)_snake.size(); ++i)
    delete _snake[i];
}

void					Game::addApple()
{
  int					i = 0;
  int					j = 0;
  int					k = 0;
  int					w = _width;
  int					h = _height;

  for (i = 0; i < _height; ++i)
    for (j = 0; j < _width; ++j)
      if (_map[i][j] == APPLE)
	return;
  for (j = 0, i = 0; _map[i][j] != EMPTY;)
    {
      if (++k > 1000)
	if (checkMap() == -1)
	  return;
      i = (rand() % (h));
      j = (rand() % (w));
    }
  _map[i][j] = APPLE;
}

int					Game::checkMap() const
{
  int					i;
  int					j;

  for (i = 0; i < _height; ++i)
    for (j = 0; j < _width; ++j)
      if (_map[i][j] == 0)
	return (0);
  return (-1);
}

int					Game::checkNext(int coordY, int coordX)
{
  if (_map[coordY][coordX] == EMPTY || _map[coordY][coordX] == TAIL)
    return (0);
  if (_map[coordY][coordX] == APPLE)
    {
      _map[coordY][coordX] = EMPTY;
      ++_score;
      if (_speed > 80000)
	_speed -= 1000;
      return (1);
    }
  return (-1);
}

void					Game::updatePath()
{
  unsigned int				i;

  _snake[0]->addDir(_dir);
  for (i = 1; i < _snake.size(); ++i)
    _snake[i]->addDir(_snake[i - 1]->getDir());
}

void					Game::move()
{
  unsigned	int			i;
  int					y = 0;
  int					x = 0;
  int					res = 0;
  Direction				tmp;

  tmp = _snake[0]->getDir();
  _snake[0]->popDir();
  _map[_snake[0]->getY()][_snake[0]->getX()] = 0;
  if (tmp == LEFT && (res = checkNext(_snake[0]->getY(), _snake[0]->getX() - 1)) != -1)
    _snake[0]->setX(_snake[0]->getX() - 1);
  else if (tmp == RIGHT && (res = checkNext(_snake[0]->getY(), _snake[0]->getX() + 1)) != -1)
    _snake[0]->setX(_snake[0]->getX() + 1);
  else if (tmp == DOWN && (res = checkNext(_snake[0]->getY() + 1, _snake[0]->getX())) != -1)
    _snake[0]->setY(_snake[0]->getY() + 1);
  else if (tmp == UP && (res = checkNext(_snake[0]->getY() - 1, _snake[0]->getX())) != -1)
    _snake[0]->setY(_snake[0]->getY() - 1);
  if (res == 0 || res == 1)
    {
      for (i = 1; i < _snake.size(); ++i)
	{
	  tmp = _snake[i]->getDir();
	  _snake[i]->popDir();
	  y = _snake[i]->getY();
	  x = _snake[i]->getX();
	  _map[y][x] = EMPTY;
	  if (tmp == LEFT)
	    _snake[i]->setX(x - 1);
	  if (tmp == RIGHT)
	    _snake[i]->setX(x + 1);
	  if (tmp == DOWN)
	    _snake[i]->setY(y + 1);
	  if (tmp == UP)
	    _snake[i]->setY(y - 1);
	}
      if (res == 1)
	{
	  _snake.push_back(new Snake(x, y));
	  _snake[_snake.size() - 1]->addDir(tmp);
	  addApple();
	}
    }
  else
    gameOver();
}

void					Game::spaceBoost()
{
  if (_boosted)
    {
      _speed += 79000;
      _boosted = false;
    }
  else
    {
      _speed -= 79000;
      _boosted = true;
    }
}

void					Game::handleBoost()
{
  if (_boosted)
    {
      if (_boost == 0)
	spaceBoost();
      else
	_boost--;
    }
  else
    if (_boost < 10)
      _boost++;
}

void					Game::loadLib(Event event)
{
  void					*dlhandle;

  try
    {
      if (event == L_SDL)
	if ((dlhandle = dlopen("./lib_nibbler_SDL.so", RTLD_LAZY)) == NULL)
	  throw std::runtime_error("Error while changing library to SDL");
      if (event == L_XLIB)
	if ((dlhandle = dlopen("./lib_nibbler_Xlib.so", RTLD_LAZY)) == NULL)
	  throw std::runtime_error("Error while changing library to XLib");
      if (event == L_NCURSES)
	if ((dlhandle = dlopen("./lib_nibbler_NCurses.so", RTLD_LAZY)) == NULL)
	  throw std::runtime_error("Error while changing library to NCurses");
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "Exception : " << e.what() << std::endl;
      exit (-1);
    }
  _lib = dlhandle;
  _curLib->quit();
  _external_creator = reinterpret_cast<ILibrary* (*)()>(dlsym(dlhandle, "createLib"));
  _curLib = _external_creator();
  _curLib->init(_width, _height);
}

void					Game::handleEvent(Event event)
{
  if (event != DEFAULT)
    {
      if (event == QUIT)
	_quit = true;
      if (event == ARROW_LEFT || event == ARROW_RIGHT)
	setDirection(event);
      if (event == Z_UP || event == Q_LEFT || event == S_DOWN || event == D_RIGHT)
	setRealDirection(event);
      if (event == BOOST)
	spaceBoost();
      if (event == L_SDL || event == L_XLIB || event == L_NCURSES)
	loadLib(event);
    }
}

void					Game::reinit()
{
  int					i;

  for(i = 0; i < _height; ++i)
    delete [] _map[i];
  delete [] _map;
  for (i = 0; i < (int)_snake.size(); ++i)
    delete _snake[i];
  _snake.clear();
  _speed = 200000;
  _dir = RIGHT;
  _isAlive = true;
  _score = 0;
  _boosted = false;
  _boost = 10;
  initMap();
}

std::vector<Snk>			Game::getSnake()
{
  std::vector<Snk>			s;
  unsigned int				i;
  Snk					tmp;

  for (i = 0; i < _snake.size(); ++i)
    {
      tmp._x = _snake[i]->getX();
      tmp._y = _snake[i]->getY();
      if (_snake[i]->getDirection().size() > 0)
	tmp._dir = _snake[i]->getDirection()[0];
      else
	tmp._dir = _dir;
      s.push_back(tmp);
    }
  return s;
}

Data					Game::getData()
{
  Data					d;

  d._map = _map;
  d._score = _score;
  d._boost = _boost;
  d._snake = getSnake();
  return d;
}

void					Game::start()
{
  _external_creator = reinterpret_cast<ILibrary* (*)()>(dlsym(_lib, "createLib"));
  _curLib = _external_creator();
  _curLib->init(_width, _height);
  while (_isAlive && _quit == false)
    {
      handleEvent(_curLib->eventHandler());
      addApple();
      updatePath();
      move();
      handleBoost();
      updateMap();
      _curLib->display(getData());
      handleEvent(_curLib->eventHandler());
      usleep(_speed);
    }
  if (_quit == false && _curLib->gameOver() == 1)
    {
      reinit();
      start();
    }
  else
    _curLib->quit();
}

void					Game::updateMap()
{
  unsigned int				i;

  _map[_snake[0]->getY()][_snake[0]->getX()] = HEAD;
  for (i = 1; i < _snake.size() - 1; ++i)
    _map[_snake[i]->getY()][_snake[i]->getX()] = BODY;
  _map[_snake[_snake.size() - 1]->getY()][_snake[_snake.size() - 1]->getX()] = TAIL;
}

void					Game::gameOver()
{
  _isAlive = false;
}

//INIT
void					Game::initMap()
{
  int					i;
  int					j;

  _map = new int*[_height];
  for(i = 0; i < _height; ++i)
    _map[i] = new int[_width];
  for (j = 0; j != _height; ++j)
    for (i = 0; i != _width; ++i)
      _map[j][i] = 0;
  for (i = 0; i != _width; ++i)
    _map[0][i] = 1;
  for (i = 0; i != _width; ++i)
    _map[_height - 1][i] = 1;
  for (i = 0; i != _height; ++i)
    _map[i][0] = 1;
  for (i = 0; i != _height; ++i)
    _map[i][_width - 1] = 1;
  initSnake();
  initObstacle();
  addApple();
}

void					Game::initSnake()
{
  unsigned int				i;

  _snake.push_back(new Snake((_width / 2) + 2, (_height / 2)));
  _snake.push_back(new Snake((_width / 2) + 1, (_height / 2)));
  _snake.push_back(new Snake((_width / 2) + 0, (_height / 2)));
  _snake.push_back(new Snake((_width / 2) - 1, (_height / 2)));
  for (i = 1; i < _snake.size(); ++i)
    _snake[i]->addDir(_dir);
}

void					Game::initObstacle()
{
  int					i = 0;
  int					j = 0;

  for (i = 2; i < _height - 2; ++i)
    {
      for (j = 2; j < _width - 2 && i < _height - 2; ++j)
	{
	  if (_map[i][j] == 0 && (rand() % 100 + 1) > 98)
	    {
	      _map[i][j] = OBSTACLE;
	      ++j;
	      ++i;
	    }
	}
    }
}

//PRINT
void					Game::printMap() const
{
  int					i;
  int					j;

  for (j = 0; j != _height; ++j)
    {
      for (i = 0; i != _width; ++i)
	std::cout << _map[j][i];
      std::cout << "\n";
    }
}

//SETTERS
void					Game::setRealDirection(int dir)
{
  if (dir == 2 && _dir != DOWN)
    _dir = UP;
  else if (dir == 3 && _dir != RIGHT)
    _dir = LEFT;
  else if (dir == 4 && _dir != UP)
    _dir = DOWN;
  else if (dir == 5 && _dir != LEFT)
    _dir = RIGHT;
}

void					Game::setDirection(int dir)
{
  if (dir == 0)
    {
      if (_dir == LEFT)
	_dir = DOWN;
      else if (_dir == RIGHT)
	_dir = UP;
      else if (_dir == DOWN)
	_dir = RIGHT;
      else if (_dir == UP)
	_dir = LEFT;
    }
  else if (dir == 1)
    {
      if (_dir == LEFT)
	_dir = UP;
      else if (_dir == RIGHT)
	_dir = DOWN;
      else if (_dir == DOWN)
	_dir = LEFT;
      else if (_dir == UP)
	_dir = RIGHT;
    }
}

//GETTERS
int					Game::getHeight() const
{
  return (_height);
}

int					Game::getWidth() const
{
  return (_width);
}

void*					Game::getLib() const
{
  return (_lib);
}

int**					Game::getMap() const
{
  return (_map);
}
