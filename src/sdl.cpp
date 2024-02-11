#include <iostream>
#include <SDL2/SDL.h>

#include "SdlState.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    int result {0};
    try {
        SdlState sdlState(480, 270, 3);
        sdlState.run();
    }
    catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        result = 1;
    }

    SDL_Quit();
    return result;
}
