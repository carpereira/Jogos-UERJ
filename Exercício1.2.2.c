#include <SDL2/SDL.h>
//#include <SDL2_gfxPrimitives.h>

#define SDL2_GFXPRIMITIVES_SCOPE

int main(int argc, char* args[])
{
/*INICIALIZAÇÃO*/
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Window* win = SDL_CreateWindow("Linhas pontos e retangulos!",
                      SDL_WINDOWPOS_UNDEFINED,
                      SDL_WINDOWPOS_UNDEFINED,
                      400, 400, SDL_WINDOW_SHOWN
                      );
SDL_Renderer* ren = SDL_CreateRenderer(win, -1,0);

/*EXECUÇÃO*/
SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
SDL_RenderClear(ren);
	
/*retangulo*/  
SDL2_GFXPRIMITIVES_SCOPE int rectColor(ren,40,20,100,100,255,0,0,0);
//SDL2_GFXPRIMITIVES_SCOPE int boxRGBA(ren,100,50,200,200,0x255);
SDL_RenderPresent(ren);
SDL_Delay(500);

SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
