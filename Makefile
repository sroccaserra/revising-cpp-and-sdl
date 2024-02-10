CXX=g++
CPPFLAGS=$(shell sdl2-config --cflags)
CXXFLAGS=-std=c++20 -Wall -pedantic -fmodules-ts
LDLIBS=$(shell sdl2-config --libs)

run: sdl
	./sdl

sdl: State.o

clean:
	rm -f sdl *.o
	rm -rf gcm.cache
