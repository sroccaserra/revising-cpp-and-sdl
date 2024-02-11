#include <sstream>
#include <SDL2/SDL.h>

#include "SdlState.h"

SdlState::SdlState(int w, int h) : shouldQuit{false}, bgColor{63, 63, 63} {
    window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w, h,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        auto msg = (std::ostringstream() << "Could not create window, " << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }

    const int rendererFlags {SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);

        auto msg = (std::ostringstream() << "Could not create renderer, " << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }
}

SdlState::~SdlState() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void SdlState::run() {
    draw();

    SDL_Event event;
    while (!shouldQuit) {
        while(SDL_PollEvent(&event)) {
            update(event);
        }
        SDL_Delay(100);
    }
}

void SdlState::draw() {
    SDL_SetRenderDrawColor(renderer, bgColor[0], bgColor[1], bgColor[2], 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void SdlState::update(const SDL_Event& event) {
    switch (event.type) {
        case SDL_QUIT:
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_WINDOWEVENT_CLOSE:
            shouldQuit = true;
    }
}
