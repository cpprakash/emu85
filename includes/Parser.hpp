#ifndef __HEADERS_PARSER_HPP__
#define __HEADERS_PARSER_HPP__

#include <vector>

#include "Types.hpp"

/***
 * class to handle file operation
 */
class Parser {
public:
  void ParseProgram(const std::vector<TokenStruct> &tokens);

private:
  void GenerateTokens(const std::string &file_text);

private:
public:
  std::vector<TokenStruct> m_vectTokens;
}; // end class Parser

#endif // end __HEADERS_PARSER_HPP__