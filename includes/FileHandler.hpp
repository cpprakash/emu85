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
  bool WriteBinFile(const std::string &file, const unsigned char data[],
                    unsigned long size);

private:
  void GenerateTokens(const std::string &file_text);

private:
public:
  std::vector<TokenStruct> m_vectTokens;
};

#endif