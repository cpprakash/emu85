COMPILER=g++
COMPILER_VERSION=-std=c++17

COMPILER_OPTIONS= -Werror -Wreorder -Wsign-compare -Waddress -Wcomment -Wformat -Wbool-compare -Wuninitialized -Wunknown-pragmas -Wunused-value -Wpointer-arith -Wcast-qual -Wno-missing-braces -Wunused-value #-Wall
COMPILER_INCLUDES=-I./src./headers

PROJECT=$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES)  -o emu8085

BUILD_DIR=build

MAIN=$(BUILD_DIR)/main.o
INSTRUCTIONS=$(BUILD_DIR)/Instructions.o

emu8085: createdir main.o Instructions.o
	$(PROJECT) main.o $(INSTRUCTIONS)

createdir: clean
	mkdir $(BUILD_DIR)

Instructions.o: src/Instructions.cpp headers/Instructions.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Instructions.cpp -o $(INSTRUCTIONS)

main.o: main.cpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) -c main.cpp -o main.o

clean:
	rm -rf $(BUILD_DIR)