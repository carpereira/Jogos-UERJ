// Testado com MinGW64:
// gcc -Wall -Wextra -Wpedantic -Wno-unused-parameter test0.c `sdl2-config --cflags --libs` -lSDL2_ttf
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window  *window;
SDL_Surface *surface;
TTF_Font    *font;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // https://fonts.google.com/specimen/VT323
    font = TTF_OpenFont("VT323.ttf", 24);

    window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED, 360, 240, 0);

    surface = SDL_GetWindowSurface(window);

    while (!SDL_QuitRequested()) {
        SDL_Surface* text = TTF_RenderText_Solid(font, "Hello, World!",
                    (SDL_Color) { 255, 255, 255, 255 });

        SDL_FillRect(surface, NULL, 0);
        SDL_BlitSurface(text, NULL, surface, NULL);
        SDL_FreeSurface(text);
        SDL_UpdateWindowSurface(window);
    }

    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
