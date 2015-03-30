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
 *      MacOS X specific header defines.
 *
 *      By Angelo Mottola.
 *
 *      See readme.txt for copyright information.
 */


#ifndef __allegro5_included_allegro5_alosx_h
#define __allegro5_included_allegro5_alosx_h

#ifndef ALLEGRO_MACOSX
   #error bad include
#endif



#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#if defined __OBJC__ && defined ALLEGRO_SRC
   #import <mach/mach.h>
   #import <mach/mach_error.h>
   #import <AppKit/AppKit.h>
   #import <ApplicationServices/ApplicationServices.h>
   #import <Cocoa/Cocoa.h>
   #import <CoreAudio/CoreAudio.h>
   #import <AudioUnit/AudioUnit.h>
   #import <AudioToolbox/AudioToolbox.h>
   #import <QuickTime/QuickTime.h>
   #import <IOKit/IOKitLib.h>
   #import <IOKit/IOCFPlugIn.h>
   #import <IOKit/hid/IOHIDLib.h>
   #import <IOKit/hid/IOHIDKeys.h>
   #import <Kernel/IOKit/hidsystem/IOHIDUsageTables.h>
#endif

ALLEGRO_PATH *_allegro5_osx_get_path(int id);

#ifndef ALLEGRO_LIB_BUILD
   #ifndef ALLEGRO_allegro5_MAGIC_MAIN
      #define ALLEGRO_MAGIC_MAIN
      #if __GNUC__ >= 4
         #define main __attribute__ ((visibility("default"))) _allegro5_mangled_main
      #else
         #define main _allegro5_mangled_main
      #endif
      #ifdef __cplusplus
         extern "C" int _allegro5_mangled_main(int, char **);
      #endif
   #endif
#endif

/* Keyboard driver */
#define KEYBOARD_MACOSX         AL_ID('O','S','X','K')

#endif

/* Local variables:       */
/* mode: objc             */
/* c-basic-offset: 3      */
/* indent-tabs-mode: nil  */
/* End:                   */
/* vim: set sts=3 sw=3 et: */
