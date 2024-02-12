#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <SDL2/SDL.h>

class SdlState {
    public:
        SdlState(int w, int h, int zoom);
        ~SdlState();
        void run();

    private:
        void processInput();
        void update();
        void draw() const;
        void cleanUpSDL();
        const Uint32 readFirstPixel(SDL_Surface* surface) const;

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* framebuffer;
        SDL_Texture* sheet;

        bool shouldQuit;
        Uint8 bgColor[3];
        int w;
        int h;
        int zoom;
        int pos_x;
        int pos_y;
};

#endif // __STATE_HPP__
