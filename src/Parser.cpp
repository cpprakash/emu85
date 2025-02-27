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
 * Handle and write erros in the vector
 * and display them at the end
 * save line number
 * possible error
 * current token
 * next token
 * expected resolution
 */
void Parser::HandleAndSaveError(const TokenStruct &token,
                                ERROR_TYPES error_type,
                                const std::string &reason) {
  std::string e_type = "";
  switch (error_type) {
  case ERROR_ILLEGAL_INSTRUCTION:
    e_type = "[ILLEGAL INSTRUCTION FOUND]";
    break;
  case ERROR_MISSING_COLON:
    e_type = "[MISSING COLON]";
    break;

  case ERROR_MISSING_HEX:
    e_type = "[MISSING HEX AT THE END]";
    break;

  case ERROR_ADDRESS_OUT_OF_RANGE:
    e_type = "[ADDRESS CANT BE MORE THAN 16BITS]";
    break;

  case ERROR_DATA_OUT_OF_RANGE:
    e_type = "[DATA CANT BE MORE THAN 8BITS]";
    break;

  case ERROR_NO_NEWLINE_FOUND:
    e_type = "[EXPECTING A NEWLINE HERE]";
    break;

  default:
    e_type = "[UNKNOWN ERROR OCCURED. PLEASE TRY AGAIN]";
    break;
  }
  std::cout << "[Parser]::[HandleAndSaveError]::[called with  = "
            << token.m_tokenValue << " at line number " << token.m_lineNumber
            << "]::[Reason]::[" << reason << "][ERROR]::[" << e_type << "]"
            << std::endl;
  // TODO save error in a struct
  return;
}
/***
 * returns token type of supplid by index
 */
TOKEN_TYPES Parser::ReturnTokenType(unsigned long index) {
  return this->m_vectTokens[index].m_tokenType;
}

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
  std::cout << "Parser::GetNextNTokens called with  = " << howMany
            << " and currentIndex =" << this->m_currentIndex << std::endl;
  this->m_currentIndex++;
  for (unsigned int i = this->m_currentIndex;
       i < this->m_currentIndex + howMany - 1; i++) {
    temp.emplace_back(this->m_vectTokens[i].m_tokenValue);
    std::cout << "Putting in vecotr " << this->m_vectTokens[i].m_tokenValue
              << std::endl;
  }
  this->m_currentIndex += howMany - 2;
  return temp;
}

std::string Parser::PeekNextToken(unsigned long howMany) {
  std::cout << "[Parser]::[PeekNextToken] called" << std::endl;
  return this->m_vectTokens[m_currentIndex + howMany].m_tokenValue;
}

