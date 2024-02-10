#include <sstream>
#include <SDL2/SDL.h>

#include "SdlState.h"

SdlState::SdlState(int w, int h) : shouldQuit{false} {
    window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w, h,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        auto msg = (std::ostringstream() << "Could not create window" << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }

    screenSurface = SDL_GetWindowSurface(window);
    bgColor = SDL_MapRGB(screenSurface->format, 255, 255, 255);
}

SdlState::~SdlState() {
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
    SDL_FillRect(screenSurface, nullptr, bgColor);
    SDL_UpdateWindowSurface(window);
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
