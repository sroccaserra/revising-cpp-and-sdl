#include "Program.hpp"

Program::Program(Machine& machine) : machine{machine} { }

Program::~Program() { }

void Program::init(){
    machine.loadConfig("config.lua");
    menuBarMap = machine.loadIntMatrix("menu_bar_tiles");
    cursorTileRect = machine.loadTileRect("cursor_tiles");

    pos_x = (machine.w+tileW)/2;
    pos_y = (machine.h+tileH)/2;
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

    for (int i = 0 ; i <= nTilesH; ++i) {
        for (int j = 0 ; j < nTilesW; ++j) {
            machine.drawBackground(0, j*tileW, i*tileH);
        }
    }

    machine.drawTileMap(menuBarMap, 0, 0);
    machine.drawText("Revising SDL and C++", tileW, tileH/2);
    machine.drawSprite(cursorTileRect, machine.mouseX, machine.mouseY);
}
