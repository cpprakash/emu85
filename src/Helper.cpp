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
std::string Helper::ConvertToUppercase(const std::string &input) {
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
// check if decimal number is valid
bool Helper::CheckDecimalNumber(const std::string &input) {
  std::cout << "[Helper]::[CheckDecimalNumber]::[start]" << std::endl;
  std::string number = "";
  for (unsigned long i = 0; i < input.length() - 1; i++)
  // last char because it will be either D or d, dont loop it
  {
    if (isdigit(input[i])) {
      number += input[i];
    } else // a not digit encountered
    {
      return false;
    }
  }
  if (std::stoi(number, nullptr, 10) < 256)
    return true;
  return false;
}
// check if binary number is valid
bool Helper::CheckBinaryNumber(const std::string &input) {
  std::cout << "[Helper]::[CheckBinaryNumber]::[start]" << std::endl;
  // if valid binary number is there, it should be atleast 2 char
  if (input.length() < 2) // should not be the case
  {
    return false;
  }
  std::string number = "";
  for (unsigned long i = 0; i < input.length() - 1; i++)
  // last char because it will be either D or d, dont loop it
  {
    std::cout << "Current digit is " << input[i] << std::endl;
    if (isdigit(input[i]) && (input[i] == '0' || input[i] == '1')) {
      number += input[i];
    } else // a not digit encountered
    {
      return false;
    }
  }
  if (std::stoi(input, nullptr, 2) < 256) {
    return true;
  }
  std::cout << "[Helper]::[CheckBinaryNumber]::[end false]"
            << std::stoi(input, nullptr, 2) << std::endl;
  return false;
}
// check if octal number is valid
bool Helper::CheckOctalNumber(const std::string &input) {
  if (std::stoi(input, nullptr, 10) < 256)
    return true;
  return false;
}
// check if hex number is valid
bool Helper::CheckHexNumber(const std::string &input) {
  if (std::stoi(input, nullptr, 10) < 256)
    return true;
  return false;
}

/***
 * helper function to check if an 8bit data is valid
 */
bool Helper::CheckIf8BitDataIsValid(const std::string &input) {
  if (input.length() < 1) // check if the input is not empty
    return false;
  if (input.length() == 1 && isdigit(input[0])) // must be a decimal number
  {
    return (std::stoi(input, nullptr, 10) < 256);
  }
  if (input.length() > 1 && isdigit(input[input.length() - 1])) // decimal
  {
    // handle decimal number
    return (std::stoi(input, nullptr, 10) < 256);
  }
  if (input.length() > 1) // can be any of these, decimal, hex, bin or octal
  {
    switch (input[input.length() - 1]) {
    case 'D':
    case 'd':
      // Handle decimal number
      return Helper::CheckDecimalNumber(input);
      break;
    case 'B':
    case 'b':
      // Handle binary number
      return Helper::CheckBinaryNumber(input);
      break;
    case 'O':
    case 'o':
    case 'Q':
    case 'q':
      // Handle ocatal number
      break;
    case 'H':
    case 'h':
      // Handle hex number
      break;
    default:
      break;
    }
  }
  return false;
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
