//
// ILibrary.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:37:51 2015 Jordan Chazottes
// Last update Fri Mar 27 13:53:24 2015 Jordan Chazottes
//

#ifndef		ILIBRARY_HPP_
# define	ILIBRARY_HPP_

# include	"game.hpp"

class	Game;

class		ILibrary
{
public:
  virtual void	desc() = 0;
  virtual void	init(int, int) = 0;
  virtual void	display(int**, int, int, int) = 0;
  virtual void	setScore(int) = 0;
  virtual void	quit() = 0;
  virtual int	eventHandler() = 0;
};

#endif		//ILIBRARY_HPP_
