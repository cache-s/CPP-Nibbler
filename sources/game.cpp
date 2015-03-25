//
// game.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:16 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 12:25:29 2015 Sebastien Cache-Delanos
//

#include				"game.hpp"

//CONSTRUCTOR
Game::Game(int width, int height, void *lib) : _width(width), _height(height), _lib(lib)
{
  std::cout << "Game class instance created" << std::endl;
  initMap();
  printMap();
}

//DESTRUCTOR
Game::~Game()
{
  int					i;

  std::cout << "Game class instance destroyed" << std::endl;

  for(i = 0; i < _height; ++i)
    delete [] _map[i];
  delete [] _map;
}

//INIT
void					Game::initMap()
{
  int					i;
  int					j;

  _map = new int*[_height];
  for(i = 0; i < _width; ++i)
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

//PRINT
void					Game::printMap() const
{
  int					i;
  int					j;

  for (j = 0; j != _height; ++j)
    {
      for (i = 0; i != _width; ++i)
	std::cout << _map[i][j];
      std::cout << "\n";
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
