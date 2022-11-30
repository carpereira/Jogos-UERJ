#include <SDL2/SDL.h>


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Aplicação Tres Retângulos",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 200, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    

    /* EXECUÇÃO */
    SDL_Rect r = { 100,10, 20,20 }; 
    SDL_Rect s = { 50,50, 30,40 };
    SDL_Rect t = { 150,100, 50,20 };
    
    //SDL_Event evt;
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
        
        SDL_Event evt;
        
        int isevt = SDL_WaitEventTimeout(&evt,500);
        if(isevt){
            if(evt.type == SDL_KEYDOWN){
                SDL_SetRenderDrawColor(ren, 255,0,0,0);
                SDL_RenderFillRect(ren, &r);                
            }
        }
            else{
                r.x +=2;
                r.y +=2;
            }                
              
        if (evt.type == SDL_QUIT){
            break;
        }        
                     
        if (evt.type == SDL_MOUSEMOTION){
            s.x=evt.motion.x, s.y=evt.motion.y;          
        }
                
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
     
