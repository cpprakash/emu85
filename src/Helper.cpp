#include "../includes/Helper.hpp"
#include "../includes/Types.hpp"
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
EightBitData Helper::CheckDecimalNumber(const std::string &input) {
  std::cout << "[Helper]::[CheckDecimalNumber]::[start]" << std::endl;
  bool result = false;
  std::string number = "";
  for (unsigned long i = 0; i < input.length() - 1; i++)
  // last char because it will be either D or d, dont loop it
  {
    if (isdigit(input[i])) {
      number += input[i];
    } else // a not digit encountered
    {
      result = false;
    }
  }
  if (std::stoi(number, nullptr, 10) < 256)
    result = true;
  return {"SUCCESS", (std::stoi(number, nullptr, 10)), result};
}
// check if binary number is valid
EightBitData Helper::CheckBinaryNumber(const std::string &input) {
  std::cout << "[Helper]::[CheckBinaryNumber]::[start]" << std::endl;
  EightBitData result{"", 0, false};
  // if valid binary number is there, it should be atleast 2 char
  if (input.length() < 2) // should not be the case
  {
    result.message = "FAIL. Data is too short.";
    result.result = false;
  }
  std::string number = "";
  for (unsigned long i = 0; i < input.length() - 1; i++)
  // last char because it will be either D or d, dont loop it
  {
    std::cout << "Current digit is " << input[i] << std::endl;
    if (isdigit(input[i]) && (input[i] == '0' || input[i] == '1')) {
      number += input[i];
    } else // a non binary digit encountered
    {
      result.message = "FAIL. Non binary digit found in binary data.";
      result.result = false;
    }
  }
  if (std::stoi(input, nullptr, 2) < 256) {
    result.message = "SUCCESS.";
    result.result = true;
  } else {
    result.message = "FAIL. The number is greater than one byte";
  }
  std::cout << "[Helper]::[CheckBinaryNumber]::[end false]"
            << std::stoi(input, nullptr, 2) << std::endl;
  return result;
}
// check if octal number is valid
EightBitData Helper::CheckOctalNumber(const std::string &input) {
  std::cout << "[Helper]::[CheckOctalNumber]::[start]" << std::endl;
  EightBitData result{"", 0, false};
  std::string number = "";
  for (unsigned long i = 0; i < input.length() - 1; i++)
  // last char because it will be either D or d, dont loop it
  {
    if (isdigit(input[i]) && (input[i] < 8)) {
      number += input[i];
    } else // a not digit encountered
    {
      result.result = false;
      result.message = "Invalid non digit found.";
    }
  }
  if (std::stoi(number, nullptr, 8) < 256) {
    result.result = true;
    result.message = MESSAGE_SUCCESS;
    result.data = std::stoi(number, nullptr, 8);
  } else {
    result.message = "Data is greater than one byte.";
  }
  std::cout << "[Helper]::[CheckOctalNumber]::[end]" << std::endl;
  return result;
}
// check if hex number is valid
EightBitData Helper::CheckHexNumber(const std::string &input) {
  std::cout << "[Helper]::[CheckHexNumber]::[start, input = " << input << "]"
            << std::endl;
  EightBitData result{"", 0, false};
  std::string number = "";

  for (unsigned long i = 0; i < input.length() - 1; i++)
  // last char because it will be either D or d, dont loop it
  {
    if (isdigit(input[i]) || (input[i] == 'A') || (input[i] == 'B') ||
        (input[i] == 'C') || (input[i] == 'D') || (input[i] == 'E') ||
        (input[i] == 'F') || (input[i] == 'a') || (input[i] == 'b') ||
        (input[i] == 'c') || (input[i] == 'd') || (input[i] == 'e') ||
        (input[i] == 'f')) {
      number += input[i];
    } else // a not digit encountered
    {
      result.result = false;
      result.message = "Invalid non digit found.";
    }
  }

  if (std::stoi(number, nullptr, 16) < 256) {
    result.result = true;
    result.data = std::stoi(number, nullptr, 16);
    result.message = MESSAGE_SUCCESS;
  } else {
    result.data = 0;
    result.message = "FAIL. The number is greater than one byte";
  }
  std::cout << "[Helper]::[CheckHexNumber]::[end]" << std::endl;
  return result;
}

/***
 * helper function to check if an 8bit data is valid
 */
EightBitData Helper::CheckIf8BitDataIsValid(const std::string &input) {
  std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[start]" << std::endl;
  if (input.length() < 1) // check if the input is not empty
  {
    std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[failed, data is empty]"
              << std::endl;
    return {"Validation failed, no value is provided", 0x00, false};
  }
  if ((input.length() == 1 && isdigit(input[0])) ||
      (input.length() > 1 &&
       isdigit(input[input.length() - 1]))) // must be a decimal number
  {
    if ((std::stoi(input, nullptr, 10) < 256))
      return {MESSAGE_SUCCESS, (std::stoi(input, nullptr, 10)),
              (std::stoi(input, nullptr, 10) < 256)};
  }

  if (input.length() > 1) // can be any of these, decimal, hex, bin or octal
  {
    const char kBase = (input[input.length() - 1]);
    if (kBase == 'D' || kBase == 'd') // Handle decimal number
    {
      std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[decimal number found]"
                << std::endl;
      // Handle decimal number
      if (Helper::CheckDecimalNumber(input).result)
        return (Helper::CheckDecimalNumber(input));
    } else if (kBase == 'B' || kBase == 'b') {
      std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[binary number found]"
                << std::endl;
      // Handle binary number
      /*if (Helper::CheckBinaryNumber(input).result)
        return (Helper::CheckBinaryNumber(input));*/
    } else if (kBase == 'O' || kBase == 'o' || kBase == 'Q' || kBase == 'q') {
      std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[octal number found]"
                << std::endl;
      // Handle ocatal number
    } else if (kBase == 'H' || kBase == 'h') {
      std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[hex number found]"
                << std::endl;
      // Handle hex number
      return (Helper::CheckHexNumber(input));
    }
  }
  std::cout << "[Helper]::[CheckIf8BitDataIsValid]::[end]" << std::endl;
  return {"FAIL", 0x00, false};
}

