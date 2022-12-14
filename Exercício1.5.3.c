#include <SDL2/SDL.h>

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

    /* EXECUÇÃO */
    SDL_Rect r = { 0,0, 20,20 };
    SDL_Rect s = {280,280,20,20};
    SDL_Rect t = {150,150,20,20};
    
        SDL_SetRenderDrawColor(ren, 255,255,255,0);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);
    
    
    SDL_Event evt;
    
    while (1) {
        
        //SDL_Event evt;
        
        SDL_WaitEvent(&evt);
        
        if (evt.type == SDL_QUIT){
            break;
        } 
        
        //int isevt = SDL_WaitEventTimeout(&evt, 500);
        //int isevt = SDL_WaitEvent(&evt);
        //int isevt = SDL_Event(&evt);
        //if (isevt) {
        if (&evt){
            //if (evt.type == SDL_MOUSEBUTTONDOWN) {                
                switch (1) {
                    case 1:
                        if (r.y<280){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 255,0,0,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);                        
                        r.y += 2;
                        break;}
                    case 2:
                        if (r.x<280){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,255,0,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);                       
                        r.x += 2;
                        break;}
                    case 3:
                        if (s.y>0){                    
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,0,255,0);
                        SDL_RenderFillRect(ren,&s);
                        SDL_RenderPresent(ren);                        
                        s.y -= 2;
                        break;}
                    case 4:
                        if (s.x>0){                    
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
            }
        }   
        
                //}
    }
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
