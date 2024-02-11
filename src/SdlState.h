#ifndef __STATE_H__
#define __STATE_H__

#include <SDL2/SDL.h>

class SdlState {
    public:
        SdlState(int w, int h, int zoom);
        ~SdlState();
        void run();

    private:
        void draw();
        void update(const SDL_Event& event);
        void cleanUpSDL();

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* framebuffer;
        SDL_Texture* sheet;
        bool shouldQuit;
        Uint8 bgColor[3];
        int w;
        int h;
        int zoom;
};

#endif // __STATE_H__