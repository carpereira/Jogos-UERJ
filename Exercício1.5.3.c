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
  
  
    while (1) {        
        SDL_SetRenderDrawColor(ren, 255,255,255,0);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r);       
        SDL_RenderPresent(ren);
        
      
  SDL_Event evt;
  
  while(SDL_PollEvent(&evt)){
    switch(evt.type);
    {
      case(r.y<280):
      SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
      SDL_RenderClear(ren);
      SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
      SDL_RenderFillRect(ren,&r);      
      SDL_RenderPresent(ren);
      SDL_Delay(100);
      r.y +=1;
      break;
      case (r.x<280):
      SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
      SDL_RenderClear(ren);
      SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
      SDL_RenderFillRect(ren,&r);      
      SDL_RenderPresent(ren);
      SDL_Delay(100);
      r.x +=1;
      break;
      case (r.y>20):
      SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
      SDL_RenderClear(ren);
      SDL_SetRenderDrawColor(ren, 0x00,0xFF,0xFF,0x00);
      SDL_RenderFillRect(ren,&r);      
      SDL_RenderPresent(ren);
      SDL_Delay(100);
      r.y -=1;
      break;
      case (r.x>20):
      SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
      SDL_RenderClear(ren);
      SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
      SDL_RenderFillRect(ren,&r);      
      SDL_RenderPresent(ren);
      SDL_Delay(100);
      r.x -=1;
  }
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
