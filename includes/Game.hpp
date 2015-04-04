//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Sat Apr  4 17:08:27 2015 Sebastien Cache-Delanos
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			<vector>
# include			<stdexcept>

# include			"nibbler.hpp"
# include			"Data.hpp"
# include			"Snake.hpp"
# include			"ILibrary.hpp"
# include			"Event.hpp"
# include			"Map.hpp"

class ILibrary;

class				Game
{
public:
  //CONSTRUCTOR
  Game(int width, int height, void *lib);
  Game(const Game& game);
  //DESTRUCTOR
  ~Game();

  int				checkNext(int coordY, int coordX);
  void				handleEvent(Event event);
  void				loadLib(Event);
  void				handleBoost();
  void				spaceBoost();
  void				updatePath();
  void				updateMap();
  std::vector<Snk>		getSnake();
  void				gameOver();
  int				checkMap() const;
  void				addApple();
  Data				getData();
  void				start();
  void				move();

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
  int				getHeight() const;
  int				getWidth() const;
  int**				getMap() const;
  void*				getLib() const;

private:
  ILibrary			*(*_external_creator)();
  bool				_boosted;
  int				_boost;
  bool				_isAlive;
  bool				_quit;
  int				_width;
  int				_height;
  int				_speed;
  std::vector<Snake*>		_snake;
  int				_score;
  Direction			_dir;
  void*				_lib;
  int**				_map;
  ILibrary			*_curLib;
};

#endif				//GAME_HPP_
