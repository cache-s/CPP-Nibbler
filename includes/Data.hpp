//
// Data.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Sat Apr  4 17:06:42 2015 Sebastien Cache-Delanos
// Last update Sat Apr  4 17:08:58 2015 Sebastien Cache-Delanos
//

#ifndef				DATA_HPP_
# define			DATA_HPP_

class           Snk
{
public:
  int			_x;
  int			_y;
  Direction		_dir;
};

class           Data
{
public:
  int**			_map;
  int			_score;
  int			_boost;
  std::vector<Snk>	_snake;
};

#endif				//DATA_HPP_
