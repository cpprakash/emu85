#ifndef __INCLUDES_FILEHANDLER_HPP__
#define __INCLUDES_FILEHANDLER_HPP__

#include <vector>

#include "Types.hpp"

/***
 * class to handle file operation
 */
class FileHandler {
public:
  FileHandler() {}
  const std::vector<TokenStruct> &ReturnTokens(const char *filePath);
  void ReadFile(char *file);
  bool WriteBinFile(const std::string &file, u_BYTE data[],
                    unsigned short size);

private:
  void GenerateTokens(const std::string &file_text);

public:
  std::vector<TokenStruct> m_vectTokens;
};

#endif