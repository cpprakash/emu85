COMPILER=g++
COMPILER_VERSION=-std=c++17

COMPILER_OPTIONS= -Werror -Wreorder -Wsign-compare -Waddress -Wcomment -Wformat -Wbool-compare -Wuninitialized -Wunknown-pragmas -Wunused-value -Wpointer-arith -Wcast-qual -Wno-missing-braces -Wunused-value #-Wall
COMPILER_INCLUDES=-I./src./headers
WX_WIDGET=`wx-config --cxxflags --libs`

PROJECT=$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -o build/emu8085

BUILD_DIR=build

MAIN=$(BUILD_DIR)/main.o
INSTRUCTIONS=$(BUILD_DIR)/Instructions.o
ASSEMBLER=$(BUILD_DIR)/Assembler.o
MAIN_APP=$(BUILD_DIR)/MainApp.o
MAIN_FRAME=$(BUILD_DIR)/MainFrame.o
FILE_HANDLER=$(BUILD_DIR)/FileHandler.o
PARSER=$(BUILD_DIR)/Parser.o
HELPER=$(BUILD_DIR)/Helper.o
API=$(BUILD_DIR)/Api.o
DISASSEMBLER=$(BUILD_DIR)/Disassembler.o

emu8085: createdir MainApp.o main.o FileHandler.o Parser.o Instructions.o Assembler.o Api.o Helper.o MainFrame.o
	$(PROJECT) $(BUILD_DIR)/MainApp.o $(MAIN) $(INSTRUCTIONS) $(WX_WIDGET) $(ASSEMBLER) $(API) $(MAIN_FRAME)

createdir: clean
	mkdir $(BUILD_DIR)

Instructions.o: src/Instructions.cpp includes/Instructions.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Instructions.cpp -o $(INSTRUCTIONS)

Assembler.o: src/Assembler.cpp includes/Assembler.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Assembler.cpp -o $(ASSEMBLER)

Disassembler.o: src/Disassembler.cpp includes/Disassembler.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Disassembler.cpp -o $(DISASSEMBLER)

FileHandler.o: src/FileHandler.cpp includes/FileHandler.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/FileHandler.cpp -o $(FILE_HANDLER)

Parser.o: src/Parser.cpp includes/Parser.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Parser.cpp -o $(PARSER)

Helper.o: src/Helper.cpp includes/Helper.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c src/Helper.cpp -o $(HELPER)

Api.o: api/Api.cpp api/Api.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -c api/Api.cpp -o $(API)

main.o: main.cpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) -c main.cpp -o $(MAIN)

MainFrame.o: src/MainFrame.cpp includes/MainFrame.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(WX_WIDGET) -c src/MainFrame.cpp -o $(MAIN_FRAME)

MainApp.o: src/MainApp.cpp includes/MainApp.hpp
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(WX_WIDGET) -c src/MainApp.cpp -o $(MAIN_APP)

clean:
	rm -rf $(BUILD_DIR)

console: createdir main.o Instructions.o Assembler.o FileHandler.o Parser.o Helper.o Api.o Disassembler.o
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES)  -o build/emu8085 $(MAIN) $(INSTRUCTIONS) $(FILE_HANDLER) $(ASSEMBLER) $(PARSER) $(HELPER)  $(API)  $(DISASSEMBLER)

debug: createdir main.o Instructions.o Assembler.o FileHandler.o
	$(COMPILER) $(COMPILER_VERSION) $(COMPILER_OPTIONS) $(COMPILER_INCLUDES) -g -o build/emu8085 main.o $(INSTRUCTIONS) $(FILE_HANDLER) $(ASSEMBLER) 