#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <SDL2/SDL.h>

class SdlState {
    public:
        SdlState(int w, int h, int zoom);
        ~SdlState();
        void run();

    private:
        // Could be user defined
        void update();
        void draw() const;
        // Could be an API available to user
        void cls() const {SDL_RenderClear(renderer);}
        void drawSprite(const int n, const float x, const float y) const;

        // Needed by SDL
        void processInput();
        void drawSdl() const;
        void cleanUpSdl();
        const Uint32 readFirstPixel(SDL_Surface* surface) const;

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* framebuffer;
        SDL_Texture* sheet;

        bool shouldQuit;
        Uint8 bgColor[3];
        int sheetW;
        int sheetH;
        int w;
        int h;
        int zoom;
        float pos_x;
        float pos_y;
};

#endif // __STATE_HPP__
