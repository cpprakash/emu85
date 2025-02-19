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
  void ParseSingleLine(const TokenStruct &token);
  std::string GetNextToken();

  /**
   * All instructions with AXX
   */
  void HandleAciInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleAdcInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleAddInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleAdiInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleAnaInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleAniInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleHltInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleLdaInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  void HandleMviInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

  bool HandleStaInstruction(const std::vector<TokenStruct> &program,
                            unsigned int index);

private:
  unsigned long m_currentIndex;
  std::string m_currentToken;

public:
  std::vector<TokenStruct> m_vectTokens;
}; // end class Parser

#endif // end __HEADERS_PARSER_HPP__