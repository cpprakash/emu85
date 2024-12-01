#include "../headers/Assembler.hpp"

/***
 * Assemble the progrm
 */
void Assembler::AssembleProgram(std::vector<std::string> program) {
  if (program.size() == 0) { // Empty program
    std::cout << "Program is empty, cant assemble it." << std::endl;
    return;
  }

  for (size_t i = 0; i < program.size(); i++) {

    if (program[i] == "NEWLINE") {
      std::cout << "New line found, will escape" << std::endl;
      continue;
    }

    std::cout << "Token " << i << " = " << program[i] << std::endl;

    // All AXX instructions
    if (program[i] == "ORG") {
      std::cout << "ORG directive found, have to relocate to " << program[i + 1]
                << std::endl;
      // each hex num must begin with a 0 and end with H, Decimal D,
      // Octal Q and Binary with B
      if (program[i + 2] != "H") {
        std::cout << "Error the relocation address is not in hex "
                  << program[i + 2] << std::endl;
        has_errors = true;
      }
    } else if (program[i] == "COMMENT") { // Comment found
      std::cout << "Comment Found " << std::endl;
      while (program[i] != "NEWLINE") {
        std::cout << " Escaping token " << program[i] << " at pos " << i
                  << std::endl;
        i++;
      }
    } else if (program[i] == "ACI") {
      std::cout << "ACI " << std::endl;
      HandleAciInstruction(program, i);
    } else if (program[i] == "ADC") {
      std::cout << "ADC " << std::endl;
      HandleAdcInstruction(program, i);
    } else if (program[i] == "ADD") {
      std::cout << "ADD " << std::endl;
      HandleAddInstruction(program, i);
    } else if (program[i] == "ADI") {
      std::cout << "ADI " << std::endl;
    } else if (program[i] == "ANA") {
      std::cout << "ANA " << std::endl;
    } else if (program[i] == "ANI") {
      std::cout << "ANI " << std::endl;
    }
    // all CXX instructions
    else if (program[i] == "CALL") {
      std::cout << "CALL " << std::endl;
    } else if (program[i] == "CC") {
      std::cout << "CC" << std::endl;
    } else if (program[i] == "CM") {
      std::cout << "CM" << std::endl;
    } else if (program[i] == "CMA") {
      std::cout << "CMA" << std::endl;
    } else if (program[i] == "CMC") {
      std::cout << "CMC" << std::endl;
    } else if (program[i] == "CMP") {
      std::cout << "CMP" << std::endl;
    } else if (program[i] == "CNC") {
      std::cout << "CNC " << std::endl;
    } else if (program[i] == "CNZ") {
      std::cout << "CNZ " << std::endl;
    } else if (program[i] == "CP") {
      std::cout << "CP " << std::endl;
    } else if (program[i] == "CPE") {
      std::cout << "CPE " << std::endl;
    } else if (program[i] == "CPI") {
      std::cout << "CPI " << std::endl;
    } else if (program[i] == "CPO") {
      std::cout << "CPO " << std::endl;
    } else if (program[i] == "CZ") {
      std::cout << "CZ " << std::endl;
    }

    // all DXX instructions
    else if (program[i] == "DAA") {
      // TODO
    } else if (program[i] == "DAD") {
      // TODO handle DAD instructions
    } else if (program[i] == "DCR") {
      // TODO handle DCR instructions
    } else if (program[i] == "DCX") {
      // TODO handle DCX instructions
    } else if (program[i] == "DI") {
      // TODO handle DI instruction
    }

    // all EXX instructions
    else if (program[i] == "EI") {
      // TODO handle EI instruction
    }

    // HLT instruction
    else if (program[i] == "HLT") {
      // TODO handle HLT instruction
    }

    // handle all IN instrutions
    else if (program[i] == "IN") {
      // TODO handle IN Port address instruction
    }

    // handle all INR instructions
    else if (program[i] == "INR") {
      // TODO handle INR instruction
    }

    // handle all INX instrutions
    else if (program[i] == "INX") {
      // TODO handle INX Port address instruction
    }

    // handle all JC instrutions
    else if (program[i] == "JC") {
      // TODO handle JC Port address instruction
    }

    // handle all JM instrutions
    else if (program[i] == "JM") {
      // TODO handle JM Port address instruction
    }
    // handle all JMP instrutions
    else if (program[i] == "JMP") {
      // TODO handle JMP instruction
    }
    // handle all JNC instrutions
    else if (program[i] == "JNC") {
      // TODO handle JNC instruction
    }
    // handle all JNZ instrutions
    else if (program[i] == "JNZ") {
      // TODO handle JNZ instruction
    }
    // handle all JP instrutions
    else if (program[i] == "JP") {
      // TODO handle JP instruction
    }
    // handle all JPE instrutions
    else if (program[i] == "JPE") {
      // TODO handle JPE instruction
    }
    // handle all JPO instrutions
    else if (program[i] == "JPO") {
      // TODO handle JPO instruction
    }
    // handle all JZ instrutions
    else if (program[i] == "JZ") {
      // TODO handle JZ instruction
    }
    // handle all LDA instrutions
    else if (program[i] == "LDA") {
      // TODO handle LDA instruction
    }
    // handle all LDAXX instrutions
    else if (program[i] == "LDAX") {
      // TODO handle LDAX B, D instruction
    }
    // handle all LHLD instrutions
    else if (program[i] == "LHLD") {
      // TODO handle LHLD instruction
    }
    // handle all LXIXX instrutions
    else if (program[i] == "LXI") {
      // TODO handle LXI instruction
    }

    // handle all MOV XX instrutions
    else if (program[i] == "MOV") {
      // TODO handle MOV instruction
    }

    // handle all MVI instrutions
    else if (program[i] == "MVI") {
      // TODO handle MVI instruction
    }

    // handle all NOP instrutions
    else if (program[i] == "NOP") {
      // TODO handle NOP instruction
    }

    // handle all ORA XX instrutions
    else if (program[i] == "ORA") {
      // TODO handle ORA instruction
    }

    // handle all ORI instrutions
    else if (program[i] == "ORI") {
      // TODO handle ORI instruction
    }
    // handle all OUT instrutions
    else if (program[i] == "OUT") {
      // TODO handle OUT instruction
    }

    // handle all PCHL instrutions
    else if (program[i] == "PCHL") {
      // TODO handle PCHL instruction
    }

    // handle all POP XX instrutions
    else if (program[i] == "POP") {
      // TODO handle POP instruction
    }

    // handle all PUSH instrutions
    else if (program[i] == "PUSH") {
      // TODO handle PUSH instruction
    }

    // handle all RAL instrutions
    else if (program[i] == "RAL") {
      // TODO handle RAL instruction
    }

    // handle all RAR instrutions
    else if (program[i] == "RAR") {
      // TODO handle RAR instruction
    }

    // handle all RC instrutions
    else if (program[i] == "RC") {
      // TODO handle RC instruction
    }
    // handle all RET instrutions
    else if (program[i] == "RET") {
      // TODO handle RET instruction
    }
    // handle all RIM instrutions
    else if (program[i] == "RIM") {
      // TODO handle RIM instruction
    }
    // handle all RLC instrutions
    else if (program[i] == "RLC") {
      // TODO handle RLC instruction
    }
    // handle all RM instrutions
    else if (program[i] == "RM") {
      // TODO handle RM instruction
    }
    // handle all RNC instrutions
    else if (program[i] == "RNC") {
      // TODO handle RNC instruction
    }
    // handle all RNZ instrutions
    else if (program[i] == "RNZ") {
      // TODO handle RNZ instruction
    }
    // handle all RP instrutions
    else if (program[i] == "RP") {
      // TODO handle RP instruction
    }
    // handle all RPE instrutions
    else if (program[i] == "RPE") {
      // TODO handle RPE instruction
    }
    // handle all RPO instrutions
    else if (program[i] == "RPO") {
      // TODO handle RPO instruction
    }
    // handle all RRC instrutions
    else if (program[i] == "RRC") {
      // TODO handle RRC instruction
    }
    // handle all RST instrutions
    else if (program[i] == "RST") {
      // TODO handle RST instruction
    }
    // handle all RZ instrutions
    else if (program[i] == "RZ") {
      // TODO handle RZ instruction
    }
    // handle all SBB XX instrutions
    else if (program[i] == "SBB") {
      // TODO handle SBB instruction
    }
    // handle all SBI instrutions
    else if (program[i] == "SBI") {
      // TODO handle SBI instruction
    }
    // handle all SHLD instrutions
    else if (program[i] == "SHLD") {
      // TODO handle SHLD instruction
    }
    // handle all SIM instrutions
    else if (program[i] == "SIM") {
      // TODO handle SIM instruction
    }
    // handle all SPHL instrutions
    else if (program[i] == "SPHL") {
      // TODO handle SPHL instruction
    }
    // handle all STA instrutions
    else if (program[i] == "STA") {
      // TODO handle STA instruction
    }
    // handle all STAX X instrutions
    else if (program[i] == "STAX") {
      // TODO handle STAX instruction
    }
    // handle all STC instrutions
    else if (program[i] == "STC") {
      // TODO handle STC instruction
    }
    // handle all SUB XX instrutions
    else if (program[i] == "SUB") {
      // TODO handle SUB instruction
    }
    // handle all SUI instrutions
    else if (program[i] == "SUI") {
      // TODO handle SUI instruction
    }
    // handle all XCHG instrutions
    else if (program[i] == "XCHG") {
      // TODO handle XCHG instruction
    }
    // handle all XRA XX instrutions
    else if (program[i] == "XRA") {
      // TODO handle XRA instruction
    }
    // handle all XRI instrutions
    else if (program[i] == "XRI") {
      // TODO handle XRI instruction
    }
    // handle all XTHL instrutions
    else if (program[i] == "XTHL") {
      // TODO handle XTHL instruction
    } else {
      // No matching instruction found, throw unkown instruction error
      std::cout << "Error: Instruction " << program[i] << " is not recognized!"
                << std::endl;
    }
  }
}
/***
 * Relocate address based on ORG directive
 * ORG directive can shift the origin for the next instructions
 * example
 * Assume that the current value of the location counter is OFH (decimal15)
 * when the following ORG directive is encountered: PAG1: ORG OFFH ;ORG
 * ASSEMBLER TO LOCATION ;OFFH (decimal 225) The symbol PAG1 is assigned the
 * address OFH. The next instruction or data byte is assembled at location OFFH.
 */