void Parser::HandleAllInstructions(const TokenStruct &token) {
  // all AXX instructions
  if (token.m_tokenValue == "ACI") {
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
  // here deal with LDA instructions
  else if (token.m_tokenValue == "LDA") {
    if (this->HandleLdaInstruction(token) == false) {
      std::cout << "Parsing LDA Instruction failed." << std::endl;
    } else {
      std::cout << "Successfully parsed LDA at line " << token.m_lineNumber
                << std::endl;
    }
  }
  // here deal with all MOV instructions
  else if (token.m_tokenValue == "MOV") {
    if (this->HandleMovInstruction(token) == false) {
      std::cout << "Parsing MOV Instruction failed." << std::endl;
    } else {
      std::cout << "Successfully parsed MOV at line " << token.m_lineNumber
                << std::endl;
    }
  }
  // here deal with all MVI instructions
  else if (token.m_tokenValue == "MVI") {
    if (this->HandleMviInstruction(token) == false) {
      std::cout << "Parsing MVI Instruction failed." << std::endl;
    } else {
      std::cout << "Successfully parsed MVI at line " << token.m_lineNumber
                << std::endl;
    }
  }
  // Parse SHLD Instruction
  else if (token.m_tokenValue == "SHLD") {
    if (!this->HandleShldInstruction(token)) {
      std::cout << "Parsing SHLD Instruction failed." << std::endl;
    } else {
      std::cout << "Successfully parsed SHLD instruction at line "
                << token.m_lineNumber << std::endl;
    }
  }
  // Parse STA instruction
  else if (token.m_tokenValue == "STA") {
    if (this->HandleStaInstruction(token) == false) {
      std::cout << "Parsing STA Instruction failed." << std::endl;
    } else {
      std::cout << "Successfully parsed STA instruction at line "
                << token.m_lineNumber << std::endl;
    }
  } else { // hopefully it never comes here
    this->HandleAndSaveError(token, ERROR_ILLEGAL_INSTRUCTION,
                             "Unknow instruction found");
    /*std::cout << "Unknow Instruction found at line " << token.m_lineNumber
              << " with value " << token.m_tokenValue << std::endl;*/
  }
}

/***
 * Handle the label
 */
void Parser::HandleTokenLabel(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleTokenLabel]::[Checking for a label found at "
            << token.m_lineNumber << " with value = " << token.m_tokenValue
            << "]" << std::endl;
  if (token.m_tokenValue.length() > 6) { // check if label is less than 6 char
    std::cout << "[Parser]::[HandleTokenLabel]::[A label  cannot have more "
                 "than 6 characters "
              << token.m_tokenValue << "]" << std::endl;
    return;
  }
  // case check label if has only one char, then its not any illegal char
  if (token.m_tokenValue.length() == 1 &&
      (Helper::CheckIfRegistersAreValid(token.m_tokenValue) ||
       token.m_tokenValue.substr(1, 1) == "?" ||
       token.m_tokenValue.substr(1, 1) == "@" ||
       isdigit(token.m_tokenValue[0]))) {
    std::cout << "[Parser]::[HandleTokenLabel]::[A label cannot have one "
                 "character with either @,?, a register name or with a digit "
              << token.m_tokenValue << "]" << std::endl;
    return;
  }
  if (this->PeekNextToken() == "COLON") {
    std::cout << "[Parser]::[HandleTokenLabel]::[A label found at "
              << token.m_lineNumber << " with value = " << token.m_tokenValue
              << "]" << std::endl;
    this->GetNextToken(); // advance tokens by one
    return;
  }
  std::cout << "[Parser]::[HandleTokenLabel]::[Checking for a label failed "
            << token.m_lineNumber << " with value = " << token.m_tokenValue
            << " is not a label]" << std::endl;
}

/***
 * parse a comment
 */
void Parser::HandleTokenComment(const TokenStruct &token) {
  std::string comment = ";";
  std::string n_token;
  while (n_token != "NEWLINE") {
    n_token = this->GetNextToken();
    if (n_token == "NEWLINE")
      return;
    comment += n_token + " ";
    std::cout << "Comment =" << comment << std::endl;
  }

  this->m_astVectTokens.push_back({token.m_lineNumber, token.m_startPos,
                                   token.m_endPos, comment.length(), comment,
                                   0x76, "", "", "", false});
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
  std::cout << "[Parser]::[ParseSingleLine]::[Parsing token= "
            << token.m_tokenValue << " (" << this->m_currentIndex << "/"
            << this->m_vectTokens.size() << ")]" << std::endl;

  switch (token.m_tokenType) {
  case TOKEN_INSTRUCTION:
    this->HandleAllInstructions(token);
    break;
  case TOKEN_LABEL:
    this->HandleTokenLabel(token);
    break;
  case TOKEN_ADDDRESS:
    // Handle16BitAddress();
    break;
  case TOKEN_DATA:
    // Handle8BitData();
    break;
  case TOKEN_REGISTER:
    // HandleRegister();
    break;
  case TOKEN_NEWLINE:
    // HandleNewline();
    std::cout << "[Parser]::[ParseSingleLine]::[A newline found at line number "
              << token.m_lineNumber << "]" << std::endl;
    break;
  case TOKEN_EOF: // token parsing is complete or no more tokens are there
    // HandleFileEnd();
    std::cout << "[Parser]::[ParseSingleLine]::[An EOF found at "
              << token.m_lineNumber << "]" << std::endl;
    break;
  case TOKEN_COMMENT:
    this->HandleTokenComment(token);
    std::cout << "[Parser]::[ParseSingleLine]::[A comment found at "
              << token.m_lineNumber << "]" << std::endl;
    break;
  case TOKEN_COMMA:
    // HandleComma();
    std::cout << "[Parser]::[ParseSingleLine]::[A comma found at "
              << token.m_lineNumber << "]" << std::endl;
    break;
  case TOKEN_COLON:
    // HandleColon();
    std::cout << "[Parser]::[ParseSingleLine]::[colon found at line number "
              << token.m_lineNumber << "]" << std::endl;
    break;
  case TOKEN_NUMBER:
    // HandleNumber();
    std::cout << "[Parser]::[ParseSingleLine]::[A Number found at line number "
              << token.m_lineNumber << " with value " << token.m_tokenValue
              << "]" << std::endl;
    break;
  case TOKEN_UNKNOWN:
  default:
    std::cout
        << "[Parser]::[ParseSingleLine]::[Wrong Instruction found. Please "
           "check it again line] "
        << token.m_lineNumber << std::endl;
    break;
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

/***
 * handle LDA instruction
 * LDA = Opcode
 * 16 bit address = operand
 * addresssing = direct
 * 3 byte instruction
 */
bool Parser::HandleLdaInstruction(const TokenStruct &token) {
  TOKEN_TYPES type = this->ReturnTokenType(this->m_currentIndex + 1);
  std::cout << "[Parser]::[HandleLdaInstruction]:[type of the current token is "
            << type << "]" << std::endl;

  std::vector<std::string> temp = this->GetNextNTokens(3); // will get only 2
  std::cout << temp[0] << std::endl;
  if (type == TOKEN_NUMBER && !Helper::CheckIfAddressInRange(temp[0])) {
    std::cout << "[Parser]::[HandleLdaInstruction]:[address is invalid "
              << temp[0] << "]" << std::endl;
    return false;
  } else if (type == TOKEN_LABEL) { // TODO handle label
  }
  if (temp[1] != "NEWLINE") {
    return false;
  }
  const auto code = types_mapInstruction.find("INS_LDA_Address");
  if (code != types_mapInstruction.end()) { // the instruction is in map
    this->m_finalParserProgram->emplace_back(code->second);
    std::cout << "Final code = " << code->second << std::endl;
    // return code->second;
  } else { // instruction was not found in the map, wrong instruction
    std::cout << "Assembler::GetHexCodeFromInstruction::Error in retreiving key"
              << std::endl;
    // return 0x76; // return halt as of now
  }
  // this->m_finalParserProgram->emplace_back(code->second);

  this->m_astVectTokens.push_back(
      {token.m_lineNumber, token.m_startPos, token.m_endPos,
       token.m_totalLength, "INS_LDA_Address", 0x76, temp[0], "", "", false});

  return true;
}

// handle all MVI instructions
/***
 * there are 3 types of MOV Instructions
 * mov reg to reg copies data from one reg to another
 * mov to memory MOV M, r second operand must be a register
 * mov from memory MOV r, M second operand must be M
 * where M is the memory address pointed by HL register
 * MOV M, M is not allowed
 */
bool Parser::HandleMovInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleMovInstruction]::[start]" << std::endl;
  std::vector<std::string> temp = this->GetNextNTokens(5); // will get only 4
  if (!Helper::CheckIfRegistersAreValid(temp[0])) {
    std::cout
        << "[Parser]::[HandleMovInstruction]::[first operand is not valid]"
        << std::endl;
    return false;
  }
  if (temp[1] != "COMMA") {
    std::cout << "[Parser]::[HandleMovInstruction]::[missing comma]"
              << std::endl;
    return false;
  }
  if (!Helper::CheckIfRegistersAreValid(temp[2])) {
    std::cout
        << "[Parser]::[HandleMovInstruction]::[second operand is not valid]"
        << std::endl;
    return false;
  }
  if (temp[3] != "NEWLINE") {
    std::cout << "[Parser]::[HandleMovInstruction]::[missing NEWLINE]"
              << std::endl;
    return false;
  }
  if (temp[0] == "M" && temp[2] == "M") {
    std::cout << "[Parser]::[HandleMovInstruction]::[MOV M, M is not allowed]"
              << std::endl;
    return false;
  }

  this->m_astVectTokens.push_back({token.m_lineNumber, token.m_startPos,
                                   token.m_endPos, token.m_totalLength,
                                   "INS_MOV_" + temp[0] + "_" + temp[2], 0x76,
                                   temp[0], temp[2], "", false});
  std::cout << "[Parser]::[HandleMovInstruction]::[end]" << std::endl;
  return true;
}

// handle all MVI instructions
/***
 * there are 8 total MVI Instructions and either of one can have
 * one of the eight registers with an 8 bit of data
 * e.g MVI <A|B|C|D|E|H|L|M>, Data <8 bit> <ENDL>+
 */
bool Parser::HandleMviInstruction(const TokenStruct &token) {

  std::cout << "[Parser]::[HandleMviInstruction]::[start]" << std::endl;
  std::string nextTokenRegister = "";
  std::string nextTokenComma = "";
  std::string nextTokenValue = "";
  std::string peekTokenBase = "";
  std::string strInstruction = "";
  // unsigned char dataValue;
  if (token.m_tokenValue != "MVI") { // we already know but still make it sure
    std::cout << "[Parser]::[HandleMviInstruction]::[MVI]" << std::endl;
    return false;
  }

  std::vector<std::string> temp = this->GetNextNTokens(6); // will get only 5

  for (unsigned long i = 0; i < temp.size(); i++)
    std::cout << temp[i] << std::endl;

  nextTokenRegister = temp[0];

  if (!Helper::CheckIfRegistersAreValid(nextTokenRegister)) {
    std::cout << "[Parser]::[HandleMviInstruction]::[nextTokenRegister]"
              << std::endl;
    return false;
  } // check for register, if not a valid register return false

  // check for COMMA
  nextTokenComma = temp[1];
  if (nextTokenComma != "COMMA") {
    std::cout << "[Parser]::[HandleMviInstruction]::[COMMA]" << std::endl;
    return false;
  }

  // check the range of the value
  nextTokenValue = temp[2];
  if (!(std::stoi(nextTokenValue) >= 0) || !(std::stoi(nextTokenValue) < 255)) {
    std::cout << "[Parser]::[HandleMviInstruction]::[nextTokenValue]"
              << std::endl;
    return false;
  }

  // check next token to be a value followed by either H, D, B or O
  peekTokenBase = temp[3];
  if (!Helper::CheckIfBaseIsValid(peekTokenBase)) { // base is wrong
    std::cout << "[Parser]::[HandleMviInstruction]::[peekTokenBase]"
              << std::endl;
    return false;
  }

  // value comversion
  /*if (peekTokenBase == "H" || peekTokenBase == "h") {
    dataValue = std::stoi(nextTokenValue, nullptr, 16);
  }*/

  std::string nextTokenNewline = temp[4];
  if (nextTokenNewline != "NEWLINE") { // check if the next token is newline,
    std::cout << "[Parser]::[HandleMviInstruction]::[NEWLINE]" << std::endl;
    return false;
  }

  std::cout << "MVI sucesful all parameters are corect" << std::endl;
  strInstruction = "INS_" + token.m_tokenValue + "_" + nextTokenRegister;

  this->m_astVectTokens.push_back({token.m_lineNumber, token.m_startPos,
                                   token.m_endPos, token.m_totalLength,
                                   strInstruction, 0x76, nextTokenRegister,
                                   nextTokenValue, peekTokenBase, false});
  std::cout << "[Parser]::[HandleMviInstruction]::[end]" << std::endl;
  return true;
}

// handle SHLD instructions
bool Parser::HandleShldInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleShldInstruction]::[start]" << std::endl;

  // get next 2 tokens
  std::vector<std::string> temp = this->GetNextNTokens(3);

  // next token should be a 16bit address
  if (!Helper::CheckIfAddressInRange(temp[0])) {
    return false;
  }

  if (temp[1] != "NEWLINE") { // check if the next token is newline,
    return false;
  }

  this->m_astVectTokens.push_back({token.m_lineNumber, token.m_startPos,
                                   token.m_endPos, token.m_totalLength,
                                   "INS_" + token.m_tokenValue, 0x76, "",
                                   temp[0], temp[1], false});
  std::cout << "[Parser]::[HandleShldInstruction]::[end]" << std::endl;
  return true;
}

