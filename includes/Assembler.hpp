#ifndef __HEADERS_ASSEMBLER_HPP__
#define __HEADERS_ASSEMBLER_HPP__

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Instructions.hpp"

class Assembler {
public:
  Assembler() : start_address{0x0000}, has_errors{false} {
    for (auto i = 0; i < 0xFFFF; i++) {
      m_final_program[i] = 0x00;
    }
  }
  void AssembleProgram(std::vector<std::string> program);
  void RelocateAddress(unsigned short new_address);
  void UpdateCurrentAssembleAddress(unsigned short &address);

  void ParseLabels();

  unsigned short IncrementProgramAddress(void);

  const char &GetAccumulator();
  void SetAccumulator(const char *value);
  void WriteBinFile(void);

private:
  /**
   * All instructions with AXX
   */
  void HandleAciInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleAdcInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleAddInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleAdiInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleAnaInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleAniInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleHltInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleLdaInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void HandleMviInstruction(std::vector<std::string> &program,
                            unsigned int index);

  bool HandleStaInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void RunFinalProgram();

  bool CheckIfAddressInRange(const std::string &address);

  void SetErrorInProgram(void);

  unsigned char GetHexCodeFromInstruction(const std::string &instruction);

  bool ParseMviInstruction(std::vector<std::string> &program,
                           unsigned int index);

  bool StoreLowAndHighAddress(std::string &address);

public:
  std::vector<unsigned char> final_program[65 * 1024];
  unsigned char m_final_program[0xFFFF];
  unsigned short start_address;
  bool has_errors;

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
  // Instructions _instructions;
  std::map<std::string, unsigned char> inst_map;
  char m_cAccumulator; // Accumulator Register
};

#endif