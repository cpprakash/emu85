#include "../includes/Assembler.hpp"

#include <bitset>

/***
 * Assemble the progrm
 */
void Assembler::AssembleProgram(std::vector<std::string> program) {

  if (program.size() == 0) { // Empty program
    std::cout << "Program is empty, cant assemble it." << std::endl;
    return;
  }

  /*for (size_t i = 0; i < program.size(); i++) {
    std::cout << "Token " << i << " = " << program[i] << std::endl;
  }*/
  for (unsigned long i = 0; i < program.size(); i++) {

    if (program[i] == "NEWLINE") {
      std::cout << "Processing the line " << this->m_iLineNumber << std::endl;
      this->m_iLineNumber++;
      // std::cout << "New line found, will escape" << std::endl;
      continue;
    }

    std::cout << "Token " << i << " = " << program[i] << std::endl;

    // EOF is the last token in the file
    if (program[i] == "EOF") {
      std::cout << "The end of file reached. Will return. " << std::endl;
      return;
    }

    // All AXX instructions
    if (program[i] == "ORG") {
      std::cout << "ORG directive found, have to relocate to " << program[i + 1]
                << std::endl;
      // each hex num must begin with a 0 and end with H, Decimal D,
      // Octal Q and Binary with B
      if (program[i + 2] != "H") {
        std::cout << "Error the relocation address is not in hex "
                  << program[i + 2] << std::endl;
        this->m_bHasErrors = true;
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
      std::cout << "HLT instruction found. Will halt the CPU" << std::endl;
      this->HandleHltInstruction(program, i);
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
      this->HandleLdaInstruction(program, i);
      i += 2; // skip two tokens
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
      HandleMviInstruction(program, i);
      i += 4; // ["MVI", "A", "," , "DATA", "H"]
      std::cout << "New index after MVI is " << i << std::endl;
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
      this->HandleStaInstruction(program, i);
      // TODO update only if the line parsed correctly
      i += 2; // skip 3 tokens ["STA", "ADDRESS", "H"]
      std::cout << "New index after STA is " << i << std::endl;
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
      this->SetErrorInProgram();
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
  } else if (program[index + 1] == "B") {
    std::cout << "ADD B instrution is found" << std::endl;
  } else if (program[index + 1] == "C") {
    std::cout << "ADD C instrution is found" << std::endl;
  } else if (program[index + 1] == "D") {
    std::cout << "ADD D instrution is found" << std::endl;
  } else if (program[index + 1] == "E") {
    std::cout << "ADD E instrution is found" << std::endl;
  } else if (program[index + 1] == "H") {
    std::cout << "ADD H instrution is found" << std::endl;
  } else if (program[index + 1] == "L") {
    std::cout << "ADD L instrution is found" << std::endl;
  } else if (program[index + 1] == "M") {
    std::cout << "ADD M instrution is found" << std::endl;
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

/***
 * Handle HLT instructions
 */
void Assembler::HandleHltInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleHltInstruction called with token = " << program[index]
            << " at index " << index << std::endl;

  this->m_final_program[this->IncrementProgramAddress()] =
      (this->GetHexCodeFromInstruction("INS_HLT"));
}

/**
 * Handle LDA Instructions
 */
void Assembler::HandleLdaInstruction(const std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleLdaInstruction called with token = " << program[index]
            << " at index " << index << std::endl;
  if (this->ParseInstAddressInstructions(program, index)) {
    std::cout << "HandleLdaInstruction finished" << std::endl;
  }
}

bool Assembler::ParseMviInstruction(std::vector<std::string> &program,
                                    unsigned int index) {
  // parse if only allowed registers are used in instructions
  if (!(program[index + 1] == "A" || program[index + 1] == "B" ||
        program[index + 1] == "C" || program[index + 1] == "D" ||
        program[index + 1] == "E" || program[index + 1] == "H" ||
        program[index + 1] == "L" || program[index + 1] == "M")) {
    std::cout << "The MVI Instruction contains invalid register (only "
                 "registers are allowed A,B,C,D,E,H,L,M). Please check"
              << std::endl
              << program[index] << " " << program[index + 1] << " " << std::endl
              << "  ^^^" << std::endl;
    return false;
  }
  // check if the comma is between instruction and operand
  if (program[index + 2] != "COMMA") {
    std::cout << "The MVI Instruction doesnt contain comma after register. "
                 "Please check"
              << std::endl
              << program[index] << " " << program[index + 1] << " "
              << program[index + 2] << " " << std::endl
              << "   ^^^"
              << " at line number =" << this->m_iLineNumber << std::endl;
    return false;
  }
  // find out which type of number was provided hex, dec, octal or binary
  if (program[index + 4] == "H" || program[index + 4] == "h") { // hex number
    this->m_charCurrentNumberSystem = 'H';
  } else if (program[index + 4] == "D" || program[index + 4] == "d" ||
             program[index + 4] == "NEWLINE") { // decimal number
    this->m_charCurrentNumberSystem = 'D';
  } else if (program[index + 4] == "Q" || program[index + 4] == "q" ||
             program[index + 4] == "O" ||
             program[index + 4] == "o") { // octal number
    this->m_charCurrentNumberSystem = 'O';
  } else if (program[index + 4] == "B" ||
             program[index + 4] == "b") { // binary number
    this->m_charCurrentNumberSystem = 'B';
  }
  std::cout << "The MVI Instruction setting the number system to "
            << this->m_charCurrentNumberSystem << std::endl;
  return true;
}

void ConvertDecimalToHex(std::string &num) {}
void ConvertHexToDecimal(std::string &num) {}

/**
 * Handle MVI Instructions
 */
void Assembler::HandleMviInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "HandleMviInstruction called with token = " << program[index]
            << " at index " << index << std::endl;
  if (!this->ParseMviInstruction(program, index)) {
    return;
  }
  if (program[index + 1] == "A") { // MVI A 8bit data
    std::cout << "HandleMviInstruction called for = " << program[index + 1]
              << " register."
              << " with the value of " << program[index + 3]
              << program[index + 4]
              << " and stoi = " << std::stoi(program[index + 3]) << std::endl;

    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_A_Data");

    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);

  } else if (program[index + 1] == "B") { // MVI B 8bit data
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_B_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else if (program[index + 1] == "C") { // MVI C 8bit data
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_C_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else if (program[index + 1] == "D") { // MVI D 8bit data
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_D_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else if (program[index + 1] == "E") { // MVI E 8bit data
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_E_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else if (program[index + 1] == "H") { // MVI H 8bit data*/
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_H_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else if (program[index + 1] == "L") { // MVI L 8bit data*/
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_L_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else if (program[index + 1] == "M") { // MVI M 8bit data
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_MVI_M_Data");
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(program[index + 3]);
  } else { // invalid instruction for MVI
    std::cout << "Invalid instruction found for MVI" << std::endl;
    this->SetErrorInProgram();
  }
}

/***
 * Handle STA instructions
 * STA <Address> 16 bits
 * return true if the instruction was parsed
 * return false otherwise
 */
bool Assembler::HandleStaInstruction(std::vector<std::string> &program,
                                     unsigned int index) {
  std::cout << "Assembler::HandleStaInstruction() called with token = "
            << program[index] << " at index " << index << " value at "
            << program[index + 1] << std::endl;

  if (this->CheckIfAddressInRange(program[index + 1])) {
    // address is in range
    this->m_final_program[IncrementProgramAddress()] =
        this->GetHexCodeFromInstruction("INS_STA_Address");
    if (!StoreLowAndHighAddress(program[index + 1]))
      return false;
    return true;
  } else {
    // address is invalid, program has erros
    std::cout << "Invalid address " << program[index + 1] << std::endl;
  }
  return false;
}

void Assembler::RunFinalProgram(void) {
  if (this->m_bHasErrors) {
    std::cout
        << "Program contains error, please fix them before running it again. "
        << std::endl;
    return;
  }
}

/**
 * Set the value of the accumulator
 */

void Assembler::SetAccumulator(const char *value) {
  std::cout << "Assembler::SetAccumulator::Old value of Acc= "
            << this->m_cAccumulator << std::endl;
  this->m_cAccumulator = atoi(value);
  std::cout << "Assembler::SetAccumulator::New value of Acc= "
            << this->m_cAccumulator << std::endl;
}

/***
 * Get the value of the accumulator register
 */
const char &Assembler::GetAccumulator() { return this->m_cAccumulator; }

/**
 * check if the address provided for the instruction is valid
 * return true if the address is valid
 * false otherwise
 */
bool Assembler::CheckIfAddressInRange(const std::string &address) {
  if ((std::stoi(address) < this->MAX_ADDRESS) && std::stoi(address) > 0)
    return true;
  return false;
}

/***
 * Set that the program that we are parsing contains error
 * so that the program cant be assembled
 * more info has to be supplied about error to the user TODO
 */
void Assembler::SetErrorInProgram(void) {
  if (!this->m_bHasErrors)
    this->m_bHasErrors = true;
}

/***
 * get the hex code based on the instruction passed
 * if the local map is empty, then make a call to the instructions class
 * fucntion to get a fresh copy of the instruction map
 * save this for later use and search in this map for the hex code
 * as of now if no code is found return the HLT code back
 */
unsigned char
Assembler::GetHexCodeFromInstruction(const std::string &instruction) {
  std::cout << "Assembler::GetHexCodeFromInstruction called inst ="
            << instruction << std::endl;
  // Instructions m_inst;
  if (this->inst_map.size() != 246) { // Total instructions are 246
    Instructions m_inst;
    this->inst_map = m_inst.FillInstructionTableWithInstructionsTwo();
  }
  const auto code = this->inst_map.find(instruction);
  if (code != this->inst_map.end()) { // the instruction is in map
    return code->second;
  } else { // instruction was not found in the map, wrong instruction
    std::cout << "Assembler::GetHexCodeFromInstruction::Error in retreiving key"
              << std::endl;
    return 0x76; // return halt as of now
  }
}

/***
 * Write the bin file for the 8085
 * it contains the opcode which can be executed on the CPU
 */
void Assembler::WriteBinFile(void) {
  if (this->m_bHasErrors) {
    std::cout << "The program contains errors, please finx them first"
              << std::endl;
    return;
  }
  std::ofstream out_file;
  out_file.open("./tests/prog.bin", std::ios::out | std::ios::binary);
  if (!out_file.is_open()) {
    std::cout << "Could not write to the file, please try again later!"
              << std::endl;
    return;
  }
  std::cout << "Writing bin file with a data size of ="
            << sizeof(m_final_program) << std::endl;
  out_file.write((char *)&m_final_program, sizeof(m_final_program));
  out_file.close();
}

unsigned short Assembler::IncrementProgramAddress(void) {
  return this->start_address++;
}

/***
 * Store low and high byte of the 16 bits address to the
 * final program array
 * rertun true if the address is valid
 * false otherwise
 * also has to convert the address or data as per the base
 * d (decimal) is the default base
 * Hexadecimal Data:- Each hexadecimal number must begin with a numeric digit (0
 * through 9) and must be followed by the letter H.
 */
bool Assembler::StoreLowAndHighAddress(const std::string &address,
                                       unsigned char base) {

  switch (this->m_charCurrentNumberSystem) {
  case 'H':
    break;
  case 'O':
    break;
  case 'B':
    break;
  case 'D':
  default:
    break;
  }

  if (address.length() == 2) { // the address is one bytes
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(address.substr(0, 2));
  } else if (address.length() == 3) { // the address is one and half bytes
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(address.substr(1, 2));
  } else if (address.length() == 4) { // the address is two bytes
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(address.substr(2, 2));
    this->m_final_program[IncrementProgramAddress()] =
        std::stoi(address.substr(0, 2));
  } else {
    std::cout << "[Assembler][StoreLowAndHighAddress]:: Error in the address. "
                 "Please check it again."
              << std::endl;
    return false;
  }
  return true;
}

/**
 * function to parser instructions which are in the format
 * instruction <16 bit address>
 * for example. LDA 1000H
 */
bool Assembler::ParseInstAddressInstructions(
    const std::vector<std::string> &program, const unsigned int index) {

  if (program[index] == "LDA") { // LDA <16 bit address>
    if (this->CheckIfAddressInRange(program[index + 1])) {
      this->m_final_program[IncrementProgramAddress()] =
          this->GetHexCodeFromInstruction("INS_LDA_Address");
      if (!StoreLowAndHighAddress(program[index + 1]))
        return false;

      return true;
    }
  }
  return false;
}