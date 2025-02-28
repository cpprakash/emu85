#include "../includes/Assembler.hpp"

#include <bitset>

/***
 * Assemble the progrm
 */
void Assembler::AssembleProgram(std::vector<TokenStruct> program) {
  /***
   * clear the final program array
   */
  for (auto i = 0; i <= 0xFFFF; i++) {
    this->m_final_program[i] = 0x00;
  }

  if (program.size() == 0) { // Empty program
    std::cout << "Program is empty, cant assemble it." << std::endl;
    return;
  }

  /*for (size_t i = 0; i < program.size(); i++) {
    std::cout << "Token " << i << " = " << program[i] << std::endl;
  }*/
  for (unsigned long i = 0; i < program.size(); i++) {

    if (program[i].m_tokenValue == "NEWLINE") {
      std::cout << "Processing the line " << this->m_iLineNumber << std::endl;
      this->m_iLineNumber++;
      // std::cout << "New line found, will escape" << std::endl;
      continue;
    }

    // std::cout << "Token " << i << " = " << program[i].m_tokenValue <<
    // std::endl;

    // EOF is the last token in the file
    if (program[i].m_tokenValue == "EOF") {
      std::cout << "The end of file reached. Will return. " << std::endl;
      return;
    } else {
      // No matching instruction found, throw unkown instruction error
      std::cout << "Error: Instruction " << program[i].m_tokenValue
                << " is not recognized!" << std::endl;
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

void ConvertDecimalToHex(std::string &num) {}
void ConvertHexToDecimal(std::string &num) {}

void Assembler::RunFinalProgram(void) {
  if (this->m_bHasErrors) {
    std::cout
        << "Program contains error, please fix them before running it again. "
        << std::endl;
    return;
  }
}

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
/*unsigned char
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
}*/

/***
 * Write the bin file for the 8085
 * it contains the opcode which can be executed on the CPU
 */
void Assembler::WriteBinFile(void) {
  if (this->m_bHasErrors) {
    std::cout << "The program contains errors, please finx them first"
              << std::endl;
    return;
  } else {
    FileHandler m_fileHandler;
    if (m_fileHandler.WriteBinFile("./tests/prog.bin", m_final_program,
                                   sizeof(m_final_program))) {
      std::cout << "Program file created." << std::endl;
    } else {
      std::cout << "Program file could not be created. Try again" << std::endl;
    }
  }

  /*std::ofstream out_file;
  out_file.open("./tests/prog.bin", std::ios::out | std::ios::binary);
  if (!out_file.is_open()) {
    std::cout << "Could not write to the file, please try again later!"
              << std::endl;
    return;
  }
  std::cout << "Writing bin file with a data size of ="
            << sizeof(m_final_program) << std::endl;
  out_file.write((char *)&m_final_program, sizeof(m_final_program));
  out_file.close();*/
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
/*bool Assembler::ParseInstAddressInstructions(
    const std::vector<TokenStruct> &program, const unsigned int index) {

  if (program[index].m_tokenValue == "LDA") { // LDA <16 bit address>
    if (this->CheckIfAddressInRange(program[index + 1].m_tokenValue)) {
      this->m_final_program[IncrementProgramAddress()] =
          this->GetHexCodeFromInstruction("INS_LDA_Address");
      if (!StoreLowAndHighAddress(program[index + 1].m_tokenValue))
        return false;

      return true;
    }
  }
  return false;
}*/