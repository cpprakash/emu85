#include "../includes/Parser.hpp"
#include "../includes/Helper.hpp"

#include <iostream>
#include <vector>

u_BYTE *Parser::ParseProgram(const std::vector<TokenStruct> &tokens) {
  std::cout << "[Parser]::[ParseProgram]::[start Total tokens are= "
            << tokens.size() << "]" << std::endl;

  this->m_vectTokens = tokens; // do everything with the local variable

  // main loop iterate over the token vector
  for (this->m_currentIndex = 0ul;
       this->m_currentIndex < this->m_vectTokens.size();) {
    this->ParseSingleLine(this->m_vectTokens[this->m_currentIndex]);
    this->m_currentIndex++; // increment counter variable here
  }
  for (auto i = this->pCounter; i < BIN_FILE_SIZE; i++) {
    this->m_finalParserProgram[i] = 0x00;
  }
  std::cout << "[Parser]::[ParseProgram]::[end final program size="
            << this->pCounter << "]" << std::endl;
  return this->m_finalParserProgram;
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
  this->m_currentIndex++;
  return this->m_vectTokens[m_currentIndex].m_tokenValue;
}

/***
 * returns N tokens based on howMany
 */
std::vector<std::string> Parser::GetNextNTokens(unsigned int howMany = 1) {
  std::vector<std::string> temp;
  this->m_currentIndex++;
  for (unsigned int i = this->m_currentIndex;
       i < this->m_currentIndex + howMany - 1; i++) {
    temp.emplace_back(this->m_vectTokens[i].m_tokenValue);
  }
  this->m_currentIndex += howMany - 2;
  return temp;
}

std::string Parser::PeekNextToken(unsigned long howMany) {
  return this->m_vectTokens[m_currentIndex + howMany].m_tokenValue;
}

