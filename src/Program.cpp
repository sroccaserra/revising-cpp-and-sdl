#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "Program.hpp"

Program::Program(Machine& machine) : machine{machine} {
    L = luaL_newstate();
    luaL_openlibs(L);
}

Program::~Program() {
    lua_close(L);
}

void Program::init(){
    loadConfig();

    pos_x = (machine.w+tileW)/2;
    pos_y = (machine.h+tileH)/2;
}

void Program::loadConfig() {
    if (LUA_OK != luaL_dofile(L, "config.lua")) {
        throw std::runtime_error(lua_tostring(L, -1));
    }

    std::vector<std::vector<int>> matrix = loadIntMatrix("menu_bar");
    for (auto row : matrix) {
        for(auto n : row) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    }
}

std::vector<std::vector<int>> Program::loadIntMatrix(std::string name) {
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

void Program::update() {
    pos_x += 1;
    if (machine.w <= pos_x) {
        pos_x = -tileW;
    }
}

void Program::draw() const {
    machine.cls();

    const int nTilesW = machine.w / tileW;
    const int nTilesH = machine.h / tileH;

    // draw corners
    machine.drawBackground(1, 0, 0);
    machine.drawBackground(3, (nTilesW-1)*tileW, 0);

    // draw title bar
    for (int j = 1; j < nTilesW-1; ++j) {
        machine.drawBackground(2, j*tileW, 0);
    }
    for (int j = 0; j < nTilesW; ++j) {
        machine.drawBackground(4, j*tileW, tileH);
    }

    drawText("Revising SDL and C++", tileW, tileH/2);

    // draw background
    for (int i = 2 ; i <= nTilesH; ++i) {
        for (int j = 0 ; j < nTilesW; ++j) {
            machine.drawBackground(0, j*tileW, i*tileH);
        }
    }

    // cursor
    machine.drawSprite(1, machine.mouseX, machine.mouseY, 2, 2);
}

void Program::drawText(const std::string &text, const float x, const float y) const {
    float char_x = x;
    for (char c : text) {
        machine.drawFont(c, char_x, y);
        char_x += tileW;
    }
}
