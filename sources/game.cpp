//
// game.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:16 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 19:08:08 2015 Sebastien Cache-Delanos
//

#include				"game.hpp"

//CONSTRUCTOR
Game::Game(int width, int height, void *lib) : _width(width), _height(height), _lib(lib)
{
  std::cout << "Game class instance created" << std::endl;
  _speed = 500000;
  _dir = RIGHT;
  _isAlive = true;
  initMap();
  initSnake();
  printMap();
  start();
}

//DESTRUCTOR
Game::~Game()
{
  int					i;

  std::cout << "Game class instance destroyed" << std::endl;
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

void					Game::move()
{
  unsigned	int			i;
  Direction				tmp;

  for (i = 0; i < _snake.size(); ++i)
    {
      tmp = _snake[i]->getDir();
      if (tmp == LEFT)
	{
	  _map[_snake[i]->getY()][_snake[i]->getX()] = 0;
	  _snake[i]->setX(_snake[i]->getX() - 1);
	}
      if (tmp == RIGHT)
	{
	  _map[_snake[i]->getY()][_snake[i]->getX()] = 0;
	  _snake[i]->setX(_snake[i]->getX() + 1);
	}
      if (tmp == DOWN)
	{
	  _map[_snake[i]->getY()][_snake[i]->getX()] = 0;
	  _snake[i]->setY(_snake[i]->getY() + 1);
	}
      if (tmp == UP)
	{
	  _map[_snake[i]->getY()][_snake[i]->getX()] = 0;
	  _snake[i]->setY(_snake[i]->getY() - 1);
	}
    }
}

void					Game::start()
{
  int					i = 0;

  while (_isAlive)
    {
      updatePath();
      move();
      updateMap();
      printMap();
      usleep(_speed);
      if (++i == 5)
	_dir = UP;
    }
}

void					Game::updateMap()
{
  unsigned int				i;

  _map[_snake[0]->getY()][_snake[0]->getX()] = 2;
  for (i = 1; i < _snake.size() - 1; ++i)
    _map[_snake[i]->getY()][_snake[i]->getX()] = 3;
  _map[_snake[_snake.size() - 1]->getY()][_snake[_snake.size() - 1]->getX()] = 4;
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
    _dir = DOWN;
  if (dir == 1)
    _dir = UP;
  if (dir == 2)
    _dir = LEFT;
  if (dir == 3)
    _dir = RIGHT;
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
