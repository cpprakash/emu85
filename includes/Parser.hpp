#ifndef __INCLUDES_PARSER_HPP__
#define __INCLUDES_PARSER_HPP__

#include <vector>

#include "Types.hpp"

/***
 * class to handle file operation
 */
class Parser {
public:
  u_BYTE *ParseProgram(const std::vector<TokenStruct> &tokens);

private:
  bool ReturnInstructionHex(const std::string &inst);
  void HandleAndSaveError(const TokenStruct &token, ERROR_TYPES error_type,
                          const std::string &reason);
  TOKEN_TYPES ReturnTokenType(unsigned long index);
  void HandleAllInstructions(const TokenStruct &token);

  SixteenBitAddress HandleTokenLabel(const TokenStruct &token);
  SixteenBitAddress HandleTokenLabel(const std::string &token);
  void HandleTokenComment(const TokenStruct &token);

  void ParseSingleLine(const TokenStruct &token);
  std::string GetNextToken();
  std::vector<std::string> GetNextNTokens(unsigned int howMany);
  std::string PeekNextToken(unsigned long howMany = 1);

  void ParseLabels(const TokenStruct &token, const unsigned long index);

  /**
   * All instructions with AXX
   */
  bool HandleAciInstruction(const TokenStruct &token);
  bool HandleAdcInstruction(const TokenStruct &token);
  bool HandleAddInstruction(const TokenStruct &token);
  bool HandleAdiInstruction(const TokenStruct &token);
  bool HandleAnaInstruction(const TokenStruct &token);
  bool HandleAniInstruction(const TokenStruct &token);

  // LDA Instruction
  bool HandleLdaInstruction(const TokenStruct &token);
  // LDA Instruction
  bool HandleMovInstruction(const TokenStruct &token);
  // All MVI Instruction
  bool HandleMviInstruction(const TokenStruct &token);
  // SHLD Instruction
  bool HandleShldInstruction(const TokenStruct &token);

  // ADC, ADD, ANA, CMP, ORA, SBB, SUB, XRA,
  bool Handle8BitRegMemInstructions(const TokenStruct &token);
  // ACI, ADI, ANI, CPI,  MVI, ORI, SBI, SUI,  XRI,
  bool Handle8BitDataInstructions(const TokenStruct &token);
  /**
   * LDA, SDA, JC, JZ, JP, JPE, JNC, JNZ, JM, JPO, RC, RZ, RP, RPE, RNC, RNZ,
   * RM, RPO, CC, CZ, CP, CPE, CNC; CNZ, CM, CPO
   */
  bool Handle16BitAddressInstructions(const TokenStruct &token);
  // IN, OUT
  bool Handle8BitPortNumberInstructions(const TokenStruct &token);
  // RLC, RAL, RRC, RAR, CMA, DAA
  bool HandleAccumulatorInstruction(const TokenStruct &token);
  // INX, DCX, DAD
  bool Handle16BitRegPairInstructions(const TokenStruct &token);
  bool Handle16BitImmediateOperandInstructions(const TokenStruct &token);

  // Handle all control instructions DI, EI, HLT, NOP, RIM, SIM, RST
  bool HandleAllControlInstructions(const TokenStruct &token);

private:
  unsigned long m_currentIndex;
  unsigned short pCounter{0};
  std::string m_currentToken;
  bool m_bHasLabel{false};
  std::vector<SymbolTable> m_vecSymbolTable;
  unsigned long m_TotalBytesTillNow{0};

public:
  std::vector<TokenStruct> m_vectTokens;
  std::vector<AstStruct> m_astVectTokens;
  u_BYTE m_finalParserProgram[BIN_FILE_SIZE];
}; // end class Parser

#endif // end __HEADERS_PARSER_HPP__