void Assembler::RelocateAddress(unsigned short new_address) {}

void Assembler::UpdateCurrentAssembleAddress(unsigned short &address) {
  std::cout << "Updating the current assembler address" << std::endl;
}

/***
 * ParseLable function to parse the lable inside the ASM instrustions
 * the label can be of form
 * LABEL: OPCODE OPERAND ;COMMENT
 */
void Assembler::ParseLabels() {}

/**
 * Handle ACI Instructions
 */
void Assembler::HandleAciInstruction(std::vector<std::string> &program,
                                     unsigned int index) {}

/***
 * Handle ADC instructions
 */
void Assembler::HandleAdcInstruction(std::vector<std::string> &program,
                                     unsigned int index) {}

/***
 * Handle ADD instructions
 */
void Assembler::HandleAddInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleAddInstructions called with token = " << program[index]
            << " at index " << index << std::endl;
  if (program[index + 1] == "A") {
    std::cout << "ADD A instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;

    unsigned char code;
    code = _instructions.instruction_map2.at("INS_ADD_A");
    std::cout << "Code === " << code << std::endl;
  } else if (program[index + 1] == "B") {
    std::cout << "ADD B instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
    unsigned char code;
    code = _instructions.instruction_map2.at("INS_ADD_B");
    std::cout << "Code === " << code << std::endl;
  } else if (program[index + 1] == "C") {
    std::cout << "ADD C instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    unsigned char code;
    code = _instructions.instruction_map2.at("INS_ADD_C");
    std::cout << "Code === " << code << std::endl;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
  } else if (program[index + 1] == "D") {
    std::cout << "ADD D instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    unsigned char code;
    code = _instructions.instruction_map2.at("INS_ADD_D");
    std::cout << "Code === " << code << std::endl;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
  } else if (program[index + 1] == "E") {
    std::cout << "ADD E instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    unsigned char code;
    code = _instructions.instruction_map2.at("INS_ADD_E");
    std::cout << "Code === " << code << std::endl;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
  } else if (program[index + 1] == "H") {
    std::cout << "ADD H instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    unsigned char code;
    code = _instructions.instruction_map2.at("INS_ADD_H");
    std::cout << "Code === " << code << std::endl;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
  } else if (program[index + 1] == "L") {
    std::cout << "ADD L instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
  } else if (program[index + 1] == "M") {
    std::cout << "ADD M instrution is found" << std::endl;

    std::map<std::string, std::pair<unsigned char, unsigned char>> my_map;
    // my_map = _instructions.instruction_map.find("INS_ADD_A");
  } else {
    // error no matching instruction found with ADD X
  }
}
/***
 * Handle ADI instructions
 */
