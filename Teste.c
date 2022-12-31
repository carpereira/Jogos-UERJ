#include <SDL2/SDL.h>


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Linha de chegada com Tres Retângulos",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         300, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    

    /* EXECUÇÃO */
    SDL_Rect r = { 80,280, 20,20 }; 
    SDL_Rect s = { 160,280, 20,20 };
    SDL_Rect t = { 240,280, 20,20 };
    SDL_Rect w = {0,30,300,5};
   
    while (1) {        
        /*SDL_SetRenderDrawColor(ren, 255,255,255,0);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r);
        SDL_SetRenderDrawColor(ren, 0,255,0,0);
        SDL_RenderFillRect(ren, &s);
        SDL_SetRenderDrawColor(ren, 255,0,0,0);
        SDL_RenderFillRect(ren, &t);
        SDL_RenderPresent(ren);
        SDL_SetRenderDrawColor(ren, 255,0,255,0);
        SDL_RenderFillRect(ren, &w);
        SDL_RenderPresent(ren);*/
        
        SDL_Event evt;
        if (r.y>35 | s.y>35 | t.y>35){
        int isevt = SDL_WaitEventTimeout(&evt,500);
        if(isevt){
            if(evt.type == SDL_MOUSEBUTTONDOWN){
                SDL_SetRenderDrawColor(ren, 255,255,255,0);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren, 0,0,255,0);
                SDL_RenderFillRect(ren, &r);
                
                SDL_SetRenderDrawColor(ren, 0,255,0,0);
                SDL_RenderFillRect(ren, &s);
                
                SDL_SetRenderDrawColor(ren, 255,0,0,0);
                SDL_RenderFillRect(ren, &t);
                SDL_RenderPresent(ren);                
            }
        }
            else{
                if(r.y>35){
                    r.y -=5;
                }
                if(s.y>35){
                    s.y -=4;
                    }
                if(t.y>35){
                t.y -=2;}
            }
        }
        else{
            SDL_SetRenderDrawColor(ren, 255,255,255,0);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0,0,255,0);
            SDL_RenderFillRect(ren, &r);
            r.x=80, r.y=280;
            SDL_SetRenderDrawColor(ren, 0,255,0,0);
            SDL_RenderFillRect(ren, &s);
            s.x=160, s.y=280;
            SDL_SetRenderDrawColor(ren, 255,0,0,0);
            SDL_RenderFillRect(ren, &t);
            t.x=240, t.y=280;
            SDL_RenderPresent(ren);}
              
        if (evt.type == SDL_QUIT){
            break;
        }        
    }
        
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
 
