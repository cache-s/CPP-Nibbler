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
 *      Configuration defines for use with MacOS X.
 *
 *      By Angelo Mottola.
 *
 *      See readme.txt for copyright information.
 */


#ifndef __allegro5_included_allegro5_alosxcfg_h
#define __allegro5_included_allegro5_alosxcfg_h

/* Include configuration information.  */
#include "../platform/alplatf.h"

#define ALLEGRO_INTERNAL_THREAD_HEADER "../platform/aintuthr.h"

/* Describe this platform */
#define ALLEGRO_PLATFORM_STR  "MacOS X"


/* Arrange for other headers to be included later on */
#define ALLEGRO_EXTRA_HEADER     "./platform/alosx.h"
#define ALLEGRO_INTERNAL_HEADER  "./platform/aintosx.h"


#endif
