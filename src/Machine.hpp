#ifndef __MACHINE_HPP__
#define __MACHINE_HPP__

constexpr int tileW {8};
constexpr int tileH {8};

class Machine {
    public:
        Machine(int w, int h) : w {w}, h {h} {}
        virtual ~Machine() {};

        virtual void cls() const = 0;
        virtual void drawFont(const int n, const float x, const float y) const = 0;
        virtual void drawSprite(const int n, const float x, const float y) const = 0;
        virtual void drawBackground(const int n, const float x, const float y) const = 0;

        int w;
        int h;
};

#endif // __MACHINE_HPP__
