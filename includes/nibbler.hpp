//
// nibbler.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Mon Mar 23 13:25:22 2015 Sebastien Cache-Delanos
// Last update Fri Apr  3 11:35:29 2015 Jordan Chazottes
//

#ifndef				NIBBLER_HPP_
# define			NIBBLER_HPP_

/* INCLUDES */

# include			<iostream>
# include			<cstdlib>
# include			<unistd.h>
# include			<cstdio>
# include			<dlfcn.h>

/* DEFINE */

# define			MIN_WIDTH	20
# define			MAX_WIDTH	60
# define			MIN_HEIGHT	20
# define			MAX_HEIGHT	30

/* ENUM */

enum				Direction
  {
    DOWN			= 7,
    UP				= 4,
    LEFT			= 6,
    RIGHT			= 5
  };

/* PROTOTYPES */

int				main(int ac, char **av);

#endif				//NIBBLER_HPP_
