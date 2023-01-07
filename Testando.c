// Testado com MinGW64:
// gcc -Wall -Wextra -Wpedantic -Wno-unused-parameter test1.c `sdl2-config --cflags --libs` -lSDL2_ttf
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window   *window;
SDL_Renderer *renderer;
TTF_Font     *font;

#define MAX_LENGTH 1024
void drawText(const char* fmt, ...) {
    char buffer[MAX_LENGTH] = {0};

    va_list ap;

    va_start (ap, fmt);

    SDL_vsnprintf(buffer, MAX_LENGTH, fmt, ap);

    va_end (ap);

    SDL_Surface* text = TTF_RenderText_Solid(font, buffer,
                    (SDL_Color) { 255, 255, 255, 255 });
    
    SDL_Texture* textureText = SDL_CreateTextureFromSurface(renderer, text);

    SDL_Rect dest = {0};
    SDL_QueryTexture(textureText, NULL, NULL, &dest.w, &dest.h);

    //SDL_FreeSurface(text);

    SDL_RenderCopy(renderer, textureText, NULL, &dest);

    //SDL_DestroyTexture(textureText);
}

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    // https://fonts.google.com/specimen/VT323
    font = TTF_OpenFont("VT323.ttf", 24);

    window = SDL_CreateWindow("Window Title", SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED, 360, 240, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

    int counter = 0;
    while (!SDL_QuitRequested()) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        drawText("Your Score: %d", counter++);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
