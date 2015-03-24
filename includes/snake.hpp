//
// snake.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Tue Mar 24 11:29:55 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 11:49:16 2015 Sebastien Cache-Delanos
//

#ifndef				SNAKE_HPP_
# define			SNAKE_HPP_

# include			"nibbler.hpp"

class				Snake
{
public:
  Snake(unsigned int width, unsigned int height, const std::string & lib);
  ~Snake();

  //GETTERS
  unsigned int			getHeight() const;
  unsigned int			getWidth() const;
  std::string	const		getLib() const;

private:
  unsigned int			_width;
  unsigned int			_height;
  const std::string		_lib;
};

#endif				//SNAKE_HPP_
