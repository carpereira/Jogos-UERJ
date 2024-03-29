#include <SDL2/SDL.h>
#include <stdbool.h>

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
    bool quit = false;
    int a=0;

    /* EXECUÇÃO */
    SDL_Rect r = {100,100,10,10};
    SDL_Rect s = {100,100,10,10};
    SDL_Rect t = {100,100,10,10};
    
    SDL_Event evt;    
   
    SDL_SetRenderDrawColor(ren, 255,255,255,0);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0,0,255,0);
    SDL_RenderFillRect(ren, &r);       
    SDL_RenderPresent(ren);
    
    while(1){
                       
        SDL_WaitEvent(&evt);
        
        if(evt.type == SDL_QUIT){
                    quit = true;
                    break;}
        
        if(evt.type == SDL_KEYDOWN){
           if(a==0){
            SDL_SetRenderDrawColor(ren, 255,255,255,0);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0,0,255,0);
            SDL_RenderFillRect(ren, &r);       
            SDL_RenderPresent(ren);
            switch (evt.key.keysym.sym){                    
                    case SDLK_UP:
                    if (r.y>0){
                        r.y -= 5;
                        break;}
                    case SDLK_DOWN:
                    if (r.y<190){
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
            else{                
                SDL_SetRenderDrawColor(ren, 255,255,255,0);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren, 0,0,255,0);
                SDL_RenderFillRect(ren, &t);       
                SDL_RenderPresent(ren);                
                switch (evt.key.keysym.sym){
                        case SDLK_UP:
                        if (t.y>0){
                            t.y -= 5;
                            break;}
                        case SDLK_DOWN:
                        if (t.y<190){
                            t.y += 5;
                            break;}
                        case SDLK_LEFT:
                        if(t.x>0){
                            t.x -= 5;
                            break;}
                        case SDLK_RIGHT:
                        if(t.x<190){
                            t.x += 5;
                            break;} 
            }
            }
        }
                    
         if (evt.type == SDL_MOUSEBUTTONDOWN){
             if(a<10){
                 switch(a){
                         case 0:                         
                         if(s.x=evt.motion.x, s.y=evt.motion.y){
                         SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                         SDL_SetRenderDrawColor(ren, 173,255,47,0);            
                         SDL_RenderFillRect(ren, &s); 
                         a++;
                         SDL_RenderPresent(ren);
                         break;                        
                         }                    
                        case 1:
                        if(s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren,255,255,255,0);           
                        SDL_SetRenderDrawColor(ren, 127,255,212,0);            
                        SDL_RenderFillRect(ren, &s);
                        a++;
                        SDL_RenderPresent(ren);
                        break;                        
                        }                      
                        case 2:
                        if(s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                        SDL_SetRenderDrawColor(ren, 173,255,47,0);            
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                     }                    
                        case 3:
                        if(s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);                
                        SDL_SetRenderDrawColor(ren, 255,255,0,0);            
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                      }                    
                        case 4:
                        if (s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);                
                        SDL_SetRenderDrawColor(ren, 0,255,0,0);            
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                         }                   
                        case 5:
                        if (s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);                
                        SDL_SetRenderDrawColor(ren, 255,0,0,0);            
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                        }                    
                        case 6:
                        if(s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);             
                        SDL_SetRenderDrawColor(ren, 176,224,230,0);            
                        SDL_RenderFillRect(ren, &s);
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                     }                    
                        case 7:
                        if (s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                        SDL_SetRenderDrawColor(ren, 216,191,216,0);            
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                    }                     
                        case 8:
                        if (s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);                       
                        SDL_SetRenderDrawColor(ren, 255,165,0,0);           
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;
                   }                   
                        case 9:
                        if (s.x=evt.motion.x, s.y=evt.motion.y){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);            
                        SDL_SetRenderDrawColor(ren, 255,105,180,0);            
                        SDL_RenderFillRect(ren, &s); 
                        a++;
                        SDL_RenderPresent(ren);
                        break;}            
             }
        }
        }
    }
    
     /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
   
