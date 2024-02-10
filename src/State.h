#ifndef __STATE_H__
#define __STATE_H__

#include <SDL2/SDL.h>

class State {
    public:
        State(int w, int h);
        ~State();
        void run();

    private:
        void draw();
        void update(const SDL_Event& event);

        SDL_Window* window;
        SDL_Surface* screenSurface;
        Uint32 bgColor;
        bool shouldQuit;
};

#endif // __STATE_H__
