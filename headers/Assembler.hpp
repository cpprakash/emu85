#ifndef __HEADERS_ASSEMBLER_HPP__
#define __HEADERS_ASSEMBLER_HPP__

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Instructions.hpp"

class Assembler {
public:
  Assembler() : start_address{0x0000}, has_errors{false} {}
  void AssembleProgram(std::vector<std::string> program);
  void RelocateAddress(unsigned short new_address);
  void UpdateCurrentAssembleAddress(unsigned short &address);

  void ParseLabels();

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

  void HandleLdaInstruction(std::vector<std::string> &program,
                            unsigned int index);

  void RunFinalProgram();

public:
  std::vector<unsigned char> final_program;
  unsigned short start_address;
  bool has_errors;

private:
  Instructions _instructions;
};

#endif