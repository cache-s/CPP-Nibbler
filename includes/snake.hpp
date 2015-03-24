//
// snake.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Tue Mar 24 11:29:55 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 14:41:25 2015 Jordan Chazottes
//

#ifndef				SNAKE_HPP_
# define			SNAKE_HPP_

# include			"nibbler.hpp"

class				Snake
{
public:
  Snake(unsigned int width, unsigned int height, void *lib);
  ~Snake();

  //GETTERS
  unsigned int			getHeight() const;
  unsigned int			getWidth() const;
  void				*getLib() const;

private:
  unsigned int			_width;
  unsigned int			_height;
  void				*_lib;
};

#endif				//SNAKE_HPP_
