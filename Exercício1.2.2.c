#ifndef _SDL2_gfxPrimitives_h
#define _SDL2_gfxPrimitives_h

#include <math.h>
#ifndef M_PI
#define M_PI	3.1415926535897932384626433832795
#endif

#include "SDL.h"

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

	/* ----- Versioning */

#define SDL2_GFXPRIMITIVES_MAJOR	1
#define SDL2_GFXPRIMITIVES_MINOR	0
#define SDL2_GFXPRIMITIVES_MICRO	2


	/* ---- Function Prototypes */

#ifdef _MSC_VER
#  if defined(DLL_EXPORT) && !defined(LIBSDL2_GFX_DLL_IMPORT)
#    define SDL2_GFXPRIMITIVES_SCOPE __declspec(dllexport)
#  else
#    ifdef LIBSDL2_GFX_DLL_IMPORT
#      define SDL2_GFXPRIMITIVES_SCOPE __declspec(dllimport)
#    endif
#  endif
#endif
#ifndef SDL2_GFXPRIMITIVES_SCOPE
#  define SDL2_GFXPRIMITIVES_SCOPE extern
#endif

int main(int argc, char* args[])
{
/*INICIALIZAÇÃO*/
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Window* win = SDL_CreateWindow("Figuras Complexas!",
                      SDL_WINDOWPOS_UNDEFINED,
                      SDL_WINDOWPOS_UNDEFINED,
                      400, 400, SDL_WINDOW_SHOWN
                      );
SDL_Renderer* ren = SDL_CreateRenderer(win, -1,0);

/*EXECUÇÂO*/
 
/* Note: all ___Color routines expect the color to be in format 0xRRGGBBAA */
 
/* Pixel */
 
SDL2_GFXPRIMITIVES_SCOPE int pixelColor(SDL_Renderer * renderer, Sint16 x, Sint16 y, Uint32 color);
SDL2_GFXPRIMITIVES_SCOPE int pixelRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
 
/* Horizontal line */
 
SDL2_GFXPRIMITIVES_SCOPE int hlineColor(SDL_Renderer * renderer, Sint16 x1, Sint16 x2, Sint16 y, Uint32 color);
SDL2_GFXPRIMITIVES_SCOPE int hlineRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 x2, Sint16 y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
 
/* Vertical line */
 
SDL2_GFXPRIMITIVES_SCOPE int vlineColor(SDL_Renderer * renderer, Sint16 x, Sint16 y1, Sint16 y2, Uint32 color);
SDL2_GFXPRIMITIVES_SCOPE int vlineRGBA(SDL_Renderer * renderer, Sint16 x, Sint16 y1, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
 
/* Rectangle */
 
SDL2_GFXPRIMITIVES_SCOPE int rectangleColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Uint32 color);
SDL2_GFXPRIMITIVES_SCOPE int rectangleRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1,
     Sint16 x2, Sint16 y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
 
/* Rounded-Corner Rectangle */
 
SDL2_GFXPRIMITIVES_SCOPE int roundedRectangleColor(SDL_Renderer * renderer, Sint16 x1, Sint16 y1, Sint16 x2, Sint16 y2, Sint16 rad, Uint32 color);
SDL2_GFXPRIMITIVES_SCOPE int roundedRectangleRGBA(SDL_Renderer * renderer, Sint16 x1, Sint16 y1,
Sint16 x2, Sint16 y2, Sint16 rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
   
  
SDL_RenderPresent(ren);
SDL_Delay(9000);

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