void Parser::HandleAllInstructions(const TokenStruct &token) {

  // Handle all instructions that have either one 8bit registger A, B, C, D ,E,
  // H, L or a memory reference M through HL pair
  // and has the format instruction RegM8, this function must parse 64
  // instructions, 8 for each of these
  if (token.m_tokenValue == "ADC" || token.m_tokenValue == "ADD" ||
      token.m_tokenValue == "ANA" || token.m_tokenValue == "CMP" ||
      token.m_tokenValue == "ORA" || token.m_tokenValue == "SBB" ||
      token.m_tokenValue == "SUB" || token.m_tokenValue == "XRA") {
    // std::cout << "ACI " << std::endl;
    this->Handle8BitRegMemInstructions(token);
  } else if (token.m_tokenValue == "ACI" || token.m_tokenValue == "ADI" ||
             token.m_tokenValue == "ANI" || token.m_tokenValue == "CPI" ||
             token.m_tokenValue == "MVI" || token.m_tokenValue == "ORI" ||
             token.m_tokenValue == "SBI" || token.m_tokenValue == "SUI" ||
             token.m_tokenValue == "XRI") {
    // std::cout << "ACI " << std::endl;
    this->Handle8BitDataInstructions(token);
  }

  // handle HLT instruction
  else if (token.m_tokenValue == "HLT") {
    if (this->HandleHltInstruction(token) == false) {
      std::cout << "[Parser]::[HandleAllInstructions]::[Parsing HLT "
                   "Instruction failed.]"
                << std::endl;
    } else {
      std::cout << "[Parser]::[HandleAllInstructions]::[Successfully parsed "
                   "HLT at line "
                << token.m_lineNumber << "]" << std::endl;
    }
  }

  else if (token.m_tokenValue == "LDA" || token.m_tokenValue == "STA" ||
           token.m_tokenValue == "JC" || token.m_tokenValue == "JZ" ||
           token.m_tokenValue == "JP" || token.m_tokenValue == "JPE" ||
           token.m_tokenValue == "JNC" || token.m_tokenValue == "JNZ" ||
           token.m_tokenValue == "JM" || token.m_tokenValue == "JPO" ||
           token.m_tokenValue == "RC" || token.m_tokenValue == "RZ" ||
           token.m_tokenValue == "RP" || token.m_tokenValue == "RPE" ||
           token.m_tokenValue == "RNC" || token.m_tokenValue == "RNZ" ||
           token.m_tokenValue == "RM" || token.m_tokenValue == "RPO" ||
           token.m_tokenValue == "CC" || token.m_tokenValue == "CZ" ||
           token.m_tokenValue == "CP" || token.m_tokenValue == "CPE" ||
           token.m_tokenValue == "CNC" || token.m_tokenValue == "CNZ" ||
           token.m_tokenValue == "CM" || token.m_tokenValue == "CPO" ||
           token.m_tokenValue == "LHLD" || token.m_tokenValue == "STHD") {
    this->Handle16BitAddressInstructions(token);
  }

  // here deal with all MOV instructions
  else if (token.m_tokenValue == "MOV") {
    if (this->HandleMovInstruction(token) == false) {
      std::cout << "[Parser]::[HandleAllInstructions]::[Parsing MOV "
                   "Instruction failed.]"
                << std::endl;
    } else {
      std::cout << "[Parser]::[HandleAllInstructions]::[Successfully parsed "
                   "MOV at line "
                << token.m_lineNumber << "]" << std::endl;
    }
  }
  // here deal with all MVI instructions
  else if (token.m_tokenValue == "MVI") {
    if (this->HandleMviInstruction(token) == false) {
      std::cout << "[Parser]::[HandleAllInstructions]::[Parsing MVI "
                   "Instruction failed.]"
                << std::endl;
    } else {
      std::cout << "[Parser]::[HandleAllInstructions]::[Successfully parsed "
                   "MVI at line "
                << token.m_lineNumber << "]" << std::endl;
    }
  }
  // Parse SHLD Instruction
  else if (token.m_tokenValue == "SHLD") {
    if (!this->HandleShldInstruction(token)) {
      std::cout << "[Parser]::[HandleAllInstructions]::[Parsing SHLD "
                   "Instruction failed.]"
                << std::endl;
    } else {
      std::cout << "[Parser]::[HandleAllInstructions]::[Successfully parsed "
                   "SHLD instruction at line "
                << token.m_lineNumber << "]" << std::endl;
    }
  }
  // Parse STA instruction
  else if (token.m_tokenValue == "STA") {
    if (this->HandleStaInstruction(token) == false) {
      std::cout << "[Parser]::[HandleAllInstructions]::[Parsing STA "
                   "Instruction failed.]"
                << std::endl;
    } else {
      std::cout << "[Parser]::[HandleAllInstructions]::[Successfully parsed "
                   "STA instruction at line "
                << token.m_lineNumber << "]" << std::endl;
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

// Handle ADC_<A|B|C|D|E|H|L|M> instructions
bool Parser::HandleAdcInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleAdcInstruction]:[start]" << std::endl;
  std::vector<std::string> temp = this->GetNextNTokens(3); // will get only 2
  if (!Helper::CheckIfRegistersAreValid(temp[0])) {
    std::cout
        << "[Parser]::[HandleAdcInstruction]::[first operand is not valid]"
        << std::endl;
    return false;
  }
  if (temp[1] != "NEWLINE") {
    return false;
  }
  std::cout << "[Parser]::[HandleAdcInstruction]:[end]" << std::endl;
  return this->ReturnInstructionHex("ADC_" + temp[0]);
}

bool Parser::HandleAddInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleAddInstruction]:[start]" << std::endl;
  std::vector<std::string> temp = this->GetNextNTokens(3); // will get only 2
  if (!Helper::CheckIfRegistersAreValid(temp[0])) {
    std::cout
        << "[Parser]::[HandleAddInstruction]::[first operand is not valid]"
        << std::endl;
    return false;
  }
  if (temp[1] != "NEWLINE") {
    return false;
  }
  std::cout << "[Parser]::[HandleAddInstruction]:[end]" << std::endl;
  return this->ReturnInstructionHex("ADD_" + temp[0]);
}
bool Parser::HandleAdiInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAnaInstruction(const TokenStruct &token) { return false; }
bool Parser::HandleAniInstruction(const TokenStruct &token) { return false; }

