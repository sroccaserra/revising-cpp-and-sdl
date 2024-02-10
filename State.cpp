
#include <SDL2/SDL.h>
#include <iostream>

#include "State.h"


State::State(int w, int h) : shouldQuit{false} {
    window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w, h,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        shouldQuit = true;
        return;
    }

    screenSurface = SDL_GetWindowSurface(window);
    bgColor = SDL_MapRGB(screenSurface->format, 255, 255, 255);
}

State::~State() {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void State::draw() {
    SDL_FillRect(screenSurface, nullptr, bgColor);
    SDL_UpdateWindowSurface(window);
}

void State::update(const SDL_Event& event) {
    switch (event.type) {
        case SDL_QUIT:
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_WINDOWEVENT_CLOSE:
            shouldQuit = true;
    }
}
