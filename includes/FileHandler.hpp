#ifndef __HEADERS_FILEHANDLER_HPP__
#define __HEADERS_FILEHANDLER_HPP__

#include <vector>

#include "../includes/Assembler.hpp"
/***
 * class to handle file operation
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

#endif