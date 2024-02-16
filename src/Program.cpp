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

    machine.drawBackground(1, 0, 0);
    for (int j = 1; j < 59; ++j) {
        machine.drawBackground(2, j*tileW, 0);
    }
    for (int j = 0; j < 60; ++j) {
        machine.drawBackground(4, j*tileW, tileH);
    }
    machine.drawBackground(3, 59*tileW, 0);
    for (int i = 2 ; i < 34; ++i) {
        for (int j = 0 ; j < 60; ++j) {
            machine.drawBackground(0, j*tileW, i*tileH);
        }
    }

    machine.drawFont(65, tileW, tileH/2);
    machine.drawFont(66, tileW*2, tileH/2);
    machine.drawFont(67, tileW*3, tileH/2);

    machine.drawSprite(1, pos_x -8, pos_y);
}
