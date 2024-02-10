#include <iostream>
#include <SDL2/SDL.h>

class State {
    public:
        State(int w, int h) : w{w}, h{h}, shouldQuit{false} {}

        void init() {
            screenSurface = SDL_GetWindowSurface(window);
            bgColor = SDL_MapRGB(screenSurface->format, 255, 255, 255);
        }

        void draw() {
            SDL_FillRect(screenSurface, nullptr, bgColor);
            SDL_UpdateWindowSurface(window);
        }

        void update(const SDL_Event& event) {
            switch (event.type) {
                case SDL_QUIT:
                case SDL_KEYDOWN:
                case SDL_MOUSEBUTTONDOWN:
                case SDL_WINDOWEVENT_CLOSE:
                    shouldQuit = true;
            }
        }

        SDL_Window* window;

        int w;
        int h;
        bool shouldQuit;

    private:
        SDL_Surface* screenSurface;
        Uint32 bgColor;
};

bool initState(State& state);

int main() {
    State state(480, 270);
    if (!initState(state)) {
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

    SDL_DestroyWindow(state.window);
    SDL_Quit();

    return 0;
}

bool initState(State& state) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    state.window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            state.w, state.h,
            SDL_WINDOW_SHOWN);
    if (state.window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return false;
    }

    state.init();

    return true;
}
