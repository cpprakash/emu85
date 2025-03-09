#ifndef __INCLUDES__HELPER__HPP__
#define __INCLUDES__HELPER__HPP__

#include <map>
#include <string>
#include <vector>

#include "../includes/Types.hpp"

class Helper {

public:
  std::vector<EightBitData> data_vector;
  std::vector<SixteenBitAddress> address_vector;

private:
  std::map<std::string, u_BYTE> *m_mapInstructionTable;

public:
  static bool CheckIfRegistersAreValid(const std::string &reg);
  static bool CheckIfValueIsInRange(const std::string &val,
                                    const std::string &base);
  static bool CheckIfAddressInRange(const std::string &add);
  static bool CheckIfBaseIsValid(const std::string &base);

  static std::string ConvertToUppercase(const std::string &input);

  static EightBitData CheckIf8BitDataIsValid(const std::string &input);

  static SixteenBitAddress CheckAndReturn16BitAddress(const std::string &add);

  static EightBitData CheckDecimalNumber(const std::string &input);
  static EightBitData CheckBinaryNumber(const std::string &input);
  static EightBitData CheckOctalNumber(const std::string &input);
  static EightBitData CheckHexNumber(const std::string &input);

private:
  // void InsertInstructionsInMap(void);
};

#endif