#ifndef __HEADERS_INSTRUCTIONS_HPP__
#define __HEADERS_INSTRUCTIONS_HPP__

#include <iostream>
#include <map>
#include <vector>

class Instructions {
public:
  Instructions(void);

private:
  void FetchNextInstructions(void);
  void FillInstructionTableWithInstructions(void);

public:
  enum MachineCycleEnum { ONE = 1, TWO, THREE };
  struct InstructionTable {
    std::string instruction_name;
    unsigned char instruction_code;
    MachineCycleEnum machine_cycles;
  };

  unsigned char current_instruction_opcode{0x00};
  std::map<std::string, std::pair<unsigned char, MachineCycleEnum>>
      instruction_map;
  std::map<std::string, unsigned char> instruction_map2;

private:
  unsigned int total_instructions;
};

#endif