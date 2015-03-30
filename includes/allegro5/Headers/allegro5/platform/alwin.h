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
 *      Windows-specific header defines.
 *
 *      By Shawn Hargreaves.
 *
 *      See readme.txt for copyright information.
 */


#ifndef ALLEGRO_WINDOWS
   #error bad include
#endif

#include <windows.h>

/*******************************************/
/********** magic main emulation ***********/
/*******************************************/
#ifdef __cplusplus
extern "C" {
#endif

AL_FUNC(int, _WinMain, (void *_main, void *hInst, void *hPrev, char *Cmd, int nShow));

#ifdef __cplusplus
}
#endif


/* The following is due to torhu from A.cc (see
 * http://www.allegro.cc/forums/thread/596872/756993#target)
 */
#ifndef ALLEGRO_allegro5_MAGIC_MAIN
   #if defined _MSC_VER && !defined ALLEGRO_LIB_BUILD
      #pragma comment(linker,"/ENTRY:mainCRTStartup")
   #endif
#endif


/*******************************************/
/************ joystick drivers *************/
/*******************************************/
#define AL_JOY_TYPE_DIRECTX      AL_ID('D','X',' ',' ')

AL_VAR(struct ALLEGRO_JOYSTICK_DRIVER, _allegro5_joydrv_directx);

#define _allegro5_JOYSTICK_DRIVER_DIRECTX                                     \
   { AL_JOY_TYPE_DIRECTX,  &_allegro5_joydrv_directx,    true  },

