#include <iostream>
#include <SDL2/SDL.h>

struct State {
    SDL_Window* window;
    SDL_Surface* screenSurface;

    int w;
    int h;
    Uint32 bgColor;
};

bool initState(State& state, int w, int h);
void drawOn(const State& state);

int main() {
    State state;
    if (!initState(state, 480, 270)) {
        return 1;
    }

    drawOn(state);

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

    SDL_DestroyWindow(state.window);
    SDL_Quit();

    return 0;
}

bool initState(State& state, int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    state.window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w, h,
            SDL_WINDOW_SHOWN);
    if (state.window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return false;
    }

    state.screenSurface = SDL_GetWindowSurface(state.window);
    state.w = w;
    state.h = h;
    state.bgColor = SDL_MapRGB(state.screenSurface->format, 255, 255, 255);

    return true;
}

void drawOn(const State& state) {
    SDL_FillRect(state.screenSurface, nullptr, state.bgColor);
    SDL_UpdateWindowSurface(state.window);
}
