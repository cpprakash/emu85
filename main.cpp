#include <iostream>

#include "headers/Instructions.hpp"

class FileHandler {
public:
  FileHandler() {}
  FileHandler(std::string file_path) {
    std::cout << "File path = " << file_path << std::endl;
  }
  void GenerateTokens();
};

int main(void) {
  std::cout << "Hello World from 8085 Emulator" << std::endl;
  return 0;
}

void FileHandler::GenerateTokens() {}
