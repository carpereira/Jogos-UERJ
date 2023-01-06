#include <SDL2/SDL.h>
#include <stdlib.h>
#include <SDL_ttf.h>


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Int();
    SDL_Window* win = SDL_CreateWindow("Linha de chegada com Tres Retângulos",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         300, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    

    /* EXECUÇÃO */
    SDL_Rect r = { 50,280, 20,20 }; 
    SDL_Rect s = { 140,260, 30,40 };
    SDL_Rect t = { 240,280, 50,20 };
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
                    r.y -=5;}
                    //else{
                        //printf("Azul");
                }
                if(s.y>35){
                    s.y -=4;}
                    //else{
                        //printf("Verde");
                    }
                if(t.y>35){
                t.y -=2;}
                //else{
                    //printf("Vermelho");
            }
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
        
        if(evt.type ==  SDL_MOUSEMOTION){
            if(s.y>35){
                s.x=evt.motion.x, s.y=evt.motion.y;}
            else{s.y=35;                 
            }
        }
        if  (evt.type == SDL_KEYDOWN){
            switch (evt.key.keysym.sym){
                case SDLK_UP:
                    if(t.y>35){
                        t.y -=5;
                        break;}
                    else {t.y=35;
                          break;}
                case SDLK_DOWN:
                    if(t.y<280){
                        t.y +=5;
                        break;}
                    else {t.y=280;
                          break;}
               case SDLK_LEFT:
                    if(t.x>0){
                        t.x -=5;
                        break;}
                    else {t.x=0; 
                          break;}
               case SDLK_RIGHT:
                    if(t.x<250){
                        t.x +=5;
                        break;}
                    else {t.x=250;
                          break;}
    }
        }
    }
        
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    TTF_CloseFont(font);
}
 
