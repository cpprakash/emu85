#include "../headers/Assembler.hpp"

/***
 * Assemble the progrm
 */
void Assembler::AssembleProgram(std::vector<std::string> program) {
  if (program.size() == 0) {
    std::cout << "Program is empty, cant assemble it." << std::endl;
    return;
  }

  for (size_t i = 0; i < program.size(); i++) {
    std::cout << "Token " << i << " = " << program[i] << std::endl;
    // All AXX instructions
    if (program[i] == "ORG") {
      std::cout << "ORG directive found, have to relocate to " << program[i + 1]
                << std::endl;
      if (program[i + 2] != "H") {
        std::cout << "Error the relocation address is not in hex "
                  << program[i + 2] << std::endl;
        has_errors = true;
      }
      if (program[i + 3] == ";") {
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