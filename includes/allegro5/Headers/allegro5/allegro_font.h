#ifndef __al_included_allegro5_allegro_font_h
#define __al_included_allegro5_allegro_font_h

#include "./allegro.h"

#if (defined ALLEGRO_MINGW32) || (defined ALLEGRO_MSVC) || (defined ALLEGRO_BCC32)
   #ifndef ALLEGRO_STATICLINK
      #ifdef ALLEGRO_FONT_SRC
         #define _ALLEGRO_FONT_DLL __declspec(dllexport)
      #else
         #define _ALLEGRO_FONT_DLL __declspec(dllimport)
      #endif
   #else
      #define _ALLEGRO_FONT_DLL
   #endif
#endif

#if defined ALLEGRO_MSVC
   #define ALLEGRO_FONT_FUNC(type, name, args)      _ALLEGRO_FONT_DLL type __cdecl name args
   #define ALLEGRO_FONT_METHOD(type, name, args)    type (__cdecl *name) args
   #define ALLEGRO_FONT_FUNCPTR(type, name, args)   extern _ALLEGRO_FONT_DLL type (__cdecl *name) args
   #define ALLEGRO_FONT_PRINTFUNC(type, name, args, a, b)  ALLEGRO_FONT_FUNC(type, name, args)
#elif defined ALLEGRO_MINGW32
   #define ALLEGRO_FONT_FUNC(type, name, args)            extern type name args
   #define ALLEGRO_FONT_METHOD(type, name, args)          type (*name) args
   #define ALLEGRO_FONT_FUNCPTR(type, name, args)         extern _ALLEGRO_FONT_DLL type (*name) args
   #define ALLEGRO_FONT_PRINTFUNC(type, name, args, a, b) ALLEGRO_FONT_FUNC(type, name, args) __attribute__ ((format (printf, a, b)))
#elif defined ALLEGRO_BCC32
   #define ALLEGRO_FONT_FUNC(type, name, args)      extern _ALLEGRO_FONT_DLL type name args
   #define ALLEGRO_FONT_METHOD(type, name, args)    type (*name) args
   #define ALLEGRO_FONT_FUNCPTR(type, name, args)   extern _ALLEGRO_FONT_DLL type (*name) args
   #define ALLEGRO_FONT_PRINTFUNC(type, name, args, a, b)    ALLEGRO_FONT_FUNC(type, name, args)
#else
   #define ALLEGRO_FONT_FUNC      AL_FUNC
   #define ALLEGRO_FONT_METHOD    AL_METHOD
   #define ALLEGRO_FONT_FUNCPTR   AL_FUNCPTR
   #define ALLEGRO_FONT_PRINTFUNC AL_PRINTFUNC
#endif


