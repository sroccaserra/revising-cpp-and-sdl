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
