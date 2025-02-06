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
MAIN_APP=$(BUILD_DIR)/MainApp.o
MAIN_FRAME=$(BUILD_DIR)/MainFrame.o

emu8085: createdir MainApp.o main.o Instructions.o Assembler.o MainFrame.o
	$(PROJECT) $(BUILD_DIR)/MainApp.o main.o $(INSTRUCTIONS) $(WX_WIDGET) $(ASSEMBLER) $(MAIN_FRAME)

createdir: clean
	mkdir $(BUILD_DIR)

Instructions.o: src/Instructions.cpp includes/Instructions.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Instructions.cpp -o $(INSTRUCTIONS)

Assembler.o: src/Assembler.cpp includes/Assembler.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Assembler.cpp -o $(ASSEMBLER)

main.o: main.cpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) -c main.cpp -o main.o

MainFrame.o: src/MainFrame.cpp includes/MainFrame.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(WX_WIDGET) -c src/MainFrame.cpp -o $(MAIN_FRAME)

MainApp.o: src/MainApp.cpp includes/MainApp.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(WX_WIDGET) -c src/MainApp.cpp -o $(MAIN_APP)

clean:
	rm -rf $(BUILD_DIR)