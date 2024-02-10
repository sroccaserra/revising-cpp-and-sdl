#ifndef __STATE_H__
#define __STATE_H__

#include <SDL2/SDL.h>
#include <iostream>

class State {
    public:
        State(int w, int h);
        ~State();
        void draw();
        void update(const SDL_Event& event);

        SDL_Window* window;
        bool shouldQuit;

    private:
        SDL_Surface* screenSurface;
        Uint32 bgColor;
};

#endif // __STATE_H__
