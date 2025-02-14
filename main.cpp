#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "includes/Assembler.hpp"

#define DEBUG = 1

/***
 * class to handle file read
 */
class FileHandler {
public:
  FileHandler() {}
  FileHandler(const std::string &file_path) {
    std::cout << "File path = " << file_path << std::endl;
  }
  void ReadFile(char *file);

private:
  void GenerateTokens(const std::string &file_text);

private:
  Assembler _assembler;

public:
  std::vector<std::string> tokens;
};

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

/***
 * Reads the file based on the parameters passed from the main function
 */
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
    _assembler.AssembleProgram(tokens);
  } else {
    std::cout << "Unable to open file" << std::endl;
  }
}

/***
 * Generates the tokens based on the file content of the <program>.asm file
 */
void FileHandler::GenerateTokens(const std::string &file_text) {
  // std::cout << file_text << std::endl;
  for (unsigned int i = 0; i < file_text.length(); i++) {
    if (file_text[i] == '\n' || file_text[i] == '\r') { // newline character
      tokens.push_back("NEWLINE");
      continue;
    }
    if (isspace(file_text[i])) // check if token is space, do nothing
      continue;
    if (isalpha(file_text[i])) { // check if token starts with character
      std::string temp_string;
      while (isalpha(file_text[i])) { // collect the token
        temp_string += file_text[i];
        i++;
      }
      tokens.push_back(temp_string); // store the token
      i--;
      // std::cout << "Tempstring = " << temp_string << std::endl;
    } else if (isdigit(file_text[i])) { // check if token starts with a digit
      std::string temp_num;
      while (isdigit(file_text[i])) { // while it is a digit collect it
        temp_num += file_text[i];
        i++;
      }
      tokens.push_back(temp_num);
      i--;
      // std::cout << "TempNumber = " << temp_num << std::endl;
    } else if (file_text[i] == ',') {
      tokens.push_back("COMMA");
      // std::cout << "Token is comma" << std::endl;
    } else if (file_text[i] == ':') {
      tokens.push_back("COLON");
      // std::cout << "Token is comma" << std::endl;
    } else if (file_text[i] == ';') {
      tokens.push_back("COMMENT");
      // std::cout << "Token is comma" << std::endl;
    } else {
      std::cout << "Unknow token|" << file_text[i] << "|" << std::endl;
    }
    // std::cout << file_text[i] << std::endl;
  }
  tokens.push_back("EOF"); // end of file
}
