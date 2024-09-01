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

  std::string current_instruction_name{NOP};
  unsigned char current_instruction_opcode{0x00};
  std::map<std::string, std::pair<unsigned char, MachineCycleEnum>>
      instruction_map;
  enum Instruction {
    ACI,
    ADC,
    ADD,
    ADI,
    ANA,
    ANI,
    CALL,
    CC,
    CM,
    CMA,
    CMC,
    CMP,
    CNC,
    CNZ,
    CP,
    CPE,
    CPI,
    CPO,
    CZ,
    DAA,
    DAD,
    DCR,
    DCX,
    DI,
    EI,
    HLT,
    IN,
    INR,
    INX,
    JC,
    JM,
    JMP,
    JNC,
    JNZ,
    JP,
    JPE,
    JPO,
    JZ,
    LDA,
    LDAX,
    LHLD,
    LXI,
    MOV,
    MVI,
    NOP,
    ORA,
    ORI,
    OUT,
    PCHL,
    POP,
    PUSH,
    RAL,
    RAR,
    RC,
    RET,
    RIM,
    RLC,
    RM,
    RNC,
    RNZ,
    RP,
    RPE,
    RPO,
    RRC,
    RST,
    SSB,
    SBI,
    SHLD,
    SIM,
    SPHL,
    STA,
    STAX,
    STC,
    SUB,
    SUI,
    XCHG,
    XRA,
    XRI,
    XTHL
  };

  std::vector<InstructionTable> instruction_table;

private:
  unsigned int total_instructions;
};

#endif