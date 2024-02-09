CXX=g++
CPPFLAGS=$(shell sdl2-config --cflags)
CXXFLAGS=-std=c++20 -Wall -pedantic
LDLIBS=$(shell sdl2-config --libs)

run: sdl
	./sdl

clean:
	rm -f sdl
