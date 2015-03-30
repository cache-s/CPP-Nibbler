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
 *      Configuration defines for use on iOS.
 *
 *      See readme.txt for copyright information.
 */


#include <fcntl.h>
#include <unistd.h>

/* Describe this platform.  */
#define ALLEGRO_PLATFORM_STR  "IPHONE"

#define ALLEGRO_EXTRA_HEADER "../platform/aliphone.h"
#define ALLEGRO_INTERNAL_HEADER "../platform/aintiphone.h"
#define ALLEGRO_INTERNAL_THREAD_HEADER "../platform/aintuthr.h"

#define ALLEGRO_EXCLUDE_GLX

#ifndef AL_INLINE
#define AL_INLINE(type, name, args, code)    \
static __inline__ type name args;         \
static __inline__ type name args code
#endif
