#include <sstream>
#include <cassert>
#include <SDL2/SDL.h>

#include "SdlMachine.hpp"

SdlMachine::SdlMachine(int w, int h, int zoom) : Machine(w, h), zoom {zoom} {
    if(0 == (SDL_WasInit(0) & SDL_INIT_VIDEO)) {
        auto msg = (std::ostringstream() << "SDL was not initialized.").str();
        throw std::runtime_error(msg);
    }

    window = SDL_CreateWindow(
            "SDL window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            w*zoom, h*zoom,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        auto msg = (std::ostringstream() << "Could not create window, " << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }

    const int rendererFlags {SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if (renderer == nullptr) {
        cleanUpSdl();
        const auto msg = (std::ostringstream() << "Could not create renderer, " << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }

    framebuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, w, h);

    loadSheet("images/Atari_ST_character_set_8x8.bmp", SDL_TRUE, fontSheet);
    loadSheet("images/spriteSheet.bmp", SDL_TRUE, spriteSheet);
    loadSheet("images/backgroundSheet.bmp", SDL_FALSE, backgroundSheet);

    SDL_ShowCursor(SDL_DISABLE);
}

SdlMachine::~SdlMachine() {
    cleanUpSdl();
}

void SdlMachine::loadSheet(const std::string& path, const bool hasColorKey, TileSheet& sheet) {
    const auto image = SDL_LoadBMP(path.c_str());
    if (image == nullptr) {
        cleanUpSdl();
        const auto msg = (std::ostringstream() << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }
    const auto firstPixel = readFirstPixel(image);
    SDL_SetColorKey(image, hasColorKey, firstPixel);
    sheet.texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    SDL_QueryTexture(sheet.texture, nullptr, nullptr, &sheet.textureW, &sheet.textureH);
}

void SdlMachine::cleanUpSdl() {
    for (auto texture : {
            fontSheet.texture, spriteSheet.texture, backgroundSheet.texture,
            framebuffer}) {
        if (texture != nullptr) {
            SDL_DestroyTexture(texture);
            texture = nullptr;
        }
    }

    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void SdlMachine::run() {
    assert(program != nullptr);

    program->init();

    while (!program->shouldQuit) {
        const Input input = processInput();
        program->update(input);
        drawSdl();
    }
}

const Input SdlMachine::processInput() {
    SDL_GetMouseState(&mouseX, &mouseY);
    mouseX /= zoom;
    mouseY /= zoom;
    Input result;

    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
            case SDL_WINDOWEVENT_CLOSE:
                result.shouldQuit = true;
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_r:
                        result.shouldReset = true;
                        break;
                    case SDLK_ESCAPE:
                        result.shouldQuit = true;
                        break;
                }
        }
    }
    return result;
}

void SdlMachine::drawTileRectFromSheet(const TileSheet &sheet, const TileRect& tileRect, const float x, const float y) const {
    const int pixelsW = tileRect.w*tileW;
    const int pixelsH = tileRect.h*tileH;

    const SDL_Rect src {tileRect.x*tileW, tileRect.y*tileH, pixelsW, pixelsH};
    const SDL_Rect dst {static_cast<int>(x), static_cast<int>(y), pixelsW, pixelsH};
    SDL_RenderCopy(renderer, sheet.texture, &src, &dst);
}

void SdlMachine::drawTilesFromSheet(const TileSheet &sheet, const int n, const float x, const float y,
        const int nTilesW, const int nTilesH) const {
    const int srcX = (n*tileW)%sheet.textureW;
    const int srcY = tileH*(n*tileW/sheet.textureW);

    const SDL_Rect src {srcX, srcY, tileW*nTilesW, tileH*nTilesH};
    const SDL_Rect dst {static_cast<int>(x), static_cast<int>(y), tileW*nTilesW, tileH*nTilesH};
    SDL_RenderCopy(renderer, sheet.texture, &src, &dst);
}

void SdlMachine::drawSdl() const {
    // Render to buffer
    SDL_SetRenderTarget(renderer, framebuffer);

    program->draw();

    // Render buffer
    SDL_SetRenderTarget(renderer, nullptr);
    const SDL_Rect windowDst {0, 0, w*zoom, h*zoom};
    SDL_RenderCopy(renderer, framebuffer, nullptr, &windowDst);

    SDL_RenderPresent(renderer);
}

const Uint32 SdlMachine::readFirstPixel(SDL_Surface* surface) const {
    const SDL_PixelFormat* const format = surface->format;

    assert(format->palette != nullptr);
    assert(format->palette->ncolors <= 256);
    assert(format->BitsPerPixel == 8);
    const Uint8 pixel = static_cast<Uint8*>(surface->pixels)[0];

    SDL_Color color;
    SDL_GetRGBA(pixel, format, &color.r, &color.g, &color.b, &color.a);

    return SDL_MapRGB(format, color.r, color.g, color.b);
}
