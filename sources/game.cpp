//
// game.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:16 2015 Sebastien Cache-Delanos
// Last update Fri Mar 27 11:26:47 2015 Sebastien Cache-Delanos
//

#include				"game.hpp"

//CONSTRUCTOR
Game::Game(int width, int height, void *lib) : _width(width), _height(height), _lib(lib)
{
  _speed = 300000;
  _dir = RIGHT;
  _isAlive = true;
  _score = 0;
  initMap();
  initSnake();
  start();
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

void					Game::updatePath()
{
  unsigned int				i;

  if (_dir == DOWN)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(DOWN);
  if (_dir == UP)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(UP);
  if (_dir == LEFT)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(LEFT);
  if (_dir == RIGHT)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(RIGHT);
}

void					Game::addApple()
{
  int					i = 0;
  int					j = 0;
  int					k = 0;
  int					w = _width;
  int					h = _height;

  while (_map[i][j] != 0)
    {
      if (++k > 200)
	if (checkMap() == -1)
	  return;
      i = (rand() % h);
      j = (rand() % w);
    }
  _map[i][j] = 5;
}

int					Game::checkMap()
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
  if (_map[coordY][coordX] == 0)
    return (0);
  if (_map[coordY][coordX] == 5)
    {
      _map[coordY][coordX] = 0;
      addApple();
      ++_score;
      return (1);
    }
  return (-1);
}

void					Game::move()
{
  unsigned	int			i;
  int					y = 0;
  int					x = 0;
  int					res = 0;
  Direction				tmp;

  tmp = _snake[0]->getDir();
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
	  y = _snake[i]->getY();
	  x = _snake[i]->getX();
	  _map[y][x] = 0;
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
	  _snake[_snake.size() - 1]->setDirection(_snake[_snake.size() - 2]->getDirection());
	  _snake[_snake.size() - 1]->addDirFront(_snake[_snake.size() - 2]->getDirection()[0]);
	}
      return;
    }
  gameOver();
}

void					Game::spaceBoost(int status)
{
  if (status == 0)
    _speed -= 100000;
  if (status == 1)
    _speed += 100000;
}

void					Game::start()
{
  ILibrary                              *(*external_creator)();
  ILibrary                              *curLib;

  external_creator = reinterpret_cast<ILibrary* (*)()>(dlsym(_lib, "createLib"));
  curLib = external_creator();
  curLib->init(_width, _height);
  while (_isAlive)
    {
      curLib->display(_map, _width, _height);
      updatePath();
      move();
      updateMap();
      usleep(_speed);
      if (_speed > 200000)
	_speed -= 1000;
    }
  curLib->quit();
}

void					Game::updateMap()
{
  unsigned int				i;

  _map[_snake[0]->getY()][_snake[0]->getX()] = 2;
  for (i = 1; i < _snake.size() - 1; ++i)
    _map[_snake[i]->getY()][_snake[i]->getX()] = 3;
  _map[_snake[_snake.size() - 1]->getY()][_snake[_snake.size() - 1]->getX()] = 4;
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
  initObstacle();
  addApple();
}

void					Game::initSnake()
{
  _snake.push_back(new Snake((_width / 2) + 2, (_height / 2)));
  _snake.push_back(new Snake((_width / 2) + 1, (_height / 2)));
  _snake.push_back(new Snake((_width / 2) + 0, (_height / 2)));
  _snake.push_back(new Snake((_width / 2) - 1, (_height / 2)));
  _snake[1]->addDir(_dir);
  _snake[2]->addDir(_dir);
  _snake[2]->addDir(_dir);
  _snake[3]->addDir(_dir);
  _snake[3]->addDir(_dir);
  _snake[3]->addDir(_dir);
  updateMap();
}

void					Game::initObstacle()
{
  int					i = 0;
  int					j = 0;

  for (i = 0; i < _height; ++i)
    {
      for (j = 0; j < _width; ++j)
	{
	  if (_map[i][j] == 0 && (rand() % 100 + 1) > 98)
	    _map[i][j] = 6;
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
int		const	&		Game::getHeight() const
{
  return (_height);
}

int		const	&		Game::getWidth() const
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
