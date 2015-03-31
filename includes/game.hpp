//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Tue Mar 31 11:12:47 2015 Jordan Chazottes
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			"nibbler.hpp"
# include			"snake.hpp"
# include			"ILibrary.hpp"

# include			<vector>

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
  std::vector<int>      boost;
  std::vector<snk>  snake;
}               data;

class				ILibrary;

class				Game
{
public:
  //CONSTRUCTOR
  Game(int width, int height, void *lib);
  //DESTRUCTOR
  ~Game();

  int				checkNext(int coordY, int coordX);
  void				play(ILibrary* curLib);
  void				handleEvent(int event);
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
