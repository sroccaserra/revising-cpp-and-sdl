#include <sstream>
#include <cassert>

#include "Machine.hpp"

extern "C" {
    #include "lualib.h"
    #include "lauxlib.h"
}

Machine::Machine(int w, int h) : w{w}, h{h} {
    L = luaL_newstate();
    luaL_openlibs(L);
}

Machine::~Machine() {
    lua_close(L);
}

void Machine::loadConfig(const std::string& filename) {
    if (LUA_OK != luaL_dofile(L, filename.c_str())) {
        throw std::runtime_error(lua_tostring(L, -1));
    }
}

const TileRect Machine::loadTileRect(const std::string& name) const {
    int startTop = lua_gettop(L);

    lua_getglobal(L, name.c_str());
    if (!lua_istable(L, -1)) {
        std::string msg = (std::ostringstream() << "Global variable '" << name << "' is not defined").str();
        throw std::runtime_error(msg);
    }
    lua_len(L, -1);
    const int n = lua_tointeger(L, -1);
    assert(4 == n);
    lua_pop(L, 1);

    TileRect result;

    lua_geti(L, -1, 1);
    result.x = lua_tointeger(L, -1);
    lua_pop(L, 1);

    lua_geti(L, -1, 2);
    result.y = lua_tointeger(L, -1);
    lua_pop(L, 1);

    lua_geti(L, -1, 3);
    result.w = lua_tointeger(L, -1);
    lua_pop(L, 1);

    lua_geti(L, -1, 4);
    result.h = lua_tointeger(L, -1);
    lua_pop(L, 1);

    lua_pop(L, 1);
    assert(startTop == lua_gettop(L));
    return result;
}

const TileMap Machine::loadIntMatrix(const std::string& name) const {
    int startTop = lua_gettop(L);

    lua_getglobal(L, name.c_str());
    if (!lua_istable(L, -1)) {
        std::string msg = (std::ostringstream() << "Global variable '" << name << "' is not defined").str();
        throw std::runtime_error(msg);
    }

    lua_len(L, -1);
    const int h = lua_tointeger(L, -1);
    assert(0 < h);
    lua_pop(L, 1);

    lua_geti(L, -1, 1);
    lua_len(L, -1);
    const int w = lua_tointeger(L, -1);
    assert(0 < w);
    lua_pop(L, 2);

    auto matrix = TileMap();

    for (int i = 1; i<= h; ++i) {
        lua_geti(L, -1, i);
        matrix.push_back(std::vector<int>());
        auto& row = matrix.back();
        for (int j = 1; j<= w; ++j) {
            lua_geti(L, -1, j);
            int n = lua_tointeger(L, -1);
            row.push_back(n);
            lua_pop(L, 1);
        }
        lua_pop(L, 1);
    }

    lua_pop(L, 1);
    assert(startTop == lua_gettop(L));

    return matrix;
}

void Machine::drawTileMap(const TileMap& tileMap, const float x, const float y) const {
    float i {y};
    for (auto& row : tileMap) {
        float j {x};
        for(int n : row) {
            drawBackground(n, j, i);
            j += tileW;
        }
        i += tileH;
    }
}

void Machine::drawText(const std::string& text, const float x, const float y) const {
    float char_x {x};
    for (char c : text) {
        drawFont(c, char_x, y);
        char_x += tileW;
    }
}
