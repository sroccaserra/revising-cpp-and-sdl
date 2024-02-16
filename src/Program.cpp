#include "Program.hpp"

void Program::init(){
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
    machine.drawFont(65, tileW, tileH/2);
    machine.drawFont(66, tileW*2, tileH/2);
    machine.drawFont(67, tileW*3, tileH/2);

    // draw background
    for (int i = 2 ; i <= nTilesH; ++i) {
        for (int j = 0 ; j < nTilesW; ++j) {
            machine.drawBackground(0, j*tileW, i*tileH);
        }
    }

    machine.drawSprite(1, pos_x -8, pos_y);
}
