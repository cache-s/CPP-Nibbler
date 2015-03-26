//
// snake.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:45 2015 Sebastien Cache-Delanos
// Last update Thu Mar 26 12:25:37 2015 Sebastien Cache-Delanos
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

  Direction				getDir();
  void					addDir(Direction dir);
  void					addDirFront(Direction dir);

  //SETTERS
  void					setX(int x);
  void					setY(int y);
  void					setDirection(std::deque<Direction> dir);

  //GETTERS
  int					getX() const;
  int					getY() const;
  std::deque<Direction>			getDirection() const;
private:
  int					X;
  int					Y;
  std::deque<Direction>			_dir;
};

#endif					//SNAKE_HPP_
