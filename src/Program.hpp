#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <vector>

#include "Machine.hpp"

class Program {

    public:
        Program(Machine& machine);
        ~Program();

        void init();
        void update();
        void draw() const;

    private:
        Machine& machine;

        float pos_x;
        float pos_y;

        std::vector<std::vector<int>> menuBarMap;
        TileRect cursorTileRect;
};

#endif // __PROGRAM_HPP__
