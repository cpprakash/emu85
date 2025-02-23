#include "../includes/Helper.hpp"

#include <iostream>

bool Helper::CheckIfRegistersAreValid(const std::string &reg) {
  if (reg == "A" || reg == "B" || reg == "C" || reg == "D" || reg == "E" ||
      reg == "H" || reg == "L" || reg == "M") {
    return true;
  }
  return false;
}
bool Helper::CheckIfValueIsInRange(const std::string &val,
                                   const std::string &base) {
  if (CheckIfBaseIsValid(base)) {
    return true;
  }
  return false;
}

bool Helper::CheckIfBaseIsValid(const std::string &base) {
  if (base == "H" || base == "h" || // hex
      base == "D" || base == "d" || // decimal
      base == "NEWLINE" ||          // decimal default
      base == "O" || base == "o" || // octal
      base == "Q" || base == "q" || // ocatal
      base == "B" || base == "b")
    return true;
  return false;
}

bool Helper::CheckIfAddressInRange(const std::string &add) {
  if (std::stoi(add, nullptr, 16) < 0xFFFF)
    return true;
  return false;
}

int ConvertHexToDecimal(const std::string &num) { return 0; }

unsigned char Helper::GetHexCodeForInstruction(const std::string &instruction) {
  std::cout << "GetHexCodeForInstruction called inst =" << instruction
            << std::endl;
  // Instructions m_inst;
  /*if (Helper::m_mapInstructionTable.size() !=
      246) { // Total instructions are 246
    InsertInstructionsInMap();
  }
  const auto code = m_mapInstructionTable.find(instruction);
  if (code != m_mapInstructionTable.end()) { // the instruction is in map
    return code->second;
  } else { // instruction was not found in the map, wrong instruction
    std::cout << "Assembler::GetHexCodeFromInstruction::Error in retreiving key"
              << std::endl;
    return 0x76; // return halt as of now
  }*/
  return 0x76;
}
