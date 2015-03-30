/*         _allegro5___   ___    ___ 
 *        /\  _  \ /\_ \  /\_ \ 
 *        \ \ \L\ \\//\ \ \//\ \      __     __   _allegro5_   ___ 
 *         \ \  __ \ \ \ \  \ \ \   /'__`\ /'_ `\/\`'__\/ __`\
 *          \ \ \/\ \ \_\ \_allegro5_\ \_/\  __//\ \L\ \ \ \//\ \L\ \
 *           \ \_\ \_\/\_allegro5_\/\_allegro5_\ \_allegro5_\ \_allegro5_ \ \_\\ \_allegro5_/
 *            \/_/\/_/\/_allegro5_/\/_allegro5_/\/_allegro5_/\/___L\ \/_/ \/___/
 *                                           /\_allegro5_/
 *                                           \_allegro5_/
 *
 *      A header file to get C99's stdbool.h.
 *
 *      By Peter Wang.
 * 
 *      See readme.txt for copyright information.
 */

#ifndef __allegro5_included_allegro5_astdbool_h
#define __allegro5_included_allegro5_astdbool_h

#ifndef __cplusplus
#  ifdef ALLEGRO_HAVE_STDBOOL_H
#     include <stdbool.h>
#  else
#     ifndef ALLEGRO_HAVE__BOOL
         typedef unsigned char _Bool;
#     endif
#     define bool _Bool
#     define false 0
#     define true 1
#     define __bool_true_false_are_defined 1
#  endif
#endif

#endif
