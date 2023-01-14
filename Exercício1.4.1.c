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
    SDL_Rect r = { 100,100, 10,10 };    
         
    SDL_Event evt;    
    
    SDL_SetRenderDrawColor(ren, 255,255,255,0);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0,0,255,0);
    SDL_RenderFillRect(ren, &r);       
    SDL_RenderPresent(ren);    
    
        while (1) {                      
        SDL_WaitEvent(&evt); 
        while(SDL_PollEvent(&evt) !=0){
            
        if (evt.type == SDL_MOUSEBUTTONDOWN){             
            r.x=evt.motion.x, r.y=evt.motion.y;            
            SDL_SetRenderDrawColor(ren, 255,255,255,0);                
            SDL_SetRenderDrawColor(ren, 255,255,0,0);            
            SDL_RenderFillRect(ren, &r);                
            SDL_RenderPresent(ren);            
        }      
                        
        if (evt.type == SDL_MOUSEBUTTONDOWN){                        
            r.x=evt.motion.x, r.y=evt.motion.y;            
            SDL_SetRenderDrawColor(ren, 255,255,255,0);                
            SDL_SetRenderDrawColor(ren, 0,255,0,0);            
            SDL_RenderFillRect(ren, &r);                
            SDL_RenderPresent(ren);            
        }    
                        
        if  (evt.type == SDL_MOUSEBUTTONDOWN){                        
            r.x=evt.motion.x, r.y=evt.motion.y;            
            SDL_SetRenderDrawColor(ren, 255,255,255,0);                
            SDL_SetRenderDrawColor(ren, 255,0,0,0);            
            SDL_RenderFillRect(ren, &r);                
            SDL_RenderPresent(ren);            
        }            
                
        if(evt.type == SDL_MOUSEBUTTONDOWN){           
                r.x=evt.motion.x, r.y=evt.motion.y;            
                SDL_SetRenderDrawColor(ren, 255,255,255,0);             
                SDL_SetRenderDrawColor(ren, 176,224,230,0);            
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
            }
        
        if(evt.type == SDL_MOUSEBUTTONDOWN){          
                r.x=evt.motion.x, r.y=evt.motion.y;            
                SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                SDL_SetRenderDrawColor(ren, 216,191,216,0);            
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
        }
        
        if(evt.type == SDL_MOUSEBUTTONDOWN){                
                (r.x=evt.motion.x, r.y=evt.motion.y);            
                SDL_SetRenderDrawColor(ren, 255,255,255,0);                       
                SDL_SetRenderDrawColor(ren, 255,165,0,0);           
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
        }
        
        if(evt.type == SDL_MOUSEBUTTONDOWN){               
                (r.x=evt.motion.x, r.y=evt.motion.y);            
                SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                SDL_SetRenderDrawColor(ren, 255,105,180,0);            
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
        }
        
        if(evt.type == SDL_MOUSEBUTTONDOWN){               
                (r.x=evt.motion.x, r.y=evt.motion.y);            
                SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                SDL_SetRenderDrawColor(ren, 245,222,179,0);            
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
            }
         
    if(evt.type == SDL_MOUSEBUTTONDOWN){               
                (r.x=evt.motion.x, r.y=evt.motion.y);        
                SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                SDL_SetRenderDrawColor(ren, 173,255,47,0);            
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
        }
           
        if(evt.type == SDL_MOUSEBUTTONDOWN){               
                (r.x=evt.motion.x, r.y=evt.motion.y);            
                SDL_SetRenderDrawColor(ren,255,255,255,0);           
                SDL_SetRenderDrawColor(ren, 127,255,212,0);            
                SDL_RenderFillRect(ren, &r);                
                SDL_RenderPresent(ren);                
        }
        }
         
        if (evt.type == SDL_QUIT){
            break;
        }
                  
        if (evt.type == SDL_KEYDOWN) {             
            SDL_SetRenderDrawColor(ren, 255,255,255,0);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0,0,255,0);
            SDL_RenderFillRect(ren, &r);       
            SDL_RenderPresent(ren); 
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    if (r.y>0){
                        r.y -= 5;
                        break;}
                case SDLK_DOWN:
                    if(r.y<190){
                        r.y += 5;
                        break;}
                case SDLK_LEFT:
                    if(r.x>0){
                        r.x -= 5;
                        break;}
                case SDLK_RIGHT:
                    if(r.x<190){
                        r.x += 5;
                    break;}                    
            }
        }
        }
    

   
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
   
