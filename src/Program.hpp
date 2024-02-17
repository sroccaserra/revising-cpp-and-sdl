#ifndef __PROGRAM_HPP__
#define __PROGRAM_HPP__

#include <string>
#include <vector>

extern "C" {
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "Machine.hpp"

class Program {

    public:
        Program(Machine& machine);
        ~Program();

        void init();
        void update();
        void draw() const;

    private:
        void loadConfig();
        std::vector<std::vector<int>> loadIntMatrix(std::string name);
        void drawText(const std::string &text, float x, float y) const;

        Machine& machine;
        lua_State* L;

        float pos_x;
        float pos_y;
};

#endif // __PROGRAM_HPP__
