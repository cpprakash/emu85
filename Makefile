COMPILER=g++
COMPILER_VERSION=-std=c++17

COMPILER_OPTIONS= -Werror -Wreorder -Wsign-compare -Waddress -Wcomment -Wformat -Wbool-compare -Wuninitialized -Wunknown-pragmas -Wunused-value -Wpointer-arith -Wcast-qual -Wno-missing-braces -Wunused-value #-Wall
COMPILER_INCLUDES=-I./src./headers
WX_WIDGET=`wx-config --cxxflags --libs`

PROJECT=$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -o emu8085

BUILD_DIR=build

MAIN=$(BUILD_DIR)/main.o
INSTRUCTIONS=$(BUILD_DIR)/Instructions.o
ASSEMBLER=$(BUILD_DIR)/Assembler.o
MAIN_WINDOW=$(BUILD_DIR)/Main_Window.o

emu8085: createdir Main_Window.o main.o Instructions.o Assembler.o
	$(PROJECT) $(BUILD_DIR)/Main_Window.o main.o $(INSTRUCTIONS) $(WX_WIDGET) $(ASSEMBLER)

createdir: clean
	mkdir $(BUILD_DIR)

Instructions.o: src/Instructions.cpp headers/Instructions.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Instructions.cpp -o $(INSTRUCTIONS)

Assembler.o: src/Assembler.cpp headers/Assembler.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Assembler.cpp -o $(ASSEMBLER)

main.o: main.cpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) -c main.cpp -o main.o

Main_Window.o: main_window.cpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(WX_WIDGET) -c main_window.cpp -o $(MAIN_WINDOW)

clean:
	rm -rf $(BUILD_DIR)