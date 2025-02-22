#ifndef __INCLUDES_TYPES_HPP
#define __INCLUDES_TYPES_HPP

#include <string>

typedef unsigned char u_BYTE;
typedef char BYTE;
typedef unsigned short u_WORD;
typedef short WORD;

// base for the operand
enum BASE { b, d, h, o };

/***
 * Token struct used for initial token generation from the file
 */
struct TokenStruct {
  unsigned int m_lineNumber;   // line of the token
  unsigned int m_startPos;     // start pos of the token
  unsigned int m_endPos;       // end pos of token
  unsigned long m_totalLength; // length of the token
  std::string m_tokenValue;    // actual value
};

/***
 * AST struct used by parser to parse and understand the token
 */
struct AstStruct {
  unsigned int lineNumber;   // line of the token
  unsigned int startPos;     // start pos of the token
  unsigned int endPos;       // end pos of token
  unsigned long totalLength; // length of the token
  std::string instruction;   // actual instruction
  unsigned char opcode;      // opcode for the instruction
  std::string operandOne;    // first operand if any
  unsigned char operandTwo;  // second operand if any
  std::string numberBase;
  bool hasErrors;
};
#endif