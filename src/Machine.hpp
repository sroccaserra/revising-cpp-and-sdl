#ifndef __MACHINE_HPP__
#define __MACHINE_HPP__

extern "C" {
    #include "lua.h"
}

#include <string>
#include <vector>

constexpr int tileW {8};
constexpr int tileH {8};

class Machine {
    public:
        Machine(int w, int h);
        virtual ~Machine();

        virtual void cls() const = 0;
        virtual void drawFont(const int n, const float x, const float y) const = 0;
        virtual void drawSprite(const int n, const float x, const float y,
                const int nTilesW = 1, const int nTilesH = 1) const = 0;
        virtual void drawBackground(const int n, const float x, const float y,
                const int nTilesW = 1, const int nTilesH = 1) const = 0;

        void loadConfig(std::string filename);
        std::vector<std::vector<int>> loadIntMatrix(std::string name);

        int w;
        int h;

        int mouseX;
        int mouseY;

    private:
        lua_State* L;
};

#endif // __MACHINE_HPP__
