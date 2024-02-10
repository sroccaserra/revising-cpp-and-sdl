#include <iostream>
#include <SDL2/SDL.h>

#include "State.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    int result {0};
    try {
        State state(480, 270);
        state.run();
    }
    catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        result = 1;
    }

    SDL_Quit();
    return result;
}
