//
// game.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:25:49 2015 Sebastien Cache-Delanos
// Last update Thu Apr  2 16:55:11 2015 Sebastien Cache-Delanos
//

#ifndef				GAME_HPP_
# define			GAME_HPP_

# include			"nibbler.hpp"
# include			"Snake.hpp"

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

  enum			Event
    {
      QUIT		=	-1,
      ARROW_LEFT	=	0,
      ARROW_RIGHT	=	1,
      Z_UP		=	2,
      Q_LEFT		=	3,
      S_DOWN		=	4,
      D_RIGHT		=	5,
      BOOST		=	6,
      PAUSE		=	7,
      DEFAULT		=	42,
      UNKNOWN
    };

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
