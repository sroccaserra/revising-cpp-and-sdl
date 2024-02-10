#include <iostream>
#include <SDL2/SDL.h>
#include "State.h"

int main() {
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