// handle HLT instruction
bool Parser::HandleHltInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleHltInstruction]:[start]" << std::endl;
  std::vector<std::string> temp = this->GetNextNTokens(2); // will get only 1
  if (temp[0] != "NEWLINE") {
    std::cout << "[Parser]::[HandleHltInstruction]::[expecting newline]"
              << std::endl;
    return false;
  }
  std::cout << "[Parser]::[HandleHltInstruction]:[end]" << std::endl;
  return this->ReturnInstructionHex(token.m_tokenValue);
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
    if (temp[3][0] == ';' && this->PeekNextToken() == "NEWLINE") {
      // do nothing
    } else {
      std::cout << "[Parser]::[HandleMovInstruction]::[missing NEWLINE]"
                << std::endl;
      return false;
    }
  }
  if (temp[0] == "M" && temp[2] == "M") {
    std::cout << "[Parser]::[HandleMovInstruction]::[MOV M, M is not allowed]"
              << std::endl;
    return false;
  }
  std::cout << "[Parser]::[HandleMovInstruction]::[end]" << std::endl;
  return this->ReturnInstructionHex("MOV_" + temp[0] + "_" + temp[2]);
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
  std::vector<std::string> temp = this->GetNextNTokens(5); // will get only 4

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

  // check the range of the value TODO check properly
  nextTokenValue = temp[2];
  if (!(std::stoi(nextTokenValue) >= 0) || !(std::stoi(nextTokenValue) < 255)) {
    std::cout << "[Parser]::[HandleMviInstruction]::[nextTokenValue]"
              << std::endl;
    return false;
  }

  std::string nextTokenNewline = temp[3];
  if (nextTokenNewline != "NEWLINE") { // check if the next token is newline,
    std::cout << "[Parser]::[HandleMviInstruction]::[NEWLINE]" << std::endl;
    return false;
  }

  std::cout << "[Parser]::[HandleMviInstruction]::[end]" << std::endl;
  strInstruction = token.m_tokenValue + "_" + nextTokenRegister;

  return this->ReturnInstructionHex("MVI_" + nextTokenRegister + "_Data");
}

// handle SHLD instructions
bool Parser::HandleShldInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleShldInstruction]::[start]" << std::endl;

  SixteenBitAddress address{"", 0x00, 0x00, false};

  TOKEN_TYPES type = this->ReturnTokenType(this->m_currentIndex + 1);

  std::vector<std::string> temp = this->GetNextNTokens(3); // will get only 2
  // std::cout << temp[0] << std::endl;
  address = Helper::CheckAndReturn16BitAddress(temp[0]);
  if (type == TOKEN_NUMBER && !address.result) {
    std::cout << "[Parser]::[HandleShldInstruction]:[address is invalid "
              << temp[0] << "]" << std::endl;

  } else if (type == TOKEN_LABEL) { // TODO handle label
  }
  if (temp[1] != "NEWLINE") {
    return false;
  }

  bool resultInst = this->ReturnInstructionHex(token.m_tokenValue + "_Address");
  this->m_finalParserProgram[pCounter] = (address.addressLow);
  this->pCounter++;
  this->m_finalParserProgram[pCounter] = (address.addressHigh);
  this->pCounter++;
  std::cout << "[Parser]::[HandleShldInstruction]:[ended for instruction "
            << token.m_tokenValue << "]" << std::endl;
  return resultInst;
}

