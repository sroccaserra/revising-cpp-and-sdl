#include <iostream>
#include <SDL2/SDL.h>

#include "SdlMachine.hpp"
#include "Program.hpp"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    int result {0};
    try {
        SdlMachine sdlMachine(480, 270, 3);
        Program program(sdlMachine);
        sdlMachine.program = &program;
        sdlMachine.run();
    }
    catch(std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        result = 1;
    }

    SDL_Quit();
    return result;
}
