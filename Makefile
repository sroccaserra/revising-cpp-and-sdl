CXX=g++
CPPFLAGS=$(shell sdl2-config --cflags)
CXXFLAGS=-std=c++20 -Wall -pedantic
LDLIBS=$(shell sdl2-config --libs)

run: src/sdl
	src/sdl

src/sdl: src/SdlState.o

clean:
	rm -f src/sdl src/*.o
