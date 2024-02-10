#include <iostream>
#include <SDL2/SDL.h>

class State {
    public:
        State(int w, int h) : shouldQuit{false}, w{w}, h{h} {}
        bool initialize();
        void draw();
        void update(const SDL_Event& event);

        SDL_Window* window;
        bool shouldQuit;

    private:
        SDL_Surface* screenSurface;
        Uint32 bgColor;
        int w;
        int h;
};

bool State::initialize() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w, h,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return false;
    }

    screenSurface = SDL_GetWindowSurface(window);
    bgColor = SDL_MapRGB(screenSurface->format, 255, 255, 255);

    return true;
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
