#include <iostream>
#include <SDL2/SDL.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    constexpr int windowWidth {480};
    constexpr int windowHeight {270};
    auto* const window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            windowWidth, windowHeight,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    auto* const surface = SDL_GetWindowSurface(window);
    const Uint32 bgColor {SDL_MapRGB(surface->format, 255, 255, 255)};
    SDL_FillRect(surface, nullptr, bgColor);
    SDL_UpdateWindowSurface(window);

    SDL_Event event;
    bool shouldQuit {false};
    while (!shouldQuit) {
        while(SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                case SDL_KEYDOWN:
                case SDL_MOUSEBUTTONDOWN:
                case SDL_WINDOWEVENT_CLOSE:
                    shouldQuit = true;
            }
        }
        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
