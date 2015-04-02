//
// ILibrary.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Tue Mar 24 15:37:51 2015 Jordan Chazottes
// Last update Thu Apr  2 16:50:29 2015 Sebastien Cache-Delanos
//

#ifndef		ILIBRARY_HPP_
# define	ILIBRARY_HPP_

# include	<vector>

# include	"Game.hpp"

struct	snk;
struct	data;

class		ILibrary
{
public:
  virtual void		init(int, int) = 0;
  virtual void		display(data d) = 0;
  virtual void		quit() = 0;
  virtual Game::Event	eventHandler() = 0;
  virtual int		gameOver() = 0;
  virtual Game::Event	pause() = 0;
};

#endif		//ILIBRARY_HPP_
