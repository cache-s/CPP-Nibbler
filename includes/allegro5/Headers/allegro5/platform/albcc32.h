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
 *      Configuration defines for use with Borland C++Builder.
 *
 *      By Greg Hackmann.
 *
 *      See readme.txt for copyright information.
 */


/*
#ifdef ALLEGRO_SRC
   #error Currently BCC32 cannot build the library
#endif
*/


#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <malloc.h>


#pragma warn -8004  /* unused assigned value         */
#pragma warn -8008  /* condition always met          */
#pragma warn -8057  /* unused parameter              */
#pragma warn -8066  /* unreachable code              */


/* describe this platform */
#define ALLEGRO_PLATFORM_STR  "BCC32"
#define ALLEGRO_WINDOWS
#define ALLEGRO_I386
#define ALLEGRO_LITTLE_ENDIAN
#define ALLEGRO_GUESS_INTTYPES_OK
   /* TODO: check if BCC has inttypes.h and/or stdint.h */

#ifdef ALLEGRO_USE_CONSOLE
   #define ALLEGRO_allegro5_MAGIC_MAIN
#endif


/* describe how function prototypes look to BCC32 */
#if (defined ALLEGRO_STATICLINK)
   #define _allegro5_DLL
#elif (defined ALLEGRO_SRC)
   #define _allegro5_DLL   __declspec(dllexport)
#else
   #define _allegro5_DLL   __declspec(dllimport)
#endif

#define AL_VAR(type, name)             extern _allegro5_DLL type name
#define AL_ARRAY(type, name)           extern _allegro5_DLL type name[]
#define AL_FUNC(type, name, args)      extern _allegro5_DLL type name args
#define AL_METHOD(type, name, args)    type (*name) args
#define AL_FUNCPTR(type, name, args)   extern _allegro5_DLL type (*name) args


#define END_allegro5_INLINE(name)
//#define AL_INLINE(type, name, args, code)    extern __inline type name args code END_allegro5_INLINE(name)

#define INLINE       __inline

#undef AL_INLINE
#undef AL_INLINE_STATIC

#define AL_INLINE(type, name, args, code)        extern __inline type __cdecl name args code END_allegro5_INLINE(name)
#define AL_INLINE_STATIC(type, name, args, code) static __inline type name args code END_allegro5_INLINE(name)

#define LONG_LONG    __int64
#define int64_t      signed __int64
#define uint64_t     unsigned __int64

#define __func__  "FIXME"

#define _wfindfirst __wfindfirst
#define _wfindnext __wfindnext

#define WinMain _main

/* windows specific defines */
#ifdef NONAMELESSUNION
   #undef NONAMELESSUNION
#endif
/* This fixes 99.999999% of Borland C++Builder's problems with structs. */

/* arrange for other headers to be included later on */
#define ALLEGRO_EXTRA_HEADER     "./platform/alwin.h"
#define ALLEGRO_INTERNAL_HEADER  "./platform/aintwin.h"
#define ALLEGRO_INTERNAL_THREAD_HEADER "./platform/aintwthr.h"
