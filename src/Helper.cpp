#include "../includes/Helper.hpp"

#include <iostream>
#include <string>

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
  std::string output = "";

  for (unsigned long i = 0; i < input.length(); i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      output += std::toupper(input[i]);
    } else {
      output += input[i];
    }
  }

  return output;
}

bool Helper::CheckIfAddressInRange(const std::string &add) {
  std::cout << "[Helper]::[CheckIfAddressInRange]::[start]" << std::endl;
  int base = 10;
  // std::cout << Helper::ConvertToUppercase(add) << std::endl;
  std::string uppercaseAdd = Helper::ConvertToUppercase(add);
  if (uppercaseAdd[uppercaseAdd.length() - 1] == 'H') {
    for (unsigned long i = 0; i < uppercaseAdd.length() - 1; i++) {
      if (isdigit(uppercaseAdd[i]) &&
          (uppercaseAdd[i] < '0' || uppercaseAdd[i] > '9')) {
        return false;
      }
      if (isalpha(uppercaseAdd[i]) &&
          (uppercaseAdd[i] < 'A' || uppercaseAdd[i] > 'F')) {
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
