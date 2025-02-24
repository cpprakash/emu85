#ifndef __INCLUDES_TYPES_HPP
#define __INCLUDES_TYPES_HPP

#include <array>
#include <string>

typedef unsigned char u_BYTE;
typedef char BYTE;
typedef unsigned short u_WORD;
typedef short WORD;

// base for the operand
enum BASE { b, d, h, o };

// Token type
enum TokenType {
  TOKEN_INSTRUCTION,
  TOKEN_LABEL,
  TOKEN_ADDDRESS,
  TOKEN_DATA,
  TOKEN_REGISTER,
  TOKEN_NEWLINE,
  TOKEN_EOF,
  TOKEN_COMMENT,
  TOKEN_UNKNOWN,
  TOKEN_COMMA,
  TOKEN_COLON,
  TOKEN_NUMBER
};

/***
 * Token struct used for initial token generation from the file
 */
struct TokenStruct {
  unsigned int m_lineNumber;   // line of the token
  unsigned int m_startPos;     // start pos of the token
  unsigned int m_endPos;       // end pos of token
  unsigned long m_totalLength; // length of the token
  TokenType m_tokenType;       // type of toke: INST, LABEL etc..
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
  std::string operandTwo;    // second operand if any
  std::string numberBase;
  bool hasErrors;
};
#endif