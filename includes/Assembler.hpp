#ifndef __HEADERS_ASSEMBLER_HPP__
#define __HEADERS_ASSEMBLER_HPP__

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "FileHandler.hpp"
#include "Instructions.hpp"
#include "Types.hpp"

class Assembler {
public:
  Assembler() : start_address{0x0000}, m_bHasErrors{false}, m_iLineNumber{0} {
    for (auto i = 0; i < 0xFFFF; i++) {
      m_final_program[i] = 0x00;
    }
  }
  void AssembleProgram(std::vector<TokenStruct> program);
  void RelocateAddress(unsigned short new_address);
  void UpdateCurrentAssembleAddress(unsigned short &address);

  void ParseLabels();

  unsigned short IncrementProgramAddress(void);

  void WriteBinFile(void);

private:
  void RunFinalProgram();

  bool CheckIfAddressInRange(const std::string &address);

  void SetErrorInProgram(void);

  bool StoreLowAndHighAddress(const std::string &address,
                              unsigned char base = 'd');

public:
  std::vector<unsigned char> final_program[65 * 1024];
  unsigned char m_final_program[0xFFFF];
  unsigned short start_address;
  bool m_bHasErrors;

private:
  struct ErrorMessage {
    unsigned int token_line_number;  // line number where error occured
    std::string current_token_value; // current token which caused error
    std::string last_token_value;    // last valid token
    std::string next_token_Value;    // next token for parsing
    unsigned int token_number;       // index of token
  };
  std::vector<ErrorMessage> ErrorMessages; // vector of error messages
  unsigned short MAX_ADDRESS = 0xFFFF;
  std::map<std::string, unsigned char> inst_map;
  unsigned char m_charCurrentNumberSystem{'d'};
  std::string m_strCurrentNumberLength;
  unsigned int m_iLineNumber = 0;
};

#endif