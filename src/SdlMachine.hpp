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
            drawTilesFromSheet(fontSheet, n, x, y, 1, 1);
        }
        void drawSprite(const int n, const float x, const float y,
                const int nTilesW, const int nTilesH) const override {
            drawTilesFromSheet(spriteSheet, n, x, y, nTilesW, nTilesH);
        }
        void drawSprite(const TileRect& tileRect, const float x, const float y) const override {
            drawTileRectFromSheet(spriteSheet, tileRect, x, y);
        }
        void drawBackground(const int n, const float x, const float y,
                const int nTilesW, const int nTilesH) const override {
            drawTilesFromSheet(backgroundSheet, n, x, y, nTilesW, nTilesH);
        }

        // SDL stuff
        void processInput();
        void drawSdl() const;
        void loadSheet(const char* path, bool hasColorKey, Sheet* sheet);
        void drawTileRectFromSheet(const Sheet &sheet, const TileRect& rect, const float x, const float y) const;
        void drawTilesFromSheet(const Sheet &sheet, const int n, const float x, const float y, const int nTilesW, const int nTilesH) const;
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
