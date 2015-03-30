//
// game.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Fri Mar 27 11:27:59 2015 Sebastien Cache-Delanos
// Last update Mon Mar 30 16:02:53 2015 Sebastien Cache-Delanos
//

#include				"game.hpp"

//CONSTRUCTOR
Game::Game(int width, int height, void *lib) : _width(width), _height(height), _lib(lib)
{
  _speed = 200000;
  _dir = RIGHT;
  _isAlive = true;
  _score = 0;
  _boosted = false;
  initMap();
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
  Direction				tmp = _dir;

  if (tmp == DOWN)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(DOWN);
  if (tmp == UP)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(UP);
  if (tmp == LEFT)
    for (i = 0; i < _snake.size(); ++i)
      _snake[i]->addDir(LEFT);
  if (tmp == RIGHT)
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

  for (i = 0; i < _height; ++i)
    for (j = 0; j < _width; ++j)
      if (_map[i][j] == 5)
	return;
  for (j = 0, i = 0; _map[i][j] != 0;)
    {
      if (++k > 1000)
	if (checkMap() == -1)
	  return;
      i = (rand() % (h));
      j = (rand() % (w));
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
      ++_score;
      if (_speed > 80000)
	_speed -= 600;
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
	  _snake[_snake.size() - 1]->addDirFront(tmp);
	  addApple();
	}
      return;
    }
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
  unsigned int				i;

  if (_boost.size() == 0)
    for (i = 0; i < 10; ++i)
      _boost.push_back(1);
  if (_boosted)
    {
      if (_boost[0] == 0)
	spaceBoost();
      else
	{
	  for (i = 0; i < _boost.size(); ++i)
	    if (_boost[i] == 0)
	      _boost[i - 1] = 0;
	    else
	      if (i + 1 == _boost.size())
		_boost[i] = 0;
	}
    }
  else
    for (i = 0; i < _boost.size(); ++i)
      if (_boost[i] == 0)
	{
	  _boost[i] = 1;
	  return;
	}
}

void					Game::handleEvent(int event)
{
  if (event != 42)
    {
      if (event == -1)
	gameOver();
      if (event == 0 || event == 1)
	setDirection(event);
      if (event >= 2 && event <= 5)
	setRealDirection(event);
      if (event == 6)
	spaceBoost();
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
  initMap();
}

std::vector<snk>			Game::getSnake()
{
  std::vector<snk>			s;
  unsigned int				i;
  snk					tmp;

  for (i = 0; i < _snake.size(); ++i)
    {
      tmp.x = _snake[i]->getX();
      tmp.y = _snake[i]->getY();
      tmp.dir = _snake[i]->getDirection()[0];
      s.push_back(tmp);
    }
  return s;
}

data					Game::getData()
{
  data					d;

  d.map = _map;
  d.score = _score;
  d.boost = _boost;
  d.snake = getSnake();
  return d;
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
      handleEvent(curLib->eventHandler());
      addApple();
      updatePath();
      move();
      handleBoost();
      updateMap();
      curLib->display(getData());
      handleEvent(curLib->eventHandler());
      usleep(_speed);
    }
  if (curLib->gameOver() == 1)
    {
      reinit();
      start();
    }
  else
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
  initSnake();
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
