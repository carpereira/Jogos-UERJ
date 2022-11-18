#include <SDL2/SDL.h>

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
SDL2_GFXPRIMITIVES_SCOPE int rectangleColor(SDL_Renderer * renderer, Sint16 100, Sint16 100,Sint16 200, Sint16 200, Uint32 255);
SDL2_GFXPRIMITIVES_SCOPE int rectangleRGBA(SDL_Renderer * renderer, Sint16 100, Sint16 100,Sint16 200, Sint16 200, Uint8 255, Uint8 0, Uint8 0, Uint8 0);
SDL_RenderPresent(ren);
SDL_Delay(500);

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
