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
    SDL_Rect r = { 40,20, 10,10 };
    //SDL_Rect s = {280,280,10,10};
    
    while (1) {
        SDL_SetRenderDrawColor(ren, 255,255,255,0);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0,0,255,0);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        
        if (evt.type == SDL_QUIT){
            break;
        } 
        
        int isevt = SDL_WaitEventTimeout(&evt,300);
        if (isevt) {
            //while(1){
            //if (evt.type == SDL_COMMON) {
              //  switch (1) {
                //    case 1:
                        if(r.y<280){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 255,0,0,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);
                        r.y += 2;}
                        //break;}
                    //case 2:
       if (isevt) {
                        if (r.x<280);{
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,255,0,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);
                        r.x += 2;}
                        //break;}
                    /*case 3:
                        if (r.y>20){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 0,0,255,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);
                        r.y -= 2;
                        break;}
                    case 4:
                        if (r.x>20){
                        SDL_SetRenderDrawColor(ren, 255,255,255,0);
                        SDL_RenderClear(ren);
                        SDL_SetRenderDrawColor(ren, 255,0,255,0);
                        SDL_RenderFillRect(ren,&r);
                        SDL_RenderPresent(ren);
                        r.x -= 2;
                        break;}*/
                
            }
        } //else {
            //r.x += 2;
            //r.y += 2;
        }
    //}

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
