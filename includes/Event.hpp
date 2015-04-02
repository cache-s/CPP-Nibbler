//
// Event.hpp for nibbler in /home/chazot_a/rendu/cpp_nibbler
// 
// Made by Jordan Chazottes
// Login   <chazot_a@epitech.net>
// 
// Started on  Thu Apr  2 17:48:33 2015 Jordan Chazottes
// Last update Thu Apr  2 17:49:11 2015 Jordan Chazottes
//

#ifndef				EVENT_HPP_
# define			EVENT_HPP_

 enum                  Event
   {
     QUIT              =       -1,
     ARROW_LEFT        =       0,
     ARROW_RIGHT       =       1,
     Z_UP              =       2,
     Q_LEFT            =       3,
     S_DOWN            =       4,
     D_RIGHT           =       5,
     BOOST             =       6,
     PAUSE             =       7,
     L_SDL             =       8,
     L_XLIB            =       9,
     L_NCURSES         =       10,
     DEFAULT           =       42,
      UNKNOWN
   };

#endif				/* EVENT_HPP */
