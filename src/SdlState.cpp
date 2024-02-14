#include <sstream>
#include <cassert>
#include <SDL2/SDL.h>

#include "SdlState.hpp"

constexpr int tileW {8};
constexpr int tileH {8};

SdlState::SdlState(int w, int h, int zoom) : w {w}, h {h}, zoom {zoom} {
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

    const auto sheetPath = "images/Atari_ST_character_set_8x8.bmp";
    const auto image = SDL_LoadBMP(sheetPath);
    if (image == nullptr) {
        cleanUpSdl();
        const auto msg = (std::ostringstream() << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }
    const auto firstPixel = readFirstPixel(image);
    SDL_SetColorKey(image, SDL_TRUE, firstPixel);
    sheet = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    SDL_QueryTexture(sheet, nullptr, nullptr, &sheetW, &sheetH);

    pos_x = (w+tileW)/2;
    pos_y = (h+tileH)/2;
}

SdlState::~SdlState() {
    cleanUpSdl();
}

void SdlState::cleanUpSdl() {
    if (sheet != nullptr) {
        SDL_DestroyTexture(sheet);
    }
    if (framebuffer != nullptr) {
        SDL_DestroyTexture(framebuffer);
    }
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }
}

void SdlState::run() {
    while (!shouldQuit) {
        processInput();
        update();
        drawSdl();
    }
}

void SdlState::processInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
            case SDL_KEYDOWN:
            case SDL_MOUSEBUTTONDOWN:
            case SDL_WINDOWEVENT_CLOSE:
                shouldQuit = true;
                break;
        }
    }
}

void SdlState::update() {
    pos_x += 1;
    if (w <= pos_x) {
        pos_x = -tileW;
    }
}


void SdlState::drawSprite(const int n, const float x, const float y) const {
    const int sheetX = (n*tileW)%sheetW;
    const int sheetY = tileH*(n*tileW/sheetW);

    const SDL_Rect src {sheetX, sheetY, tileW, tileH};
    const SDL_Rect dst {static_cast<int>(x), static_cast<int>(y), tileW, tileH};
    SDL_RenderCopy(renderer, sheet, &src, &dst);
}

void SdlState::draw() const {
    cls();
    drawSprite(65, pos_x, pos_y);
    drawSprite(66, pos_x + 8, pos_y);
    drawSprite(67, pos_x + 16, pos_y);
}

void SdlState::drawSdl() const {
    // Render to buffer
    SDL_SetRenderTarget(renderer, framebuffer);
    SDL_SetRenderDrawColor(renderer, bgColor[0], bgColor[1], bgColor[2], 255);

    draw();

    // Render buffer
    SDL_SetRenderTarget(renderer, nullptr);
    const SDL_Rect windowDst {0, 0, w*zoom, h*zoom};
    SDL_RenderCopy(renderer, framebuffer, nullptr, &windowDst);

    SDL_RenderPresent(renderer);
}

const Uint32 SdlState::readFirstPixel(SDL_Surface* surface) const {
    const SDL_PixelFormat* const format = surface->format;

    assert(format->palette != nullptr);
    assert(format->palette->ncolors <= 0xff);
    assert(format->BitsPerPixel == 8);
    const Uint8 pixel = static_cast<Uint8*>(surface->pixels)[0];

    SDL_Color color;
    SDL_GetRGBA(pixel, format, &color.r, &color.g, &color.b, &color.a);

    return SDL_MapRGB(format, color.r, color.g, color.b);
}
