#include <SDL2/SDL.h>
#include <iostream>

#include "State.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    {
        State state(480, 270);
        if (state.shouldQuit) {
            return 1;
        }

        state.draw();

        SDL_Event event;
        while (!state.shouldQuit) {
            while(SDL_PollEvent(&event)) {
                state.update(event);
            }
            SDL_Delay(100);
        }
    }

    SDL_Quit();
    return 0;
}