#ifdef __cplusplus
   extern "C" {
#endif


/* Type: ALLEGRO_FONT
*/
typedef struct ALLEGRO_FONT ALLEGRO_FONT;
typedef struct ALLEGRO_FONT_VTABLE ALLEGRO_FONT_VTABLE;

struct ALLEGRO_FONT
{
   void *data;
   int height;
   ALLEGRO_FONT_VTABLE *vtable;
};

/* text- and font-related stuff */
struct ALLEGRO_FONT_VTABLE
{
   ALLEGRO_FONT_METHOD(int, font_height, (const ALLEGRO_FONT *f));
   ALLEGRO_FONT_METHOD(int, font_ascent, (const ALLEGRO_FONT *f));
   ALLEGRO_FONT_METHOD(int, font_descent, (const ALLEGRO_FONT *f));
   ALLEGRO_FONT_METHOD(int, char_length, (const ALLEGRO_FONT *f, int ch));
   ALLEGRO_FONT_METHOD(int, text_length, (const ALLEGRO_FONT *f, const ALLEGRO_USTR *text));
   ALLEGRO_FONT_METHOD(int, render_char, (const ALLEGRO_FONT *f, ALLEGRO_COLOR color, int ch, float x, float y));
   ALLEGRO_FONT_METHOD(int, render, (const ALLEGRO_FONT *f, ALLEGRO_COLOR color, const ALLEGRO_USTR *text, float x, float y));
   ALLEGRO_FONT_METHOD(void, destroy, (ALLEGRO_FONT *f));
   ALLEGRO_FONT_METHOD(void, get_text_dimensions, (const ALLEGRO_FONT *f,
      const ALLEGRO_USTR *text, int *bbx, int *bby, int *bbw, int *bbh));
};

enum {
   ALLEGRO_ALIGN_LEFT       = 0,
   ALLEGRO_ALIGN_CENTRE     = 1,
   ALLEGRO_ALIGN_CENTER     = 1,
   ALLEGRO_ALIGN_RIGHT      = 2,
   ALLEGRO_ALIGN_INTEGER    = 4
};

ALLEGRO_FONT_FUNC(bool, al_register_font_loader, (const char *ext, ALLEGRO_FONT *(*load)(const char *filename, int size, int flags)));
ALLEGRO_FONT_FUNC(ALLEGRO_FONT *, al_load_bitmap_font, (const char *filename));
ALLEGRO_FONT_FUNC(ALLEGRO_FONT *, al_load_font, (const char *filename, int size, int flags));

ALLEGRO_FONT_FUNC(ALLEGRO_FONT *, al_grab_font_from_bitmap, (ALLEGRO_BITMAP *bmp, int n, const int ranges[]));
ALLEGRO_FONT_FUNC(ALLEGRO_FONT *, al_create_builtin_font, (void));

ALLEGRO_FONT_FUNC(void, al_draw_ustr, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, ALLEGRO_USTR const *ustr));
ALLEGRO_FONT_FUNC(void, al_draw_text, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, char const *text));
ALLEGRO_FONT_FUNC(void, al_draw_justified_text, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, char const *text));
ALLEGRO_FONT_FUNC(void, al_draw_justified_ustr, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, ALLEGRO_USTR const *text));
ALLEGRO_FONT_PRINTFUNC(void, al_draw_textf, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x, float y, int flags, char const *format, ...), 6, 7);
ALLEGRO_FONT_PRINTFUNC(void, al_draw_justified_textf, (const ALLEGRO_FONT *font, ALLEGRO_COLOR color, float x1, float x2, float y, float diff, int flags, char const *format, ...), 8, 9);
ALLEGRO_FONT_FUNC(int, al_get_text_width, (const ALLEGRO_FONT *f, const char *str));
ALLEGRO_FONT_FUNC(int, al_get_ustr_width, (const ALLEGRO_FONT *f, const ALLEGRO_USTR *ustr));
ALLEGRO_FONT_FUNC(int, al_get_font_line_height, (const ALLEGRO_FONT *f));
ALLEGRO_FONT_FUNC(int, al_get_font_ascent, (const ALLEGRO_FONT *f));
ALLEGRO_FONT_FUNC(int, al_get_font_descent, (const ALLEGRO_FONT *f));
ALLEGRO_FONT_FUNC(void, al_destroy_font, (ALLEGRO_FONT *f));
ALLEGRO_FONT_FUNC(void, al_get_ustr_dimensions, (const ALLEGRO_FONT *f,
   ALLEGRO_USTR const *text,
   int *bbx, int *bby, int *bbw, int *bbh));
ALLEGRO_FONT_FUNC(void, al_get_text_dimensions, (const ALLEGRO_FONT *f,
   char const *text,
   int *bbx, int *bby, int *bbw, int *bbh));
ALLEGRO_FONT_FUNC(void, al_init_font_addon, (void));
ALLEGRO_FONT_FUNC(void, al_shutdown_font_addon, (void));
ALLEGRO_FONT_FUNC(uint32_t, al_get_allegro_font_version, (void));


#ifdef __cplusplus
   }
#endif

#endif
