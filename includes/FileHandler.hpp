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

private:
  // Array of all Instructions
  std::array<std::string, 79ul> m_arrAllInstructions = {
      "ACI", "ADC", "ADD", "ADI",  "ANA",  "ANI",  "CALL", "CC",  "CM",
      "CMA", "CMC", "CMP", "CNC",  "CNZ",  "CP",   "CPE",  "CPI", "CPO",
      "CZ",  "DAA", "DAD", "DCR",  "DCX",  "DI",   "EI",   "HLT", "IN",
      "INR", "INX", "JC",  "JM",   "JMP",  "JNC",  "JNZ",  "JP",  "JPE",
      "JPO", "JZ",  "LDA", "LDAX", "LHLD", "LXI",  "MOV",  "MVI", "NOP",
      "ORA", "ORI", "OUT", "PCHL", "POP",  "PUSH", "RAL",  "RAR", "RC",
      "RET", "RIM", "RLC", "RM",   "RNC",  "RNZ",  "RP",   "RPE", "RPO",
      "RRC", "RST", "SSB", "SBI",  "SHLD", "SIM",  "SPHL", "STA", "STAX",
      "STC", "SUB", "SUI", "XCHG", "XRA",  "XRI",  "XTHL"};

public:
  std::vector<TokenStruct> m_vectTokens;
};

#endif