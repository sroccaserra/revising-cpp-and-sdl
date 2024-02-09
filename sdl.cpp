#include <iostream>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 270

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    const Uint32 bgColor = SDL_MapRGB(screenSurface->format, 255, 255, 255);
    SDL_FillRect(screenSurface, nullptr, bgColor);
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
