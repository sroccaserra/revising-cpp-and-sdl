CXX=g++
CPPFLAGS=$(shell sdl2-config --cflags) -I/usr/include/lua5.4
CXXFLAGS=-std=c++20 -Wall -pedantic
LDLIBS=$(shell sdl2-config --libs) -llua5.4

run: src/sdl
	src/sdl

src/sdl: src/Machine.o src/SdlMachine.o src/Program.o

clean:
	rm -f src/sdl src/*.o
