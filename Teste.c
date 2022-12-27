#include <SDL2/SDL.h>
#include <stdbool.h>
#define max 5

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Animando e Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         300, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    
    bool quit = false;

    /* EXECUÇÃO */
    SDL_Rect r = { 0,0, 20,20 };
    SDL_Rect s = {280,280,20,20};
    SDL_Rect t = {150,150,20,20};            
    
    SDL_Event evt;
    SDL_SetRenderDrawColor(ren, 255,255,255,0);
    SDL_RenderClear(ren);
    SDL_SetRenderDrawColor(ren, 0,0,255,0);
    SDL_RenderFillRect(ren, &r);
    SDL_RenderPresent(ren);
    
    //while (1) {  
    while(!quit){  
    
        //SDL_WaitEvent(&evt);        
        while (SDL_PollEvent(&evt) !=false){
            
        if (evt.type == SDL_QUIT){
          quit = true;
            //break;
        }         
     
        /*SDL_Event evt;
        int isevt = SDL_WaitEventTimeout(&evt,500);
        if (isevt){
            if (evt.type == SDL_KEYDOWN){*/
        while (quit=false){
            int i;
            for(i=1;i<=max;i++){
                switch (i) {
                    case 1:
                        while (r.y<280){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 255,0,0,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);                        
                        r.y += 2;
                        break;}
                    case 2:
                        while (r.x<280){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,255,0,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);                       
                        r.x += 2;
                        break;}
                    case 3:
                        while (s.y>0){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,0,255,0);
                        SDL_RenderFillRect(ren,&s);
                        SDL_RenderPresent(ren);                        
                        s.y -= 2;
                        break;}
                    case 4:
                        while (s.x>0){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,255,255,0);
                        SDL_RenderFillRect(ren,&s);
                        SDL_RenderPresent(ren);                        
                        s.x -= 2;
                        break;} 
                    case 5:                        
                        SDL_SetRenderDrawColor(ren, 0,0,0,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderFillRect(ren,&t);
                        SDL_RenderPresent(ren);                        
                        break;
                //}
                //}
             }
               }
            }
        }   
    }     
    
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
    