// handle STA instructions
bool Parser::HandleStaInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleStaInstruction]::[start]" << std::endl;
  if (token.m_tokenValue != "STA") {
    return false; // just make sure once again
  }
  // get next 3 tokens
  std::vector<std::string> temp = this->GetNextNTokens(4);
  std::cout << "STA INS size of temp =" << temp.size() << std::endl;
  for (unsigned long i = 0; i < temp.size(); i++)
    std::cout << temp[i] << std::endl;
  // next token should be a 16bit address
  if (!Helper::CheckIfAddressInRange(temp[0])) {
    return false;
  }

  if (!Helper::CheckIfBaseIsValid(temp[1])) { // base is wrong
    return false;
  }

  if (temp[2] != "NEWLINE") { // check if the next token is newline,
    return false;
  }
  /*AstStruct astStruckt;
  astStruckt.lineNumber = token.m_lineNumber;
  astStruckt.startPos = token.m_startPos;
  astStruckt.endPos = token.m_endPos;
  astStruckt.totalLength = token.m_totalLength;
  astStruckt.instruction = "INS_" + token.m_tokenValue;
  astStruckt.opcode = 0x76; // fill it later at the first pass of assembler
  // Helper::GetHexCodeForInstruction(strInstruction);
  astStruckt.operandOne = "";
  astStruckt.operandTwo = temp[0];
  astStruckt.numberBase = temp[1];
  astStruckt.hasErrors = false;
  this->m_astVectTokens.push_back(astStruckt);*/
  this->m_astVectTokens.push_back({token.m_lineNumber, token.m_startPos,
                                   token.m_endPos, token.m_totalLength,
                                   "INS_" + token.m_tokenValue, 0x76, "",
                                   temp[0], temp[1], false});
  std::cout << "[Parser]::[HandleStaInstruction]::[end]" << std::endl;
  return true;
}

//************************PRIVATE FUNCTIONS END******************************