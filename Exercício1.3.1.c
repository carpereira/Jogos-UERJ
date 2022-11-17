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

SDL_Rect r={40,20,10,10}
  while (r.x<100){
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(ren,&r);
      
   SDL_RenderPresent(ren);
   SDL_Delay(9000);
    r.x +=2;
    r.y +=2;
  }    

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
