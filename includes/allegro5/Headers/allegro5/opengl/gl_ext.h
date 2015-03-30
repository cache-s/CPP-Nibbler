
#ifndef __al_included_allegro5_gl_ext_h
#define __al_included_allegro5_gl_ext_h


/*
 * MSVC declares the following extensions and MinGW doesn't. In order to
 * export the same symbols on both platforms we removed the extensions from
 * MSVC.
 */
#ifdef ALLEGRO_MSVC
   #undef GL_EXT_vertex_array
   #undef GL_EXT_paletted_texture
   #undef GL_WIN_swap_hint
   #undef GL_WIN_draw_range_elements
#endif

/* GL extension definitions. */

/* For example:
 *
 * #define GL_BGRA 0x80E1
 *
 */

#if !defined(ALLEGRO_GP2XWIZ) && !defined(ALLEGRO_IPHONE)
#include "./opengl/GLext/gl_ext_defs.h"
#endif
#if defined ALLEGRO_WINDOWS && !defined ALLEGRO_EXCLUDE_WGL
#include "./opengl/GLext/wgl_ext_defs.h"
#elif defined ALLEGRO_UNIX && !defined ALLEGRO_EXCLUDE_GLX
#include "./opengl/GLext/glx_ext_defs.h"
#endif

/* GL extension types */

/* For example:
 *
 * typedef void (APIENTRY * _ALLEGRO_glBlendEquation_t (GLenum);
 *
 */
 
#ifndef APIENTRY
#define APIENTRY
#define APIENTRY_defined
#endif

#define AGL_API(type, name, args) typedef type (APIENTRY * _ALLEGRO_gl##name##_t) args;
#	include "./opengl/GLext/gl_ext_api.h"
#undef AGL_API
#ifdef ALLEGRO_WINDOWS
#define AGL_API(type, name, args) typedef type (APIENTRY * _ALLEGRO_wgl##name##_t) args;
#	include "./opengl/GLext/wgl_ext_api.h"
#undef AGL_API
#elif defined ALLEGRO_UNIX
#define AGL_API(type, name, args) typedef type (APIENTRY * _ALLEGRO_glX##name##_t) args;
#	include "./opengl/GLext/glx_ext_api.h"
#undef AGL_API
#endif

#ifdef APIENTRY_defined
#undef APIENTRY
#undef APIENTRY_defined
#endif

/* GL extension declarations */

/* For example:
 *
 * #define glBlendEquation _al_glBlendEquation
 * extern _ALLEGRO_glBlendEquation_t _al_glBlendEquation;
 *
 */

#define AGL_API(type, name, args) AL_VAR(_ALLEGRO_gl##name##_t, _al_gl##name);
# 	include "./opengl/GLext/gl_ext_alias.h"
#	include "./opengl/GLext/gl_ext_api.h"
#undef AGL_API
#ifdef ALLEGRO_WINDOWS
#define AGL_API(type, name, args) AL_VAR(_ALLEGRO_wgl##name##_t, _al_wgl##name);
# 	include "./opengl/GLext/wgl_ext_alias.h"
#	include "./opengl/GLext/wgl_ext_api.h"
#undef AGL_API
#elif defined ALLEGRO_UNIX
#define AGL_API(type, name, args) extern _ALLEGRO_glX##name##_t _al_glX##name;
# 	include "./opengl/GLext/glx_ext_alias.h"
#	include "./opengl/GLext/glx_ext_api.h"
#undef AGL_API
#endif

/* A list of all supported extensions.
 *
 * For example:
 * int ALLEGRO_GL_ARB_imaging;
 *
 */

typedef struct ALLEGRO_OGL_EXT_LIST {
#    define AGL_EXT(name, ver) int ALLEGRO_GL_##name;
#    include "./opengl/GLext/gl_ext_list.h"
#    undef  AGL_EXT

#ifdef ALLEGRO_UNIX
#    define AGL_EXT(name, ver) int ALLEGRO_GLX_##name;
#    include "./opengl/GLext/glx_ext_list.h"
#    undef  AGL_EXT
#elif defined ALLEGRO_WINDOWS
#    define AGL_EXT(name, ver) int ALLEGRO_WGL_##name;
#    include "./opengl/GLext/wgl_ext_list.h"
#    undef  AGL_EXT

#endif
} ALLEGRO_OGL_EXT_LIST;


/* GL extension Structure. Holds the pointers to all the functions
 * of all extensions, for a single context.
 *
 * Example:
 * ALLEGRO_BlendEquation_t BlendEquation;
 */
typedef struct ALLEGRO_OGL_EXT_API {
#define AGL_API(type, name, args) _ALLEGRO_gl##name##_t name;
#	include "./opengl/GLext/gl_ext_api.h"
#undef AGL_API
#ifdef ALLEGRO_WINDOWS
#define AGL_API(type, name, args) _ALLEGRO_wgl##name##_t name;
#	include "./opengl/GLext/wgl_ext_api.h"
#undef AGL_API
#elif defined ALLEGRO_UNIX
#define AGL_API(type, name, args) _ALLEGRO_glX##name##_t name;
#	include "./opengl/GLext/glx_ext_api.h"
#undef AGL_API
#endif
} ALLEGRO_OGL_EXT_API;



#endif
