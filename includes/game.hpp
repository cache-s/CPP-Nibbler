//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Sun Mar 29 19:13:55 2015 Sebastien Cache-Delanos
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			"nibbler.hpp"
# include			"snake.hpp"
# include			"ILibrary.hpp"

# include			<vector>

class				ILibrary;

class				Game
{
public:
  //CONSTRUCTOR
  Game(int width, int height, void *lib);
  //DESTRUCTOR
  ~Game();

  int				checkNext(int coordY, int coordX);
  void				handleBoost();
  void				spaceBoost();
  void				updatePath();
  void				updateMap();
  int				checkMap();
  void				addApple();
  void				gameOver();
  void				start();
  void				move();

  //INIT
  void				initObstacle();
  void				initSnake();
  void				initMap();

  //PRINT
  void				printMap() const;

  //SETTERS
  void				setDirection(int dir);

  //GETTERS
  int		const&		getHeight() const;
  int		const&		getWidth() const;
  int**				getMap() const;
  void*				getLib() const;

private:
  bool				_boosted;
  std::vector<int>		_boost;
  bool				_isAlive;
  const int			_width;
  const int			_height;
  int				_speed;
  std::vector<Snake*>		_snake;
  int				_score;
  Direction			_dir;
  void*				_lib;
  int**				_map;
};

#endif				//GAME_HPP_
