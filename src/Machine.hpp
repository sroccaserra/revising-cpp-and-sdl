#ifndef __MACHINE_HPP__
#define __MACHINE_HPP__

extern "C" {
    #include "lua.h"
}

#include <string>
#include <vector>

constexpr int tileW {8};
constexpr int tileH {8};

struct TileRect {
    int x;
    int y;
    int w;
    int h;
};

class Machine {
    public:
        Machine(int w, int h);
        virtual ~Machine();

        virtual void cls() const = 0;

        virtual void drawFont(const int n, const float x, const float y) const = 0;
        virtual void drawSprite(const TileRect& rect, const float x, const float y) const = 0;
        virtual void drawSprite(const int n, const float x, const float y,
                const int nTilesW = 1, const int nTilesH = 1) const = 0;
        virtual void drawBackground(const int n, const float x, const float y,
                const int nTilesW = 1, const int nTilesH = 1) const = 0;

        virtual void loadTileSheets() = 0;

        void drawTileMap(const std::vector<std::vector<int>>& tileMap, const float x, const float y) const;
        void drawText(const std::string& text, const float x, const float y) const;

        void loadConfig(const std::string& filename);
        const TileRect loadTileRect(const std::string& name) const;
        const std::vector<std::vector<int>> loadIntMatrix(const std::string& name) const;

        int w;
        int h;

        int mouseX;
        int mouseY;

    private:
        lua_State* L;
};

#endif // __MACHINE_HPP__
