#include <SDL2/SDL.h>

int main(int argc, char* args[])
{
/*INICIALIZAÇÃO*/
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Window* win = SDL_CreateWindow("Animação Simples!",
                      SDL_WINDOWPOS_UNDEFINED,
                      SDL_WINDOWPOS_UNDEFINED,
                      300, 300, SDL_WINDOW_SHOWN
                      );
SDL_Renderer* ren = SDL_CreateRenderer(win, -1,0);

/*EXECUÇÃO*/

SDL_Rect r={40,20,10,10};
      
  while (r.y<280){
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
    SDL_RenderFillRect(ren,&r);      
    SDL_RenderPresent(ren);
    SDL_Delay(100);
    r.y +=1;
    
  while (r.x<280){
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
    SDL_RenderFillRect(ren,&r);      
    SDL_RenderPresent(ren);
    SDL_Delay(100);
    r.x +=1;    
  
  }  
  }  
    
SDL_Rect s={280,280,10,10};
    
   while (s.y>20){
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0x00,0xFF,0xFF,0x00);
    SDL_RenderFillRect(ren,&s);      
    SDL_RenderPresent(ren);
    SDL_Delay(100);
    s.y -=1;
      
  while (s.x>20){
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
    SDL_RenderFillRect(ren,&s);      
    SDL_RenderPresent(ren);
    SDL_Delay(100);
    s.x -=1;
  }
    }
  
  
   
        SDL_Event evt;
        
        int isevt = SDL_WaitEventTimeout(&evt,500);
        if(isevt){
            if(evt.type == SDL_MOUSEBUTTONDOWN){
                SDL_SetRenderDrawColor(ren, 255,255,255,0);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren, 255,0,0,0);
                SDL_RenderFillRect(ren, &r);
                SDL_RenderPresent(ren);
                //SDL_Delay(200);
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
                
  
  
  

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
