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
 *      Configuration defines for use with Mingw32.
 *
 *      By Michael Rickmann.
 *
 *      Native build version by Henrik Stokseth.
 *
 *      See readme.txt for copyright information.
 */


#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <malloc.h>

#include "../platform/alplatf.h"


/* describe this platform */
#ifdef ALLEGRO_STATICLINK
   #define ALLEGRO_PLATFORM_STR  "MinGW32.s"
#else
   #define ALLEGRO_PLATFORM_STR  "MinGW32"
#endif

#define ALLEGRO_WINDOWS
#define ALLEGRO_I386
#define ALLEGRO_LITTLE_ENDIAN

#ifdef ALLEGRO_USE_CONSOLE
   #define ALLEGRO_allegro5_MAGIC_MAIN
#endif


/* describe how function prototypes look to MINGW32 */
#if (defined ALLEGRO_STATICLINK) || (defined ALLEGRO_SRC)
   #define _allegro5_DLL
#else
   #define _allegro5_DLL   __declspec(dllimport)
#endif

#define AL_VAR(type, name)                   extern _allegro5_DLL type name
#define AL_ARRAY(type, name)                 extern _allegro5_DLL type name[]
#define AL_FUNC(type, name, args)            extern type name args
#define AL_METHOD(type, name, args)          type (*name) args
#define AL_FUNCPTR(type, name, args)         extern _allegro5_DLL type (*name) args


/* windows specific defines */

#if (defined ALLEGRO_SRC)
/* pathches to handle DX7 headers on a win9x system */

/* should WINNT be defined on win9x systems? */
#ifdef WINNT
   #undef WINNT
#endif

/* defined in windef.h */
#ifndef HMONITOR_DECLARED
   #define HMONITOR_DECLARED 1
#endif

#endif /* ALLEGRO_SRC */

/* another instance of missing constants in the mingw32 headers */
#ifndef ENUM_CURRENT_SETTINGS
   #define ENUM_CURRENT_SETTINGS       ((DWORD)-1)
#endif

/* arrange for other headers to be included later on */
#define ALLEGRO_EXTRA_HEADER     "./platform/alwin.h"
#define ALLEGRO_INTERNAL_HEADER  "./platform/aintwin.h"
#define ALLEGRO_INTERNAL_THREAD_HEADER "./platform/aintwthr.h"
