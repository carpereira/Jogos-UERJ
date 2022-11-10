#define SDL2_GFXPRIMITIVES_SCOPE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//#include <SDL_rotozoom.h>
#include "SDL2_gfxPrimitives.h"
#include "SDL2_gfxPrimitives_font.h"

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

/*EXECUÇÃO*/
SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
SDL_RenderClear(ren);
/*circulo*/  
SDL2_GFXPRIMITIVES_SCOPE int aacircleColor(SDL_Renderer * renderer,200,200,30,0xFF);
   
  
SDL_RenderPresent(ren);
SDL_Delay(9000);

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
