#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Animando e Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         300, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = { 20,20, 10,10 };
    
    SDL_SetRenderDrawColor(ren, 255,255,255,0);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0,0,255,0);
    SDL_RenderFillRect(ren, &r);
    SDL_RenderPresent(ren);      

    SDL_Event evt;
    while(1){
        int isevt = SDL_WaitEventTimeout(&evt,500);
        if(isevt){
        switch (evt.type){
            case SDL_QUIT:                
                break;
            case SDL_KEYDOWN:
                if(r.y<280){
                    SDL_SetRenderDrawColor(ren, 255,255,255,0);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 255,0,0,0);
                    SDL_RenderFillRect(ren,&r);
                    SDL_RenderPresent(ren);
                    r.y += 2;
                    break;}
        
            //case SDL_KEYDOWN:
                if (r.x<280);{
                    SDL_SetRenderDrawColor(ren, 255,255,255,0);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 0,255,0,0);
                    SDL_RenderFillRect(ren,&r);
                    SDL_RenderPresent(ren);
                    r.x += 2;       
                    break;}
                
            //case SDL_KEYDOWN:
                if (r.y>20);{
                    SDL_SetRenderDrawColor(ren, 255,255,255,0);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 0,255,0,0);
                    SDL_RenderFillRect(ren,&r);
                    SDL_RenderPresent(ren);
                    r.y -= 2;       
                    break;}
                
            //case SDL_KEYDOWN:
                if (r.x>20);{
                    SDL_SetRenderDrawColor(ren, 255,255,255,0);
                    SDL_RenderClear(ren);
                    SDL_SetRenderDrawColor(ren, 255,0,255,0);
                    SDL_RenderFillRect(ren,&r);
                    SDL_RenderPresent(ren);
                    r.x -= 2;
                    break;}
        }
           
               }
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
