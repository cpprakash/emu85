COMPILER=g++
COMPILER_VERSION=-std=c++17

COMPILER_OPTIONS= -Werror -Wreorder -Wsign-compare -Waddress -Wcomment -Wformat -Wbool-compare -Wuninitialized -Wunknown-pragmas -Wunused-value -Wpointer-arith -Wcast-qual -Wno-missing-braces -Wunused-value #-Wall
COMPILER_INCLUDES=-I./src./headers

PROJECT=$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES)  -o emu8085

BUILD_DIR=build

emu8085: main.o
	$(PROJECT) main.o -o emu8085

main.o: main.cpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) -c main.cpp -o main.o