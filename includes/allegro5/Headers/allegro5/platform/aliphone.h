#ifndef ALLEGRO_IPHONE
   #error bad include
#endif

#ifndef ALLEGRO_LIB_BUILD
#define ALLEGRO_MAGIC_MAIN
#define main _allegro5_mangled_main
#ifdef __cplusplus
   extern "C" int _allegro5_mangled_main(int, char **);
#endif
#endif