SixteenBitAddress Helper::CheckAndReturn16BitAddress(const std::string &input) {
  std::cout << "[Helper]::[CheckAndReturn16BitAddress]::[start input = ]"
            << input << std::endl;
  SixteenBitAddress address{"", 0, 0, false};
  u_BYTE lowByte = 0x00;
  u_BYTE highByte = 0x00;

  const u_WORD kLOW_BIT_MASK = 0x00FF;
  const u_WORD kHIGH_BIT_MASK = 0xFF00;

  if (input.length() < 1) // check if the input is not empty
  {
    std::cout
        << "[Helper]::[CheckAndReturn16BitAddress]::[failed, data is empty]"
        << std::endl;
    address.message = MESSAGE_EMPTY_FIELD;
  } // empty field
  else if ((input.length() == 1 && isdigit(input[0])) ||
           (input.length() > 1 &&
            isdigit(input[input.length() - 1]))) // must be a decimal number,
                                                 // default is decimal
  {
    const auto num = std::stoi(input, nullptr, 10);
    if (num > MAX_CHAR_ADDRESS) { // invalid address, more than 16bits
      address.message = "FAIL. The address is greater than 2 byte";
    } else { // valid 16 bit addrss in decimal
      address.message = MESSAGE_SUCCESS;
      address.addressLow = static_cast<unsigned char>(num & kLOW_BIT_MASK);
      address.addressHigh =
          static_cast<unsigned char>((num & kHIGH_BIT_MASK) >> 8);
      address.result = true;
    }
  }

  else if (input.length() > 1) // can be  decimal, hex, bin or octal
  {
    const char kBase = (input[input.length() - 1]);

    if (kBase == 'D' || kBase == 'd') // Handle decimal number
    {
      std::cout
          << "[Helper]::[CheckAndReturn16BitAddress]::[decimal number found]"
          << std::endl;
      const auto num =
          std::stoi(input.substr(0, input.length() - 1), nullptr, 10);
      if (num > MAX_CHAR_ADDRESS) { // invalid address, more than 16bits
        address.message = "FAIL. The address is greater than 2 byte";
      } else { // valid 16 bit addrss in decimal
        address.message = MESSAGE_SUCCESS;
        address.addressLow = static_cast<unsigned char>((num & kLOW_BIT_MASK));
        address.addressHigh =
            static_cast<unsigned char>((num & kHIGH_BIT_MASK) >> 8);
        address.result = true;
      }

    } else if (kBase == 'B' || kBase == 'b') {
      std::cout
          << "[Helper]::[CheckAndReturn16BitAddress]::[binary number found]"
          << std::endl;
      const auto num =
          std::stoi(input.substr(0, input.length() - 1), nullptr, 2);
      if (num > MAX_CHAR_ADDRESS) { // invalid address, more than 16bits
        address.message = "FAIL. The address is greater than 2 byte";
      } else { // valid 16 bit addrss in binary
        address.message = MESSAGE_SUCCESS;
        address.addressLow = static_cast<unsigned char>((num & kLOW_BIT_MASK));
        address.addressHigh =
            static_cast<unsigned char>((num & kHIGH_BIT_MASK) >> 8);
        address.result = true;
      }

    } else if (kBase == 'O' || kBase == 'o' || kBase == 'Q' || kBase == 'q') {
      std::cout
          << "[Helper]::[CheckAndReturn16BitAddress]::[octal number found]"
          << std::endl;
      const auto num =
          std::stoi(input.substr(0, input.length() - 1), nullptr, 8);
      if (num > MAX_CHAR_ADDRESS) { // invalid address, more than 16bits
        address.message = "FAIL. The address is greater than 2 byte";
      } else { // valid 16 bit addrss in octal
        address.message = MESSAGE_SUCCESS;
        address.addressLow = static_cast<unsigned char>(num & kLOW_BIT_MASK);
        address.addressHigh =
            static_cast<unsigned char>((num & kHIGH_BIT_MASK) >> 8);
        address.result = true;
      }

    } else if (kBase == 'H' || kBase == 'h') {
      std::cout << "[Helper]::[CheckAndReturn16BitAddress]::[hex number found]"
                << input << std::endl;

      // Handle hex number
      const auto num =
          std::stoi(input.substr(0, input.length() - 1), nullptr, 16);

      if (num > MAX_CHAR_ADDRESS) { // invalid address, more than 16bits
        address.message = "FAIL. The address is greater than 2 byte";
      } else { // valid 16 bit addrss in hex
        address.message = MESSAGE_SUCCESS;
        address.addressLow = static_cast<unsigned char>(num & kLOW_BIT_MASK);
        address.addressHigh =
            static_cast<unsigned char>((num & kHIGH_BIT_MASK) >> 8);
        address.result = true;
      }
    } else { // invalid number
      address.message = "FAIL. The address is invalid";
    }
  }

  std::cout << "[Helper]::[CheckAndReturn16BitAddress]::[end with "
            << address.message << " ]" << std::endl;
  return address;
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
