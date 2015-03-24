//
// main.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Mon Mar 23 13:28:44 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 17:03:22 2015 Jordan Chazottes
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

  if ((dlhandle = dlopen(lib, RTLD_NOW)) == NULL)
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
  return (nibbler(width, height, lib));
}
