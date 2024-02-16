#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include "Machine.hpp"

class Program {

    public:
        Program(Machine& machine) : machine {machine} {}

        void init();
        void update();
        void draw() const;

    private:
        Machine& machine;
        float pos_x;
        float pos_y;
};

#endif // __PROGRAM_HPP__
