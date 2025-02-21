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
  bool HandleAciInstruction(const TokenStruct &token);
  bool HandleAdcInstruction(const TokenStruct &token);
  bool HandleAddInstruction(const TokenStruct &token);
  bool HandleAdiInstruction(const TokenStruct &token);
  bool HandleAnaInstruction(const TokenStruct &token);
  bool HandleAniInstruction(const TokenStruct &token);
  // HLT Instruction
  bool HandleHltInstruction(const TokenStruct &token);
  // LDA Instruction
  bool HandleLdaInstruction(const TokenStruct &token);
  // All MVI Instruction
  bool HandleMviInstruction(const TokenStruct &token);
  // All STA Instruction
  bool HandleStaInstruction(const TokenStruct &token);

private:
  unsigned long m_currentIndex;
  std::string m_currentToken;

public:
  std::vector<TokenStruct> m_vectTokens;
}; // end class Parser

#endif // end __HEADERS_PARSER_HPP__