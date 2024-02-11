#ifndef __STATE_H__
#define __STATE_H__

#include <SDL2/SDL.h>

class SdlState {
    public:
        SdlState(int w, int h);
        ~SdlState();
        void run();

    private:
        void draw();
        void update(const SDL_Event& event);

        SDL_Window* window;
        SDL_Renderer* renderer;
        bool shouldQuit;
        Uint8 bgColor[3];
};

#endif // __STATE_H__
