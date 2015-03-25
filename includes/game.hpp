//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 12:25:59 2015 Sebastien Cache-Delanos
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			"nibbler.hpp"

class				Game
{
public:
  Game(int width, int height, void *lib);
  ~Game();

  //INIT
  void				initMap();

  //PRINT
  void				printMap() const;

  //GETTERS
  int		const	&	getHeight() const;
  int		const	&	getWidth() const;
  void*				getLib() const;

private:
  const int			_width;
  const int			_height;
  void*				_lib;
  int**				_map;
};

#endif				//GAME_HPP_
