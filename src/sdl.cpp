#include <SDL2/SDL.h>
#include <iostream>

#include "State.h"

void run();

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    int result {0};
    try {
        run();
    }
    catch(std::exception& e) {
        result = 1;
    }

    SDL_Quit();
    return result;
}

void run() {
    State state(480, 270);
    if (state.shouldQuit) {
        throw std::exception();
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
