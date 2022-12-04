#include <SDL2/SDL.h>

int main(int argc, char* args[])
{
/*INICIALIZAÇÃO*/
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Window* win = SDL_CreateWindow("Animação Orientada a Eventos!",
                      SDL_WINDOWPOS_UNDEFINED,
                      SDL_WINDOWPOS_UNDEFINED,
                      300, 300, SDL_WINDOW_SHOWN
                      );
SDL_Renderer* ren = SDL_CreateRenderer(win, -1,0);

/*EXECUÇÃO*/

SDL_Rect r={40,20,10,10};
SDL_Rect s={280,280,10,10};
  
  
    while (1) {        
        SDL_SetRenderDrawColor(ren, 255,255,255,0);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r);       
        //SDL_SetRenderDrawColor(ren, 255,0,0,0);
        //SDL_RenderFillRect(ren, &s);  
        SDL_RenderPresent(ren);
      
      SDL_Event evt;
      
      if (evt.type == SDL_QUIT){            
            break;
        } 
      
      int isevt = SDL_WaitEventTimeout(&evt, 100);
        if (isevt) {
          if (r.y<280){
            SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
            SDL_RenderFillRect(ren,&r);      
            SDL_RenderPresent(ren);
            r.y +=1;
        } //else{      
                //r.y +=1;                    
        //}
         /*if (isevt) { 
           if (r.x<280){
             SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
             SDL_RenderClear(ren);
             SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
             SDL_RenderFillRect(ren,&r);      
             SDL_RenderPresent(ren);}
        } else{      
              r.x +=1;              
              }*/
      /*if (isevt) {
           if (s.y>20){
              SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
              SDL_RenderClear(ren);
              SDL_SetRenderDrawColor(ren, 0x00,0xFF,0xFF,0x00);
              SDL_RenderFillRect(ren,&s);      
              SDL_RenderPresent(ren);}
       } else{
              s.y -=1;
              }
      if (isevt) {
           if (s.x>20){
             SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
             SDL_RenderClear(ren);
             SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
             SDL_RenderFillRect(ren,&s);      
             SDL_RenderPresent(ren);}
       } else{
              s.x -=1;
              }*/
  
    }          
              
        
  
    
  

/*FINALIZAÇÃO*/
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();
}
