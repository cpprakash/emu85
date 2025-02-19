#ifndef __INCLUDES_TYPES_HPP
#define __INCLUDES_TYPES_HPP

#include <string>

/***
 * Token struct
 */
struct TokenStruct {
  unsigned int m_lineNumber;   // line of the token
  unsigned int m_startPos;     // start pos of the token
  unsigned int m_endPos;       // end pos of token
  unsigned long m_totalLength; // length of the token
  std::string m_tokenValue;    // actual value
};
#endif