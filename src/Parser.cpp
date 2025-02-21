#include "../includes/Parser.hpp"

#include <iostream>
#include <vector>

void Parser::ParseProgram(const std::vector<TokenStruct> &tokens) {

  std::cout << "Parser::ParseProgram::total tokens are= " << tokens.size()
            << std::endl;
  this->m_vectTokens = tokens; // do everything with the local variable

  // main loop iterate over the token vector
  for (this->m_currentIndex = 0ul;
       this->m_currentIndex < this->m_vectTokens.size();) {
    this->ParseSingleLine(this->m_vectTokens[this->m_currentIndex]);
    this->m_currentIndex++;
  }
}

//************************PRIVATE FUNCTIONS START******************************

/***
 * returns the next token in the vector
 * and consumes it
 */
std::string Parser::GetNextToken() {
  std::cout << "Parser::GetNextTokenCalled" << std::endl;
  this->m_currentIndex++;
  std::cout << "Parser::GetNextTokenCalled currentIndex = " << m_currentIndex
            << std::endl;
  std::cout << "Parser::GetNextTokenCalled size of mvet = "
            << this->m_vectTokens.size() << std::endl;
  std::cout << "Parser::GetNextTokenCalled m[vectToken] at curInxdex  = "
            << this->m_vectTokens[m_currentIndex].m_tokenValue << std::endl;
  return this->m_vectTokens[m_currentIndex].m_tokenValue;
}

/***
 * struct TokenStruct {
  unsigned int m_lineNumber;   // line of the token
  unsigned int m_startPos;     // start pos of the token
  unsigned int m_endPos;       // end pos of token
  unsigned long m_totalLength; // length of the token
  std::string m_tokenValue;    // actual value
};
 */
void Parser::ParseSingleLine(const TokenStruct &token) {
  std::cout << "Parser::ParserSingleLine::parsing token= " << token.m_tokenValue
            << " the index is " << this->m_currentIndex << std::endl;
  // token parsing is complete or no more tokens are there
  if (token.m_tokenValue == "NEWLINE" || token.m_tokenValue == "EOF") {
    return;
  }
  // all AXX instructions
  else if (token.m_tokenValue == "ACI") {
    std::cout << "ACI " << std::endl;
    HandleAciInstruction(token);
  } else if (token.m_tokenValue == "ADC") {
    std::cout << "ADC " << std::endl;
    HandleAdcInstruction(token);
  } else if (token.m_tokenValue == "ADD") {
    std::cout << "ADD " << std::endl;
    HandleAddInstruction(token);
  } else if (token.m_tokenValue == "ADI") {
    std::cout << "ADI " << std::endl;
  } else if (token.m_tokenValue == "ANA") {
    std::cout << "ANA " << std::endl;
  } else if (token.m_tokenValue == "ANI") {
    std::cout << "ANI " << std::endl;
  }
  // here deal with all MVI instructions
  else if (token.m_tokenValue == "MVI") {
    std::cout << "MVI with token = " << token.m_endPos << token.m_lineNumber
              << token.m_startPos << token.m_totalLength << std::endl;
    if (this->HandleMviInstruction(token) == false) {
      std::cout << "Parsing MVI Instruction failed." << std::endl;
    } else {
      std::cout << "Successfully parser MVI " << std::endl;
    }
  } else {
    std::cout << "not new line hast to do something" << std::endl;
  }
}
// All AXX instructions
bool Parser::HandleAciInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAdcInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAddInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAdiInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAnaInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAniInstruction(const TokenStruct &token) { return false; }

// handle HLT instruction
bool Parser::HandleHltInstruction(const TokenStruct &token) { return false; }

// handle LDA instruction
bool Parser::HandleLdaInstruction(const TokenStruct &token) { return false; }

// handle all MVI instructions
/***
 * there are 8 total MVI Instructions and either of one can have
 * one of the eight registers with an 8 bit of data
 * e.g MVI <A|B|C|D|E|H|L|M>, Data <8 bit> <ENDL>+
 */
bool Parser::HandleMviInstruction(const TokenStruct &token) {
  std::cout << "HAndle mvi inst" << std::endl;
  if (token.m_tokenValue == "MVI") {
    std::string nextToken = this->GetNextToken();
    std::cout << "Next token for MVI is = " << nextToken << std::endl;
    return true;
  }
  return false;
}

// handle STA instructions
bool Parser::HandleStaInstruction(const TokenStruct &token) { return false; }

//************************PRIVATE FUNCTIONS END******************************