#include "Program.hpp"

Program::Program(Machine& machine) : machine{machine} { }

Program::~Program() { }

void Program::init(){
    shouldQuit = false;
    machine.loadConfig("config.lua");
    menuBarMap = machine.loadIntMatrix("menu_bar_tiles");
    room_01 = machine.loadIntMatrix("room_01");
    cursorTileRect = machine.loadTileRect("cursor_tiles");
}

void Program::reset() {
    init();
    machine.loadTileSheets();
}

void Program::update(const Input& input) {
    shouldQuit = input.shouldQuit;
    if (input.shouldReset) {
        reset();
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

    machine.drawTileMap(room_01, 0,tileH*2);

    machine.drawTileMap(menuBarMap, 0, 0);
    machine.drawText("Revising SDL and C++", tileW, tileH/2);
    machine.drawSprite(cursorTileRect, machine.mouseX, machine.mouseY);
}
