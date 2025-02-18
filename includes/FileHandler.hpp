#ifndef __HEADERS_FILEHANDLER_HPP__
#define __HEADERS_FILEHANDLER_HPP__

#include <vector>

#include "Types.hpp"

/***
 * class to handle file operation
 */
class FileHandler {
public:
  FileHandler() {}
  void ReadFile(char *file);

private:
  void GenerateTokens(const std::string &file_text);

private:
public:
  // std::vector<std::string> tokens;
  std::vector<m_Token> m_vectTokens;
};

#endif