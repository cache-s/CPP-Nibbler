//
// Lib_Allegro.hpp for  in /home/charie_p/rendu/cpp_nibbler/includes
//
// Made by Pierre Charié
// Login   <charie_p@epitech.net>
//
// Started on  Sun Mar 29 22:45:43 2015 Pierre Charié
// Last update Mon Mar 30 13:10:34 2015 Pierre Charié
//

#ifndef		LIB_ALLEGRO_HPP_
# define	LIB_ALLEGRO_HPP_


# include       "ILibrary.hpp"
# include       "game.hpp"

# include	"allegro5/Headers/allegro5/allegro.h"
# include	"allegro5/Headers/allegro5/allegro_image.h"
# include	"allegro5/Headers/allegro5/allegro_font.h"
# include	"allegro5/Headers/allegro5/allegro_acodec.h"
# include	"allegro5/Headers/allegro5/allegro_audio.h"



class	Aleg : public ILibrary
{
public:
  Aleg();
  ~Aleg();

  virtual void  init(int, int);
  virtual void  display(int**, int, std::vector<int>);
  virtual void  quit();
  virtual void  desc();
  virtual int   eventHandler();
  virtual int	gameOver();

private:
  void	*allib;
};

#endif
