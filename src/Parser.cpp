#include "../includes/Parser.hpp"

#include <iostream>
#include <vector>

void Parser::ParseProgram(const std::vector<TokenStruct> &tokens) {

  std::cout << "Parser::ParseProgram::total tokens are= " << tokens.size()
            << std::endl;

  // main loop iterate over the token vector
  for (unsigned long i = 0ul; i < tokens.size(); i++) {
    this->m_currentIndex = i;
    this->ParseSingleLine(tokens[i]);
  }
}

//************************PRIVATE FUNCTIONS START******************************

std::string Parser::GetNextToken() {
  return this->m_vectTokens[m_currentIndex + 1].m_tokenValue;
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
            << std::endl;
  // token parsing is complete or no more tokens are there
  if (token.m_tokenValue == "NEWLINE" || token.m_tokenValue == "EOF") {
    return;
  }
  // all AXX instructions
  else if (token.m_tokenValue == "ACI") {
    std::cout << "ACI " << std::endl;
    HandleAciInstruction(program, i);
  } else if (token.m_tokenValue == "ADC") {
    std::cout << "ADC " << std::endl;
    HandleAdcInstruction(program, i);
  } else if (token.m_tokenValue == "ADD") {
    std::cout << "ADD " << std::endl;
    HandleAddInstruction(program, i);
  } else if (token.m_tokenValue == "ADI") {
    std::cout << "ADI " << std::endl;
  } else if (token.m_tokenValue == "ANA") {
    std::cout << "ANA " << std::endl;
  } else if (token.m_tokenValue == "ANI") {
    std::cout << "ANI " << std::endl;
  } else {
    std::cout << "not new line hast to do something" << std::endl;
  }
}
// All AXX instructions
void Parser::HandleAciInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}
void Parser::HandleAdcInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}
void Parser::HandleAddInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}
void Parser::HandleAdiInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}
void Parser::HandleAnaInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}
void Parser::HandleAniInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}

// handle HLT instruction
void Parser::HandleHltInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}

// handle LDA instruction
void Parser::HandleLdaInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}

// handle all MVI instructions
void Parser::HandleMviInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}

// handle STA instructions
void Parser::HandleStaInstruction(const std::vector<TokenStruct> &program,
                                  unsigned int index) {}

//************************PRIVATE FUNCTIONS END******************************