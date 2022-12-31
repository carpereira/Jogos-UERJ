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
        SDL_SetRenderDrawColor(ren, 255,255,255,0);
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
        SDL_RenderPresent(ren);
        
        SDL_Event evt;
        
        int isevt = SDL_WaitEventTimeout(&evt,500);
        if(isevt){
            if(evt.type == SDL_MOUSEBUTTONDOWN){
                SDL_SetRenderDrawColor(ren, 255,255,255,0);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren, 255,0,0,0);
                SDL_RenderFillRect(ren, &r);
                
                SDL_SetRenderDrawColor(ren, 0,255,0,0);
                SDL_RenderFillRect(ren, &s);
                
                SDL_SetRenderDrawColor(ren, 255,0,0,0);
                SDL_RenderFillRect(ren, &t);
                SDL_RenderPresent(ren);                
            }
        }
            else{
                if(r.y>30){
                    r.y -=5;
                }
                if(s.y>30){
                    s.y -=4;
                    }
                if(t.y>30){
                t.y -=2;}
            }                
              
        if (evt.type == SDL_QUIT){
            break;
        }        
                     
        //if (evt.type == SDL_MOUSEMOTION){
           // s.x=evt.motion.x, s.y=evt.motion.y;          
        //}
                
        if (evt.type == SDL_KEYDOWN) {            
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    if (t.y>0){
                        t.y -= 5;
                        break;}
                    else {t.y=0;    
                        break;}
                case SDLK_DOWN:
                    if(t.y<180){
                        t.y += 5;
                        break;}
                    else {t.y=180;
                        break;}
                case SDLK_LEFT:
                    if(t.x>0){
                        t.x -= 5;
                        break;}
                    else {t.x>0;
                        break;}
                case SDLK_RIGHT:
                    if(t.x<150){
                        t.x += 5;
                    break;}
                    else {t.x=150;
                        break;}                    
            }
        }
    }
        
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
 
