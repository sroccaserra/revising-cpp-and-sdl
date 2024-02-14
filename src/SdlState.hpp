#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <SDL2/SDL.h>

struct Sheet {
    SDL_Texture* texture;
    int textureW;
    int textureH;
};

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

        void drawSheet(const Sheet &sheet, const int n, const float x, const float y) const;
        void drawFont(const int n, const float x, const float y) const {
            drawSheet(fontSheet, n, x, y);
        }
        void drawSprite(const int n, const float x, const float y) const {
            drawSheet(spriteSheet, n, x, y);
        }
        void drawBackground(const int n, const float x, const float y) const {
            drawSheet(backgroundSheet, n, x, y);
        }

        // Needed by SDL
        void processInput();
        void drawSdl() const;
        void cleanUpSdl();
        void loadSheet(const char* path, bool hasColorKey, Sheet* sheet);
        const Uint32 readFirstPixel(SDL_Surface* surface) const;

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* framebuffer;
        int w;
        int h;
        int zoom;

        Sheet fontSheet;
        Sheet spriteSheet;
        Sheet backgroundSheet;

        Uint8 bgColor[3] {63, 63, 63};

        bool shouldQuit {false};
        float pos_x;
        float pos_y;
};

#endif // __STATE_HPP__
