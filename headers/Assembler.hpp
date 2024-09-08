#ifndef __HEADERS_ASSEMBLER_HPP__
#define __HEADERS_ASSEMBLER_HPP__

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Instructions.hpp"

class Assembler {
public:
  Assembler() {}
  void AssembleProgram(std::vector<std::string> program);

private:
  void HandleAciInstructions(std::vector<std::string> &program,
                             unsigned int index);

  void HandleAdcInstructions(std::vector<std::string> &program,
                             unsigned int index);

  void HandleAddInstructions(std::vector<std::string> &program,
                             unsigned int index);

public:
  std::vector<unsigned char> final_program;

private:
  Instructions _instructions;
};

#endif