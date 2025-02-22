#include "../includes/Parser.hpp"
#include "../includes/Helper.hpp"

#include <algorithm>
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
    this->m_currentIndex++; // increment counter variable here
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
  std::cout << "Parser::GetNextTokenCalled returnning "
            << this->m_vectTokens[m_currentIndex].m_tokenValue << std::endl;
  return this->m_vectTokens[m_currentIndex].m_tokenValue;
}

/***
 * returns N tokens based on howMany
 */
std::vector<std::string> Parser::GetNextNTokens(unsigned int howMany = 1) {
  std::vector<std::string> temp;
  std::cout << "How many current index start = " << this->m_currentIndex
            << std::endl;
  this->m_currentIndex++;
  for (unsigned int i = this->m_currentIndex; i < howMany; i++) {
    temp.emplace_back(this->m_vectTokens[i].m_tokenValue);
  }
  this->m_currentIndex += howMany - 2;
  std::cout << "How many current index end  = " << this->m_currentIndex
            << std::endl;
  return temp;
}

std::string Parser::PeekNextToken(unsigned long howMany) {
  std::cout << "Parser::PeekNextToken called" << std::endl;
  return this->m_vectTokens[m_currentIndex + howMany].m_tokenValue;
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
  std::string num = "0x1ff";
  unsigned char strtonum =
      std::stoi(num, nullptr, static_cast<std::size_t>(16));
  std::cout << "TEST for NUMBER = "
            << std::stoi(num, nullptr, static_cast<std::size_t>(16))
            << " strtonum" << strtonum << std::endl;
  std::cout << "HAndle mvi inst" << std::endl;
  std::string nextTokenRegister = "";
  std::string nextTokenComma = "";
  std::string nextTokenValue = "";
  std::string peekTokenBase = "";
  std::string strInstruction = "";
  unsigned char dataValue;
  if (token.m_tokenValue == "MVI") { // we already know but still make it sure
    std::vector<std::string> temp = this->GetNextNTokens(6);
    // if ()
    for (unsigned int i = 0; i < temp.size(); i++) {
      std::cout << temp[i] << std::endl;
    }
    nextTokenRegister = temp[0];
    std::cout << "Next token for MVI is = " << nextTokenRegister << std::endl;
    if (!Helper::CheckIfRegistersAreValid(nextTokenRegister)) {
      return false;
    } // check for register, if not a valid register return false

    // check for COMMA
    nextTokenComma = temp[1];
    if (nextTokenComma != "COMMA") {
      return false;
    }

    // check next token to be a value followed by either H, D, B or O
    nextTokenValue = temp[2];
    if (!(std::stoi(nextTokenValue) >= 0) ||
        !(std::stoi(nextTokenValue) < 255)) {
      return false;
    }

    std::cout << "Value is in range" << std::endl;
    peekTokenBase = temp[3];
    std::cout << "Peektoken is " << peekTokenBase << std::endl;
    if (!Helper::CheckIfBaseIsValid(peekTokenBase)) { // base is wrong
      return false;
    }

    std::cout << "base also is in range" << std::endl;
    if (peekTokenBase == "H" || peekTokenBase == "h") {
      dataValue = std::stoi(nextTokenValue, nullptr, 16);
    }
    // this->GetNextToken(); // call it to get the next correct token
    std::string nextTokenNewline = temp[4];
    if (nextTokenNewline != "NEWLINE") { // check if the next token is newline,
      return false;
    }

    std::cout << "MVI sucesful all parameters are corect" << std::endl;
    strInstruction = "INS_" + token.m_tokenValue + "_" + nextTokenRegister;
    AstStruct astStruckt;
    astStruckt.lineNumber = token.m_lineNumber;
    astStruckt.startPos = token.m_startPos;
    astStruckt.endPos = token.m_endPos;
    astStruckt.totalLength = token.m_totalLength;
    astStruckt.instruction = strInstruction;
    astStruckt.opcode = 0x76; // fill it later at the first pass of assembler
    // Helper::GetHexCodeForInstruction(strInstruction);
    astStruckt.operandOne = nextTokenRegister;
    astStruckt.operandTwo = dataValue;
    astStruckt.numberBase = peekTokenBase;
    astStruckt.hasErrors = false;
    this->m_astVectTokens.push_back(astStruckt
                  /*{token.m_lineNumber, token.m_startPos, token.m_endPos,
                   token.m_totalLength, token.m_tokenValue, nextTokenRegister,
                   dataValue, peekTokenBase, false}*/);
    return true;
  }
  return false; // instruction is not MVI return fail
}

// handle STA instructions
bool Parser::HandleStaInstruction(const TokenStruct &token) { return false; }

//************************PRIVATE FUNCTIONS END******************************