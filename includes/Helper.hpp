#ifndef __HEADER__HELPER__
#define __HEADER__HELPER__

#include <map>
#include <string>

class Helper {

public:
private:
  unsigned char MIN_CHAR_DATA{0};
  unsigned char MIN_BOOL_DATA{0b0000};
  unsigned char MIN_HEX_DATA{0x00};
  unsigned char MIN_OCT_DATA{00};

  unsigned char MAX_CHAR_DATA{255};
  unsigned char MAX_BOOL_DATA{0b11111111};
  unsigned char MAX_HEX_DATA{0xFF};
  unsigned char MAX_OCT_DATA{0377};

  unsigned short MIN_CHAR_ADDRESS{0};
  unsigned short MIN_BOOL_ADDRESS{0b0000000000000000};
  unsigned short MIN_HEX_ADDRESS{0x0000};
  unsigned short MIN_OCT_ADDRESS{00};

  unsigned short MAX_CHAR_ADDRESS{65535};
  unsigned short MAX_BOOL_ADDRESS{0b1111111111111111};
  unsigned short MAX_HEX_ADDRESS{0xFFFF};
  unsigned short MAX_OCT_ADDRESS{0177777};

  std::map<std::string, unsigned char> *m_mapInstructionTable;

public:
  static bool CheckIfRegistersAreValid(const std::string &reg);
  static bool CheckIfValueIsInRange(const std::string &val,
                                    const std::string &base);
  static bool CheckIfAddressInRange(const std::string &add);
  static bool CheckIfBaseIsValid(const std::string &base);

  static int ConvertHexToDecimal(const std::string &num);

  static std::string ConvertToUppercase(const std::string &input);

  static bool CheckIf8BitDataIsValid(const std::string &input);

  static bool CheckDecimalNumber(const std::string &input);
  static bool CheckBinaryNumber(const std::string &input);
  static bool CheckOctalNumber(const std::string &input);
  static bool CheckHexNumber(const std::string &input);

private:
  // void InsertInstructionsInMap(void);
};

#endif