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

void Machine::loadConfig(std::string filename) {
    if (LUA_OK != luaL_dofile(L, filename.c_str())) {
        throw std::runtime_error(lua_tostring(L, -1));
    }
}

std::vector<std::vector<int>> Machine::loadIntMatrix(std::string name) {
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

    auto matrix = std::vector<std::vector<int>>();

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
