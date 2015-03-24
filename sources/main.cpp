//
// main.cpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Mon Mar 23 13:28:44 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 12:43:06 2015 Sebastien Cache-Delanos
//

#include			"nibbler.hpp"

int				checkWidth(int width)
{
  (void)width;
  return (0);
}

int				checkHeight(int height)
{
  (void)height;
  return (0);
}

int				checkLib(const std::string & lib)
{
  (void)lib;
  return (0);
}

int				main(int ac, char **av)
{
  int				height;
  int				width;
  std::string			lib;

  if (ac != 4)
    {
      std::cout << "Usage : ./nibbler width height lib.so" << std::endl;
      return (-1);
    }
  if (checkWidth((width = atoi(av[1]))) != 0)
    return (-1);
  if (checkHeight((height = atoi(av[2]))) != 0)
    return (-1);
  if (checkLib((lib = av[3])) != 0)
    return (-1);
  return (nibbler(width, height, lib));
}
