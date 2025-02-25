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
  std::cout << "Helper::CheckIfAddressInRange " << std::endl;
  int base = 10;
  if (add[add.length() - 1] == 'h' || add[add.length() - 1] == 'H') {
    std::cout << "Helper::CheckIfAddressInRange parsing address Numner is "
                 "invalid hex please check the number "
              << add << std::endl;
    for (unsigned long i = 0; i < add.length() - 1; i++) {
      std::cout << "Helper::CheckIfAddressInRange:: add[i]=" << add[i]
                << std::endl;
      if (isdigit(add[i]) && (add[i] < '0' || add[i] > '9')) {
        std::cout << "Helper::CheckIfAddressInRange Numner is invalid hex "
                     "isdigit(add[i]) && (add[i] < '0' || add[i] > '9') please "
                     "check the number "
                  << add << std::endl;
        return false;
      }
      if ((add[add.length() - 1] == 'H') && isalpha(add[i]) &&
          (add[i] < 'A' || add[i] > 'F')) {
        std::cout << "Helper::CheckIfAddressInRange Numner is invalid hex "
                     "isalpha(add[i]) && (add[i] < 'A' || add[i] > 'F' please "
                     "check the number "
                  << add << std::endl;
        return false;
      }
      if ((add[add.length() - 1] == 'h') && isalpha(add[i]) &&
          (add[i] < 'a' || add[i] > 'f')) {
        std::cout << "Helper::CheckIfAddressInRange Numner is invalid hex "
                     "isalpha(add[i]) && (add[i] < 'a' || add[i] > 'f' please "
                     "check the number "
                  << add << std::endl;
        return false;
      }
    }
    base = 16;
  }
  // check if number is decimal
  else if (add[add.length() - 1] == 'd' || add[add.length() - 1] == 'D' ||
           isdigit(add[add.length() - 1])) {
    base = 10;
  }
  /// check if number is octal
  if (add[add.length() - 1] == 'o' || add[add.length() - 1] == 'Q') {
    base = 8;
  }
  // check if number is binary
  else if (add[add.length() - 1] == 'b' || add[add.length() - 1] == 'B') {
    base = 2;
  }
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
