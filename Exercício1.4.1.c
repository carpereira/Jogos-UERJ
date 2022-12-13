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
    SDL_SetRenderDrawColor(ren, 255,255,255,0);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0,0,255,0);
    SDL_RenderFillRect(ren, &r);       
    SDL_RenderPresent(ren);    
    
    SDL_Event evt;
   while (1) {
               
        //while (SDL_PollEvent(&evt)){ 
       SDL_WaitEvent(&evt);
       //SDL_PollEvent(&evt);
        
        if (evt.type == SDL_QUIT){
            break;
        }
            
        int isevt = SDL_WaitEventTimeout(&evt, 1000);
        if (isevt){
       SDL_WaitEvent(&evt);
            if (evt.type == SDL_MOUSEBUTTONDOWN){                
                        r.x=evt.motion.x, r.y=evt.motion.y;   
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                        SDL_SetRenderDrawColor(ren, 255,0,0,0);            
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
            if (evt.type == SDL_MOUSEBUTTONDOWN){
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);            
            SDL_SetRenderDrawColor(ren, 0,255,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
        }    
    /*//case 4:             
            if (evt.type == SDL_MOUSEBUTTONDOWN){   
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);            
            SDL_SetRenderDrawColor(ren, 255,0,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
            }        
//case 5:                
            if (evt.type == SDL_MOUSEBUTTONDOWN){
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);             
            SDL_SetRenderDrawColor(ren, 255,0,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
        }*/            
        /*case 6:
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);                        
            SDL_SetRenderDrawColor(ren, 255,50,100,0);           
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
        //}
        case 7:
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);             
            SDL_SetRenderDrawColor(ren, 200,0,100,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
        //}
        case 8:
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);             
            SDL_SetRenderDrawColor(ren, 0,100,255,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);
            //}        
        case 9:
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);            
            SDL_SetRenderDrawColor(ren, 100,100,100,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
        //}
        case 10:
            r.x=evt.motion.x, r.y=evt.motion.y;
            SDL_SetRenderDrawColor(ren, 255,255,255,0);            
            SDL_SetRenderDrawColor(ren, 100,0,100,0);            
            SDL_RenderFillRect(ren, &r);            
            SDL_RenderPresent(ren);            
        //} */                
                      }                   
            //}
        //}
    }
   
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
   
