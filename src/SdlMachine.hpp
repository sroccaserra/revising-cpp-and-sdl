#ifndef __SDL_STATE_HPP__
#define __SDL_STATE_HPP__

#include <SDL2/SDL.h>

#include "Machine.hpp"
#include "Program.hpp"

struct Sheet {
    SDL_Texture* texture;
    int textureW;
    int textureH;
};

class SdlMachine : public Machine {
    public:
        SdlMachine(int w, int h, int zoom);
        virtual ~SdlMachine();
        Program* program;
        void run();

    private:
        // Implement Machine methods
        void cls() const override {
            SDL_SetRenderDrawColor(renderer, bgColor[0], bgColor[1], bgColor[2], 255);
            SDL_RenderClear(renderer);
        }
        void drawFont(const int n, const float x, const float y) const override {
            drawSheet(fontSheet, n, x, y);
        }
        void drawSprite(const int n, const float x, const float y) const override {
            drawSheet(spriteSheet, n, x, y);
        }
        void drawBackground(const int n, const float x, const float y) const override {
            drawSheet(backgroundSheet, n, x, y);
        }

        // SDL stuff
        void processInput();
        void drawSdl() const;
        void loadSheet(const char* path, bool hasColorKey, Sheet* sheet);
        void drawSheet(const Sheet &sheet, const int n, const float x, const float y) const;
        const Uint32 readFirstPixel(SDL_Surface* surface) const;
        void cleanUpSdl();

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* framebuffer;

        Sheet fontSheet;
        Sheet spriteSheet;
        Sheet backgroundSheet;

        Uint8 bgColor[3] {0, 0, 0};

        bool shouldQuit {false};
        int zoom;
};

#endif // __SDL_STATE_HPP__
