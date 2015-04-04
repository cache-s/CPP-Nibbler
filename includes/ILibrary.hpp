//
// ILibrary.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:37:51 2015 Jordan Chazottes
// Last update Sat Apr  4 17:09:23 2015 Sebastien Cache-Delanos
//

#ifndef		ILIBRARY_HPP_
# define	ILIBRARY_HPP_

# include	<vector>

# include	"Game.hpp"
# include	"Event.hpp"

class		Game;

class		ILibrary
{
public:
  virtual void		init(int, int) = 0;
  virtual void		display(const Data &d) = 0;
  virtual void		quit() = 0;
  virtual Event		eventHandler() = 0;
  virtual int		gameOver() = 0;
  virtual Event		pause() = 0;
  virtual void		muteGame() = 0;
  virtual		~ILibrary() {}
};

#endif		//ILIBRARY_HPP_
