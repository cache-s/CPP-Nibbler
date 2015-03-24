//
// nibbler.hpp for nibbler in /home/cache-_s/rendu/cpp_nibbler
// 
// Made by Sebastien Cache-Delanos
// Login   <cache-_s@epitech.net>
// 
// Started on  Mon Mar 23 13:25:22 2015 Sebastien Cache-Delanos
// Last update Tue Mar 24 15:04:32 2015 Jordan Chazottes
//

#ifndef				NIBBLER_HPP_
# define			NIBBLER_HPP_

/* INCLUDES */

# include			<iostream>
# include			<cstdlib>
# include			<dlfcn.h>

/* DEFINE */

# define			MIN_WIDTH	10
# define			MAX_WIDTH	100
# define			MIN_HEIGHT	10
# define			MAX_HEIGHT	100

/* PROTOTYPES */

int				main(int ac, char **av);
int				nibbler(unsigned int width, unsigned int height, void *lib);

#endif				//NIBBLER_HPP_
