#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Animando e Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 100, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = { 40,20, 10,10 };
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        
        if (evt.type == SDL_QUIT){
            break;
        } 
        
        int isevt = SDL_WaitEventTimeout(&evt, 500);
        if (isevt) {
            if (evt.type == SDL_KEYDOWN) {
                switch (evt.key.keysym.sym) {
                    case SDLK_UP:
                        r.y -= 5;
                        break;
                    case SDLK_DOWN:
                        r.y += 5;
                        break;
                    case SDLK_LEFT:
                        r.x -= 5;
                        break;
                    case SDLK_RIGHT:
                        r.x += 5;
                        break;
                }
            }
        } else {
            r.x += 2;
            r.y += 2;
        }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
