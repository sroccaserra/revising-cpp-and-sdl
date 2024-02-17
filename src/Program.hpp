#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <string>
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
        void drawText(const std::string &text, float x, float y) const;

        Machine& machine;

        float pos_x;
        float pos_y;
};

#endif // __PROGRAM_HPP__