// handle STA instructions
bool Parser::HandleStaInstruction(const TokenStruct &token) {
  std::cout << "[Parser]::[HandleStaInstruction]::[start]" << std::endl;
  if (token.m_tokenValue != "STA") {
    return false; // just make sure once again
  }
  // get next 3 tokens
  std::vector<std::string> temp = this->GetNextNTokens(4);
  // std::cout << "STA INS size of temp =" << temp.size() << std::endl;
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

  this->m_astVectTokens.push_back({token.m_lineNumber, token.m_startPos,
                                   token.m_endPos, token.m_totalLength,
                                   token.m_tokenValue, 0x76, "", temp[0],
                                   temp[1], false});
  std::cout << "[Parser]::[HandleStaInstruction]::[end]" << std::endl;
  return true;
}

bool Parser::ReturnInstructionHex(const std::string &inst) {
  std::cout << "[Parser]::[ReturnInstructionHex]::[start for instruction "
            << inst << "]" << std::endl;
  bool result = false;
  const auto code = types_mapInstruction.find(inst);
  if (code != types_mapInstruction.end()) { // the instruction is in map
    this->m_finalParserProgram[pCounter] = (code->second);
    this->pCounter++;
    result = true;
  } else { // instruction was not found in the map, wrong instruction
    std::cout << "[Parser]::[ReturnInstructionHex]::[Error in retreiving key]"
              << std::endl;
    result = false;
  }
  std::cout << "[Parser]::[ReturnInstructionHex]::[end for instruction " << inst
            << "]" << std::endl;
  return result;
}

/***
 * Handle all instructions that operate on 8 bit registers A,B,C,D,E,H or L or
 * M(memory referance) via 16 bit address in H and L register
 * this function covers these instructions
 * ADC, ADD, ANA, CMP, ORA, SBB, SUB, XRA,
 * this function takes a token struct and parse the instructions
 * and tries to determine the correct hex for instructions
 * and the related operands if any
 */
bool Parser::Handle8BitRegMemInstructions(const TokenStruct &token) {
  std::cout
      << "[Parser]::[Handle8BitRegMemInstructions]:[started for instruction "
      << token.m_tokenValue << "]" << std::endl;
  std::vector<std::string> temp = this->GetNextNTokens(3); // will get only 2
  if (!Helper::CheckIfRegistersAreValid(temp[0])) {
    std::cout << "[Parser]::[Handle8BitRegMemInstructions]::[first operand is "
                 "not valid]"
              << std::endl;
    return false;
  }
  if (temp[1] != "NEWLINE") {
    return false;
  }
  std::cout
      << "[Parser]::[Handle8BitRegMemInstructions]:[ended for instruction "
      << token.m_tokenValue << "]" << std::endl;
  return this->ReturnInstructionHex(token.m_tokenValue + "_" + temp[0]);
}

/***
 * Handle all instructions that operate on 8 bit immediate operand
 * this function covers these instructions
 * ADI, ACI, SUI, SBI, ANI, XRI, ORI, CPI, MVI
 */
