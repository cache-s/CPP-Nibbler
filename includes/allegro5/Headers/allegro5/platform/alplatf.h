/* alplatf.h is generated from alplatf.h.cmake */
/* #undef ALLEGRO_MINGW32 */
#define ALLEGRO_UNIX
/* #undef ALLEGRO_MSVC */
/* #undef ALLEGRO_CFG_D3D */
/* #undef ALLEGRO_CFG_D3D9EX */
#define ALLEGRO_CFG_OPENGL
/* #undef ALLEGRO_MACOSX */
/* #undef ALLEGRO_BCC32 */
/* #undef ALLEGRO_GP2XWIZ */
/* #undef ALLEGRO_IPHONE */
/* #undef ALLEGRO_CFG_allegro5_FPU */
/* #undef ALLEGRO_CFG_DLL_TLS */
/* #undef ALLEGRO_CFG_PTHREADS_TLS */

/*---------------------------------------------------------------------------*/

/* Define to 1 if you have the corresponding header file. */
#define ALLEGRO_HAVE_DIRENT_H
#define ALLEGRO_HAVE_INTTYPES_H
/* #undef ALLEGRO_HAVE_LINUX_AWE_VOICE_H */
/* #undef ALLEGRO_HAVE_LINUX_INPUT_H */
#define ALLEGRO_HAVE_LINUX_JOYSTICK_H
#define ALLEGRO_HAVE_LINUX_SOUNDCARD_H
/* #undef ALLEGRO_HAVE_MACHINE_SOUNDCARD_H */
/* #undef ALLEGRO_HAVE_SOUNDCARD_H */
#define ALLEGRO_HAVE_STDBOOL_H
#define ALLEGRO_HAVE_STDINT_H
/* #undef ALLEGRO_HAVE_allegro5_PROCFS_H */
#define ALLEGRO_HAVE_SYS_allegro5_H
#define ALLEGRO_HAVE_SYS_SOUNDCARD_H
#define ALLEGRO_HAVE_SYS_STAT_H
#define ALLEGRO_HAVE_SYS_TIME_H
#define ALLEGRO_HAVE_TIME_H
#define ALLEGRO_HAVE_SYS_UTSNAME_H
#define ALLEGRO_HAVE_SYS_TYPES_H
/* #undef ALLEGRO_HAVE_OSATOMIC_H */
#define ALLEGRO_HAVE_SYS_INOTIFY_H
#define ALLEGRO_HAVE_SYS_TIMERFD_H

/* Define to 1 if the corresponding functions are available. */
/* #undef ALLEGRO_HAVE_GETEXECNAME */
#define ALLEGRO_HAVE_MKSTEMP
#define ALLEGRO_HAVE_MMAP
#define ALLEGRO_HAVE_MPROTECT
#define ALLEGRO_HAVE_SCHED_YIELD
#define ALLEGRO_HAVE_SYSCONF
#define ALLEGRO_HAVE_FSEEKO
#define ALLEGRO_HAVE_FTELLO
#define ALLEGRO_HAVE_allegro5_COPY

/* Define to 1 if procfs reveals argc and argv */
/* #undef ALLEGRO_HAVE_PROCFS_ARGCV */

/*---------------------------------------------------------------------------*/

/* Define if target machine is little endian. */
#define ALLEGRO_LITTLE_ENDIAN

/* Define if target machine is big endian. */
/* #undef ALLEGRO_BIG_ENDIAN */

/* Define if target platform is Darwin. */
/* #undef ALLEGRO_DARWIN */

/*---------------------------------------------------------------------------*/

/* Define if you need support for X-Windows. */
#define ALLEGRO_WITH_XWINDOWS

/* Define if XCursor ARGB extension is available. */
#define ALLEGRO_XWINDOWS_WITH_XCURSOR

/* Define if XF86VidMode extension is supported. */
/* #undef ALLEGRO_XWINDOWS_WITH_XF86VIDMODE */

/* Define if Xinerama extension is supported. */
#define ALLEGRO_XWINDOWS_WITH_XINERAMA

/* Define if XRandR extension is supported. */
#define ALLEGRO_XWINDOWS_WITH_XRANDR

/* Define if XIM extension is supported. */
#define ALLEGRO_XWINDOWS_WITH_XIM

/*---------------------------------------------------------------------------*/

/* Define if target platform is linux. */
/* #undef ALLEGRO_LINUX */

/*---------------------------------------------------------------------------*/
/* vi: set ft=c ts=3 sts=3 sw=3 et: */
