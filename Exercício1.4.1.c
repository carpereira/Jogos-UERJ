#include <SDL2/SDL.h>


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         200, 200, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    

    /* EXECUÇÃO */
    SDL_Rect r = { 100,100, 20,20 };
    //SDL_Rect s = { 100,100, 10,10 };
    
    
    SDL_Event evt;
    while (1) {        
        SDL_SetRenderDrawColor(ren, 255,255,255,0);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r);
        //SDL_RenderFillRect(ren, &s);
        SDL_RenderPresent(ren);
        
        SDL_WaitEvent(&evt);        
        if (evt.type == SDL_QUIT){
            break;
        }

            
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            r.x=evt.motion.x, r.y=evt.motion.y;
        }
        if (evt.type == SDL_MOUSEBUTTONUP){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 255,0,0,0);
            SDL_RenderFillRect(ren, &r);
            SDL_RenderPresent(ren);            
            r.x, r.y;
            //SDL_Delay(300);
            
        }
     
                  
       if (evt.type == SDL_MOUSEBUTTONDOWN){
            r.x=evt.motion.x, r.y=evt.motion.y;
       }
        if (evt.type == SDL_MOUSEBUTTONUP){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 0,0,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
            r.x, r.y;
            //SDL_Delay(300);
            
        }
                 
           /*if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 0,255,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
        
         if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 255,255,0,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
        
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 255,0,0,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
            
         if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 0,255,0,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
        
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 200,0,100,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
        
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 0,100,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
        
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 100,100,100,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }
        
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);              
            SDL_RenderClear(ren);            
            SDL_SetRenderDrawColor(ren, 100,0,100,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_Delay(200);
        }*/
        
        if (evt.type == SDL_KEYDOWN) {            
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    if (r.y>0){
                        r.y -= 5;
                        break;}
                    else {r.y=0;    
                        break;}
                case SDLK_DOWN:
                    if(r.y<190){
                        r.y += 5;
                        break;}
                    else {r.y=190;
                        break;}
                case SDLK_LEFT:
                    if(r.x>0){
                        r.x -= 5;
                        break;}
                    else {r.x>0;
                        break;}
                case SDLK_RIGHT:
                    if(r.x<190){
                        r.x += 5;
                    break;}
                    else {r.x=190;
                        break;}                    
            }
        }
    }
        
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
     
