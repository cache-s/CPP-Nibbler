//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 19:12:05 2015 Sebastien Cache-Delanos
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			"nibbler.hpp"
# include			"snake.hpp"

# include			<vector>

class				Game
{
public:
  Game(int width, int height, void *lib);
  ~Game();

  void				updatePath();
  void				updateMap();
  void				start();
  void				move();

  //INIT
  void				initMap();
  void				initSnake();

  //PRINT
  void				printMap() const;

  //SETTERS
  void				setDirection(int dir);

  //GETTERS
  int		const	&	getHeight() const;
  int		const	&	getWidth() const;
  int**				getMap() const;
  void*				getScreen() const;
  void*				getLib() const;

private:
  const int			_width;
  const int			_height;
  int				_speed;
  Direction			_dir;
  void*				_lib;
  int**				_map;
  std::vector<Snake*>		_snake;
  bool				_isAlive;
  void*				_screen;
};

#endif				//GAME_HPP_
