#include <sstream>
#include <SDL2/SDL.h>

#include "SdlState.h"

SdlState::SdlState(int w, int h, int zoom)
    : shouldQuit{false} , bgColor{63, 63, 63} , w {w}, h {h}, zoom {zoom} {
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
        cleanUpSDL();
        auto msg = (std::ostringstream() << "Could not create renderer, " << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }

    framebuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET, w, h);

    auto sheetPath = "images/sheet.bmp";
    auto image = SDL_LoadBMP(sheetPath);
    if (image == nullptr) {
        cleanUpSDL();
        auto msg = (std::ostringstream() << SDL_GetError()).str();
        throw std::runtime_error(msg);
    }
    sheet = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
}

SdlState::~SdlState() {
    cleanUpSDL();
}

void SdlState::cleanUpSDL() {
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
    draw();

    SDL_Event event;
    while (!shouldQuit) {
        while(SDL_PollEvent(&event)) {
            update(event);
        }
        SDL_Delay(100);
    }
}

void SdlState::draw() {
    // Render to buffer
    SDL_SetRenderTarget(renderer, framebuffer);
    SDL_SetRenderDrawColor(renderer, bgColor[0], bgColor[1], bgColor[2], 255);
    SDL_RenderClear(renderer);

    SDL_Rect dst {0, 0, 0, 0};
    SDL_QueryTexture(sheet, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, sheet, nullptr, &dst);

    // Render buffer
    SDL_SetRenderTarget(renderer, nullptr);
    SDL_Rect windowDst {0, 0, w*zoom, h*zoom};
    SDL_RenderCopy(renderer, framebuffer, nullptr, &windowDst);

    SDL_RenderPresent(renderer);
}

void SdlState::update(const SDL_Event& event) {
    switch (event.type) {
        case SDL_QUIT:
        case SDL_KEYDOWN:
        case SDL_MOUSEBUTTONDOWN:
        case SDL_WINDOWEVENT_CLOSE:
            shouldQuit = true;
    }
}
