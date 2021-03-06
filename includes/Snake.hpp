//
// snake.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:45 2015 Sebastien Cache-Delanos
// Last update Sat Apr  4 16:51:17 2015 Jordan Chazottes
//

#ifndef					SNAKE_HPP_
# define				SNAKE_HPP_

# include				"nibbler.hpp"

# include				<deque>

class					Snake
{
public:
  Snake(int x, int y);
  ~Snake();

  void					addDir(Direction dir);
  void					addDirFront(Direction dir);
  void					popDir();

  //SETTERS
  void					setX(int x);
  void					setY(int y);
  void					setDirection(const std::deque<Direction> &dir);

  //GETTERS
  int					getX() const;
  int					getY() const;
  const std::deque<Direction>		&getDirection() const;
  Direction				getDir() const;
private:
  int					_x;
  int					_y;
  std::deque<Direction>			_dir;
};

#endif					//SNAKE_HPP_