void Assembler::HandleAdiInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleAdiInstruction called with token = " << program[index]
            << " at index " << index << std::endl;
}
/***
 * Handle ANA instructions
 */
void Assembler::HandleAnaInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleAnaInstruction called with token = " << program[index]
            << " at index " << index << std::endl;
  if (program[index + 1] == "A") {
    std::cout << "ANA A instrution is found" << std::endl;
  } else if (program[index + 1] == "B") {
    std::cout << "ANA B instrution is found" << std::endl;
  } else if (program[index + 1] == "C") {
    std::cout << "ANA C instrution is found" << std::endl;
  } else if (program[index + 1] == "D") {
    std::cout << "ANA D instrution is found" << std::endl;
  } else if (program[index + 1] == "E") {
    std::cout << "ANA E instrution is found" << std::endl;
  } else if (program[index + 1] == "H") {
    std::cout << "ANA H instrution is found" << std::endl;
  } else if (program[index + 1] == "L") {
    std::cout << "ANA L instrution is found" << std::endl;
  } else if (program[index + 1] == "M") {
    std::cout << "ANA M instrution is found" << std::endl;
  } else {
    // Error no instruction found matching ANA X
  }
}
/***
 * Handle ANI instructions
 */
void Assembler::HandleAniInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleAniInstruction called with token = " << program[index]
            << " at index " << index << std::endl;
}

/**
 * Handle LDA Instructions
 */
void Assembler::HandleLdaInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleLdaInstruction called with token = " << program[index]
            << " at index " << index << std::endl;
}

void Assembler::RunFinalProgram(void) {
  if (has_errors) {
    std::cout
        << "Program contains error, please fix them before running it again. "
        << std::endl;
    return;
  }
}