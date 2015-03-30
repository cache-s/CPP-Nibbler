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
 *      Configuration defines for use on Unix platforms.
 *
 *      By Michael Bukin.
 *
 *      See readme.txt for copyright information.
 */


#include <fcntl.h>
#include <unistd.h>

/* Describe this platform.  */
#define ALLEGRO_PLATFORM_STR  "Unix"

#define ALLEGRO_EXTRA_HEADER "./platform/alunix.h"

#ifdef _this_allegro5_a_hack_allegro5_fool_scons
#include "alunix.h"
#endif

#define ALLEGRO_INTERNAL_HEADER "./platform/aintunix.h"
#define ALLEGRO_INTERNAL_THREAD_HEADER "./platform/aintuthr.h"

/* Include configuration information.  */
#include "../platform/alplatf.h"

/* Enable OpenGL if GLX is available. */
#ifdef ALLEGRO_GLX
#define ALLEGRO_CFG_OPENGL
#endif