bool Parser::Handle8BitDataInstructions(const TokenStruct &token) {
  std::cout
      << "[Parser]::[Handle8BitDataInstructions]:[started for instruction "
      << token.m_tokenValue << "]" << std::endl;
  bool result = false;
  std::vector<std::string> temp = this->GetNextNTokens(5); // will get only 4
  // check for register, if not a valid register return false
  if (!Helper::CheckIfRegistersAreValid(temp[0])) {
    std::cout << "[Parser]::[Handle8BitDataInstructions]::[first operand is "
                 "not valid]"
              << std::endl;
    result = false;
  }
  // expects a comma between register and 8bit data
  if (temp[1] != "COMMA") {
    std::cout << "[Parser]::[Handle8BitDataInstructions]::[expecting a comma]"
              << std::endl;
  }
  // parse an 8 bit data here
  EightBitData data = Helper::CheckIf8BitDataIsValid(temp[2]);
  if (data.result == false) {
    std::cout << "[Parser]::[Handle8BitDataInstructions]::[" << data.message
              << "]" << std::endl;
  }
  // expects a new line at the end
  if (temp[3] != "NEWLINE") {
    if (temp[3][0] == ';' && this->PeekNextToken() == "NEWLINE") {
      // do nothing
    } else {
      result = false;
      std::cout
          << "[Parser]::[Handle8BitDataInstructions]::[expecting a new line]"
          << std::endl;
    }
  }

  if (token.m_tokenValue == "MVI") {
    result = this->ReturnInstructionHex(token.m_tokenValue + "_" + temp[0] +
                                        "_Data");
  } else {
    result = this->ReturnInstructionHex(token.m_tokenValue + "_Data");
  }
  if (result) // if we were able to find instruction only push operand
  {
    this->m_finalParserProgram[pCounter] = (data.data);
    this->pCounter++;
  }
  std::cout << "[Parser]::[Handle8BitDataInstructions]:[ended for instruction "
            << token.m_tokenValue << "]" << std::endl;
  return result;
}

/***
 * Handle all instructions that operate on 16 bit address
 * this function covers these instructions
 * LDA, SDA, JC, JZ, JP, JPE, JNC, JNZ, JM, JPO, RC, RZ, RP, RPE, RNC, RNZ, RM,
 * RPO, CC, CZ, CP, CPE, CNC; CNZ, CM, CPO
 */
bool Parser::Handle16BitAddressInstructions(const TokenStruct &token) {
  std::cout
      << "[Parser]::[Handle16BitAddressInstructions]:[start for instruction "
      << token.m_tokenValue << "]" << std::endl;
  SixteenBitAddress address{"", 0x00, 0x00, false};

  TOKEN_TYPES type = this->ReturnTokenType(this->m_currentIndex + 1);

  std::vector<std::string> temp = this->GetNextNTokens(3); // will get only 2

  address = Helper::CheckAndReturn16BitAddress(temp[0]);
  if (type == TOKEN_NUMBER && !address.result) {
    std::cout
        << "[Parser]::[Handle16BitAddressInstructions]:[address is invalid "
        << temp[0] << "]" << std::endl;

  } else if (type == TOKEN_LABEL) { // TODO handle label
  }

  if (temp[1] != "NEWLINE") {
    if (temp[1][0] == ';' && this->PeekNextToken() == "NEWLINE") {
      std::cout << "[Parser]::[Handle16BitAddressInstructions]:[its a comment, "
                   "ahve to get another token "
                << temp[1] << "]" << std::endl;
    } else {
      return false;
    }
  }

  std::cout
      << "[Parser]::[Handle16BitAddressInstructions]:[ended for instruction "
      << token.m_tokenValue << "]" << std::endl;
  bool resultInst = this->ReturnInstructionHex(token.m_tokenValue + "_Address");
  this->m_finalParserProgram[this->pCounter] = (address.addressLow);
  this->pCounter++;
  this->m_finalParserProgram[this->pCounter] = (address.addressHigh);
  this->pCounter++;
  return resultInst;
}

/***
 * Handle all instructions that operate on 8 bit port number
 * this function covers these instructions
 * IN, OUT
 */
bool Parser::Handle8BitPortNumberInstructions(const TokenStruct &token) {
  return false;
}

/***
 * Handle all instructions operate on 16 bit register pair B & C,D & E,H & L
 * this function covers these instructions INX, DCX, DAD
 */
bool Parser::Handle16BitRegPairInstructions(const TokenStruct &token) {
  return false;
}

/***
 * Handle all instructions that operate on 16 bit immediate operand
 * this function covers these instructions
 * ADD, ADC, SUB, SBB, ANA, XRA, ORA, CMP
 */
bool Parser::Handle16BitImmediateOperandInstructions(const TokenStruct &token) {
  return false;
}

//************************PRIVATE FUNCTIONS END******************************