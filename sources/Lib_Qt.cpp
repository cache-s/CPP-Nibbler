//
// Lib_Qt.cpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 17:12:25 2015 Jordan Chazottes
// Last update Tue Mar 24 17:12:28 2015 Jordan Chazottes
//

#include	"Lib_Qt.hpp"

void		Qt::desc() const
{
  std::cout << "Using Qt library !" << std::endl;
}

extern "C"
{
  ILibrary *createLib()
  {
    return new Qt();
  }
}
