//
// main.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Mon Mar 23 13:28:44 2015 Sebastien Cache-Delanos
// Last update Fri Apr  3 16:20:42 2015 Sebastien Cache-Delanos
//

#include			"nibbler.hpp"
#include			"Game.hpp"

#include			<stdexcept>
#include			<sstream>

int				checkSize(int width, int height)
{
  std::ostringstream		widthError;
  std::ostringstream		heightError;

  widthError << "Width must be a valid number between " << MIN_WIDTH << " and " << MAX_WIDTH;
  heightError << "Height must be a valid number between " << MIN_HEIGHT << " and " << MAX_HEIGHT;
  try
    {
      if (width < MIN_WIDTH || width > MAX_WIDTH)
	throw std::range_error(widthError.str());
      if (height < MIN_HEIGHT || height > MAX_HEIGHT)
	throw std::range_error(heightError.str());
    }
  catch (const std::range_error& e)
    {
      std::cout << "Exception : " << e.what() << std::endl;
      return (-1);
    }
  return (0);
}

void				*checkLib(const char *lib)
{
  void				*dlhandle;
  std::string			_lib = lib;

  try
    {
      if (_lib.substr(0, 2) != "./" && _lib.substr(0, 1) != "/")
	_lib = "./" + _lib;
      if ((dlhandle = dlopen(_lib.c_str(), RTLD_LAZY)) == NULL)
	throw std::runtime_error("Error while openning the library");
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "Exception : " << e.what() << std::endl;
    }
  return (dlhandle);
}

int				main(int ac, char **av)
{
  int				height;
  int				width;
  void*				lib;
  Game*				s;

  if (ac != 4)
    {
      std::cout << "Usage : ./nibbler width height lib.so" << std::endl;
      return (-1);
    }
  if (checkSize((width = atoi(av[1])), (height = atoi(av[2]))) != 0)
    return (-1);
  if ((lib = checkLib(av[3])) == NULL)
    return (-1);
  srand(time(NULL));
  s = new Game(width, height, lib);
  s->start();
  delete (s);
  return (0);
}
