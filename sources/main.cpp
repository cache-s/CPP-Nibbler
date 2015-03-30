//
// main.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
//
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
//
// Started on  Mon Mar 23 13:28:44 2015 Sebastien Cache-Delanos
// Last update Mon Mar 30 11:38:04 2015 Pierre Charié
//

#include			"nibbler.hpp"

int				checkSize(int width, int height)
{
  int				err;

  err = 0;
  if (width < MIN_WIDTH || width > MAX_WIDTH)
    {
      std::cout << "Width must be a valid number between " << MIN_WIDTH << " and " << MAX_WIDTH << std::endl;
      err++;
    }
  if (height < MIN_HEIGHT || height > MAX_HEIGHT)
    {
      std::cout << "Height must be a valid number between " << MIN_HEIGHT << " and " << MAX_HEIGHT << std::endl;
      err++;
    }
  if (err > 0)
    return (-1);
  return (0);
}

void				*checkLib(const char *lib)
{
  void				*dlhandle;
  std::string			_lib = lib;

  if (_lib.substr(0, 2) != "./" && _lib.substr(0, 1) != "/")
    _lib = "./" + _lib;
  if ((dlhandle = dlopen(_lib.c_str(), RTLD_LAZY)) == NULL)
    std::cout << "Error while openning the library " << lib << std::endl;
  return (dlhandle);
}

int				main(int ac, char **av)
{
  int				height;
  int				width;
  void				*lib;

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
  return (nibbler(width, height, lib));
}
