#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <vector>

#include "Machine.hpp"
#include "Input.hpp"

class Program {

    public:
        Program(Machine& machine);
        ~Program();

        void init();
        void update(const Input& input);
        void draw() const;

        bool shouldQuit;

    private:
        void reset();

        Machine& machine;

        TileMap menuBarMap;
        TileMap room_01;
        TileRect cursorTileRect;
};

#endif // __PROGRAM_HPP__
