#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "headers/Instructions.hpp"

class FileHandler {
public:
  FileHandler() {}
  FileHandler(std::string file_path) {
    std::cout << "File path = " << file_path << std::endl;
  }
  void ReadFile(char *file);

private:
  void GenerateTokens(std::string file_text);

public:
  std::vector<std::string> tokens;
};

int main(int argc, char *argv[]) {
  std::cout << "Hello World from 8085 Emulator argc=" << argc << argv[1]
            << std::endl;
  FileHandler file_handler;
  if (argc == 2) {
    file_handler.ReadFile(argv[1]);
  }

  return 0;
}

void FileHandler::ReadFile(char *file_path) {
  std::streampos size;
  char *memblock;

  std::ifstream file(file_path,
                     std::ios::in | std::ios::binary | std::ios::ate);
  if (file.is_open()) {
    size = file.tellg();
    memblock = new char[size];
    file.seekg(0, std::ios::beg);
    file.read(memblock, size);
    file.close();

    GenerateTokens(memblock);

    delete[] memblock;
  } else {
    std::cout << "Unable to open file";
  }
}
void FileHandler::GenerateTokens(std::string file_text) {
  // std::cout << file_text << std::endl;
  for (unsigned int i = 0; i < file_text.length(); i++) {
    if (isspace(file_text[i]))
      continue;
    if (isalpha(file_text[i])) {
      std::string temp_string;
      while (isalpha(file_text[i])) {
        temp_string += file_text[i];
        i++;
      }
      tokens.push_back(temp_string);
      i--;
      // std::cout << "Tempstring = " << temp_string << std::endl;
    } else if (isdigit(file_text[i])) {
      std::string temp_num;
      while (isdigit(file_text[i])) {
        temp_num += file_text[i];
        i++;
      }
      tokens.push_back(temp_num);
      i--;
      // std::cout << "TempNumber = " << temp_num << std::endl;
    } else if (file_text[i] == ',') {
      tokens.push_back("COMMA");
      // std::cout << "Token is comma" << std::endl;
    } else {
      std::cout << "Unknow token|" << file_text[i] << "|" << std::endl;
    }
    // std::cout << file_text[i] << std::endl;
  }
}
