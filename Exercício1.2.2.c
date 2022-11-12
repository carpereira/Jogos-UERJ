#ifndef _SDL2_gfxPrimitives_h
#define _SDL2_gfxPrimitives_h
#endif

#include <math.h>
#ifndef M_PI
#define M_PI	3.1415926535897932384626433832795
#endif

#include <SDL2/SDL.h>

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
                      500, 500, SDL_WINDOW_SHOWN
                      );
SDL_Renderer* ren = SDL_CreateRenderer(win, -1,0);
	
SDL_Surface*s;
s=SDL_CreateRGBSurface(0,300,200,32,0,0,0,0);

/*EXECUÇÂO*/
 
/* Note: all ___Color routines expect the color to be in format 0xRRGGBBAA */
SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0x00);
SDL_RenderClear(ren);
 
/* Pixel */
 
SDL2_GFXPRIMITIVES_SCOPE int pixelColor(SDL_Renderer * renderer, Sint16 200, Sint16 200, Uint32 255)
{
	Uint8 *c = (Uint8 *)&color;
	return pixelRGBA(renderer,200,200, c[0],c[1],c[2],c[3]);
}
SDL2_GFXPRIMITIVES_SCOPE int pixelRGBA(SDL_Renderer * renderer, Sint16 200, Sint16 200, Uint8 255, Uint8 255, Uint8 255, Uint8 0);
{
	
}
	
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
	
SDL_FillRect(s,NULL,SDL_MapRGB(s->format,0xFF,0x00,0x00));
SDL_UpdateWindowSurface(window);
   
  
SDL_RenderPresent(ren);
SDL_Delay(9000);

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
