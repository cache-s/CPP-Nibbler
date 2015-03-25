//
// snake.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Wed Mar 25 12:35:45 2015 Sebastien Cache-Delanos
// Last update Wed Mar 25 18:21:34 2015 Sebastien Cache-Delanos
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

  //SETTERS
  void					setX(int x);
  void					setY(int y);

  //GETTERS
  int					getX() const;
  int					getY() const;
private:
  int					X;
  int					Y;
  std::deque<Direction>			_dir;
};

#endif					//SNAKE_HPP_
