//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Fri Apr  3 14:03:43 2015 Sebastien Cache-Delanos
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			<vector>

# include			"nibbler.hpp"
# include			"Snake.hpp"
# include			"ILibrary.hpp"
# include			"Event.hpp"


class ILibrary;

typedef struct  snk
{
  int           x;
  int           y;
  Direction     dir;
}               snk;

typedef struct  data
{
  int**                 map;
  int                   score;
  int			boost;
  std::vector<snk>	snake;
}               data;

class				Game
{
public:
  //CONSTRUCTOR
  Game(int width, int height, void *lib);
  //DESTRUCTOR
  ~Game();

  int				checkNext(int coordY, int coordX);
  void				handleEvent(Event event);
  void				handleBoost();
  void				spaceBoost();
  void				updatePath();
  void				updateMap();
  std::vector<snk>		getSnake();
  void				gameOver();
  int				checkMap();
  void				addApple();
  data				getData();
  void				start();
  void				move();
  void				loadLib(Event);
  //INIT
  void				initObstacle();
  void				initSnake();
  void				initMap();
  void				reinit();

  //PRINT
  void				printMap() const;

  //SETTERS
  void				setRealDirection(int dir);
  void				setDirection(int dir);

  //GETTERS
  int		const&		getHeight() const;
  int		const&		getWidth() const;
  int**				getMap() const;
  void*				getLib() const;

private:
  bool				_boosted;
  int				_boost;
  bool				_isAlive;
  bool				_quit;
  const int			_width;
  const int			_height;
  int				_speed;
  std::vector<Snake*>		_snake;
  int				_score;
  Direction			_dir;
  void*				_lib;
  int**				_map;
  ILibrary			*(*_external_creator)();
  ILibrary			*_curLib;
};

#endif				//GAME_HPP_
