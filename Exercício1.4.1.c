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
    
    SDL_Texture* tex;

    /* EXECUÇÃO */
    SDL_Rect r = { 100,100, 10,10 };    
    
    SDL_Event evt;
    while (1) {        
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);
        
        SDL_WaitEvent(&evt);        
        if (evt.type == SDL_QUIT){
            break;
        }
        
        if (evt.type == SDL_MOUSEBUTTONDOWN){
            SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
            SDL_RenderClear(ren);
            SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
            //gModulatedTexture.setColor(255,255,255);
            //gModulatedTexture.render(0,0);
            SDL_SetTextureColorMod( tex, 255, 255, 255);
            
            SDL_RenderFillRect(ren, &r);
            SDL_RenderPresent(ren);
            SDL_Delay(200);
        }
        
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
     
