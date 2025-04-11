#include "api/Api.hpp"
#include "includes/Disassembler.hpp"
#include "includes/FileHandler.hpp"
#include <iostream>
#define CONSOLE

/***
 * Main function, takes the filepath of the assembly as the argument
 * and then calls the ReadFile method from FileHandler class
 */

#ifdef CONSOLE
int main(int argc, char *argv[]) {
  std::cout << "Hello World from 8085 Emulator argc=" << argc << argv[1]
            << std::endl;

  // API stuff
  // Api api;
  // api.GetDataForGUI(argv[1]);

  FileHandler file_handler;
  if (argc == 2) {
    file_handler.ReadFile(argv[1]);

    Disassembler dis("./tests/prog.bin");
    dis.DisassembleProgram();

    return 0;
  }
}
#endif
