#include "includes/Assembler.hpp"
#include "includes/FileHandler.hpp"

#define DEBUG = 1

/***
 * Main function, takes the filepath of the assembly as the argument
 * and then calls the ReadFile method from FileHandler class
 */
#ifdef DEBUG
int main(int argc, char *argv[]) {
  std::cout << "Hello World from 8085 Emulator argc=" << argc << argv[1]
            << std::endl;
  FileHandler file_handler;
  if (argc == 2) {
    file_handler.ReadFile(argv[1]);
  }

  return 0;
}
#endif
