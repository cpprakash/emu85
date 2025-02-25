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
  void HandleAndSaveError(const TokenStruct &token, ERROR_TYPES error_type,
                          const std::string &reason);
  TOKEN_TYPES ReturnTokenType(unsigned long index);
  void HandleAllInstructions(const TokenStruct &token);

  void HandleTokenLabel(const TokenStruct &token);
  void HandleTokenComment(const TokenStruct &token);

  void ParseSingleLine(const TokenStruct &token);
  std::string GetNextToken();
  std::vector<std::string> GetNextNTokens(unsigned int howMany);
  std::string PeekNextToken(unsigned long howMany = 1);

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
  // LDA Instruction
  bool HandleMovInstruction(const TokenStruct &token);
  // All MVI Instruction
  bool HandleMviInstruction(const TokenStruct &token);
  // SHLD Instruction
  bool HandleShldInstruction(const TokenStruct &token);
  // All STA Instruction
  bool HandleStaInstruction(const TokenStruct &token);

private:
  unsigned long m_currentIndex;
  std::string m_currentToken;

public:
  std::vector<TokenStruct> m_vectTokens;
  std::vector<AstStruct> m_astVectTokens;
}; // end class Parser

#endif // end __HEADERS_PARSER_HPP__

/***
 * struct AstStruct {
  unsigned int lineNumber;   // line of the token
  unsigned int startPos;     // start pos of the token
  unsigned int endPos;       // end pos of token
  unsigned long totalLength; // length of the token
  std::string instruction;   // actual value
  std::string operandOne;    // actual value
  std::string operandTwo;    // actual value
  u_BYTE numberBase;
  bool hasErrors;
};
 */