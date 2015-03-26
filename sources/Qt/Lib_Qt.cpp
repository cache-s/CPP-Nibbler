//
// Lib_Qt.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 17:12:25 2015 Jordan Chazottes
// Last update Thu Mar 26 11:12:57 2015 Jordan Chazottes
//

#include	"Lib_Qt.hpp"

void		*Qt::desc(int x, int y)
{
  (void)x;
  (void)y;
  std::cout << "Using Qt library !" << std::endl;
  return (NULL);
}

extern "C"
{
  ILibrary *createLib()
  {
    return new Qt();
  }
}
