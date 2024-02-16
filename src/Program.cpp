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

    machine.drawBackground(0, 0, 0);

    machine.drawFont(65, pos_x, pos_y);
    machine.drawFont(66, pos_x + 8, pos_y);
    machine.drawFont(67, pos_x + 16, pos_y);

    machine.drawSprite(1, pos_x -8, pos_y);
}
