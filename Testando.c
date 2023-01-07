#include <SDL2/SDL_ttf.h>
#include <assert.h>
int main (int argc, char* args[]) {
/* INICIALIZACAO */
TTF_Init();
TTF_Font* fnt = TTF_OpenFont("tiny.ttf", 20);
assert(fnt != NULL);
SDL_Color clr = {0xFF,0x00,0x00,0xFF};
SDL_Surface* sfc = TTF_RenderText_Blended(fnt, "ola mundo", clr);
assert(sfc != NULL);
SDL_Texture* txt = SDL_CreateTextureFromSurface(ren, sfc);
assert(txt != NULL);
SDL_FreeSurface(sfc);
/* EXECUÇÃO */
SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
SDL_RenderClear(ren);
SDL_Rect r = { 50,50, 200,80 };
SDL_RenderCopy(ren, txt, NULL, &r);
SDL_RenderPresent(ren);
SDL_Delay(5000);
/* FINALIZACAO */
SDL_DestroyTexture(txt);
TTF_CloseFont(fnt);
TTF_Quit();
}
