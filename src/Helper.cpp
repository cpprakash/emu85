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

/***
 * Helper fuction to convert a string to its uppercase
 */
std::string Helper::ConvertToUppercase(std::string input) {
  std::string out = "";
  for (unsigned long i = 0; i < input.length(); i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      std::cout << "Okay its a lowercase letter " << input[i] << std::endl;
      switch (input[i]) {
      case 'a':
        out += 'A';
        break;
      case 'b':
        out += "B";
        break;
      case 'c':
        out += "C";
        break;
      case 'd':
        out += "D";
        break;
      case 'e':
        out += "E";
        break;
      case 'f':
        out += "F";
        break;
      case 'g':
        out += "G";
        break;
      case 'h':
        out += "H";
        break;
      case 'i':
        out += "I";
        break;
      case 'j':
        out += "J";
        break;
      case 'k':
        out += "K";
        break;
      case 'l':
        out += "L";
        break;
      case 'm':
        out += "M";
        break;
      case 'n':
        out += "N";
        break;
      case 'o':
        out += "O";
        break;
      case 'p':
        out += "P";
        break;
      case 'q':
        out += "Q";
        break;
      case 'r':
        out += "R";
        break;
      case 's':
        out += "S";
        break;
      case 't':
        out += "T";
        break;
      case 'u':
        out += "U";
        break;
      case 'v':
        out += "V";
        break;
      case 'w':
        out += "W";
        break;
      case 'x':
        out += "X";
        break;
      case 'y':
        out += "Y";
        break;
      case 'z':
        out += "Z";
        break;

      default:
        break;
      }
    } else {
      std::cout << "Okay its a uppercase letter " << input[i] << std::endl;
      out += input[i];
    }
  }
  return out;
}

bool Helper::CheckIfAddressInRange(const std::string &add) {
  std::cout << "Helper::CheckIfAddressInRange " << std::endl;
  int base = 10;
  std::cout << Helper::ConvertToUppercase(add) << std::endl;
  std::string uppercaseAdd = Helper::ConvertToUppercase(add);
  if (uppercaseAdd[uppercaseAdd.length() - 1] == 'H') {
    std::cout << "Helper::CheckIfAddressInRange parsing address Numner is "
                 "invalid hex please check the number "
              << uppercaseAdd << std::endl;
    for (unsigned long i = 0; i < uppercaseAdd.length() - 1; i++) {
      std::cout << "Helper::CheckIfAddressInRange:: add[i]=" << add[i]
                << std::endl;
      if (isdigit(uppercaseAdd[i]) &&
          (uppercaseAdd[i] < '0' || uppercaseAdd[i] > '9')) {
        std::cout << "Helper::CheckIfAddressInRange Numner is invalid hex "
                     "isdigit(uppercaseAdd[i]) && (uppercaseAdd[i] < '0' || "
                     "uppercaseAdd[i] > "
                     "'9') please "
                     "check the number "
                  << add << std::endl;
        return false;
      }
      if (isalpha(uppercaseAdd[i]) &&
          (uppercaseAdd[i] < 'A' || uppercaseAdd[i] > 'F')) {
        std::cout << "Helper::CheckIfAddressInRange Numner is invalid hex "
                     "isalpha(uppercaseAdd[i]) && (uppercaseAdd[i] < 'A' || "
                     "uppercaseAdd[i] > "
                     "'F' please "
                     "check the number "
                  << add << std::endl;
        return false;
      }
    }
    base = 16;
  }
  // check if number is decimal
  else if (uppercaseAdd[add.length() - 1] == 'D' ||
           isdigit(uppercaseAdd[add.length() - 1])) {
    base = 10;
  }
  /// check if number is octal
  if (uppercaseAdd[uppercaseAdd.length() - 1] == 'Q') {
    base = 8;
  }
  // check if number is binary
  else if (uppercaseAdd[uppercaseAdd.length() - 1] == 'B') {
    base = 2;
  }
  if (std::stoi(uppercaseAdd, nullptr, 16) < 0xFFFF)
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
