//
// ILibrary.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:37:51 2015 Jordan Chazottes
// Last update Fri Apr  3 12:35:37 2015 Jordan Chazottes
//

#ifndef		ILIBRARY_HPP_
# define	ILIBRARY_HPP_

# include	<vector>

# include	"Game.hpp"
# include	"Event.hpp"

struct	snk;
struct	data;

class		Game;

class		ILibrary
{
public:
  virtual void		init(int, int) = 0;
  virtual void		display(const data &d) = 0;
  virtual void		quit() = 0;
  virtual Event		eventHandler() = 0;
  virtual int		gameOver() = 0;
  virtual Event		pause() = 0;
  virtual void		muteGame() = 0;
  virtual		~ILibrary() {}
};

#endif		//ILIBRARY_HPP_
