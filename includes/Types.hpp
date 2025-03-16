#ifndef __INCLUDES_TYPES_HPP__
#define __INCLUDES_TYPES_HPP__

#include <array>
#include <map>
#include <string>

typedef unsigned char u_BYTE;
typedef char BYTE;
typedef unsigned short u_WORD;
typedef short WORD;

static unsigned char MIN_CHAR_DATA{0};
static unsigned char MIN_BOOL_DATA{0b0000};
static unsigned char MIN_HEX_DATA{0x00};
static unsigned char MIN_OCT_DATA{00};

static unsigned char MAX_CHAR_DATA{255};
static unsigned char MAX_BOOL_DATA{0b11111111};
static unsigned char MAX_HEX_DATA{0xFF};
static unsigned char MAX_OCT_DATA{0377};

static unsigned short MIN_CHAR_ADDRESS{0};
static unsigned short MIN_BOOL_ADDRESS{0b0000000000000000};
static unsigned short MIN_HEX_ADDRESS{0x0000};
static unsigned short MIN_OCT_ADDRESS{00};

static unsigned short MAX_CHAR_ADDRESS{65535};
static unsigned short MAX_BOOL_ADDRESS{0b1111111111111111};
static unsigned short MAX_HEX_ADDRESS{0xFFFF};
static unsigned short MAX_OCT_ADDRESS{0177777};

static const unsigned short BIN_FILE_SIZE{1024};

/**
 * Const strings
 */
const std::string MESSAGE_SUCCESS{"SUCCESS"};

/***
 * Failure message strings
 */
const std::string MESSAGE_EMPTY_FIELD{"Data/Address is empty."};

// base for the operand
enum BASE { b, d, h, o };

// struct for 8 bit data
struct EightBitData {
  std::string message;
  int data;
  bool result;
};

// result struct with 16 bit address
struct SixteenBitAddress {
  std::string message;
  u_BYTE addressLow;
  u_BYTE addressHigh;
  bool result;
};

enum LOG_LEVELS {
  LOG_FATAL,
  LOG_ERROR,
  LOG_WARN,
  LOG_INFO,
  LOG_DEBUG,
  LOG_TRACE
};

// Token type
enum TOKEN_TYPES {
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

enum ERROR_TYPES {
  ERROR_ILLEGAL_INSTRUCTION,
  ERROR_MISSING_COLON,
  ERROR_MISSING_HEX,
  ERROR_ADDRESS_OUT_OF_RANGE,
  ERROR_DATA_OUT_OF_RANGE,
  ERROR_NO_NEWLINE_FOUND,
  ERROR_SYMBOL_REDEFINED, // if a lable is redefined
  ERROR_UNKNOW
};

enum RESULT_TYPES {
  RESULT_VALID_DATA,
  RESULT_MISSING_COLON,
  RESULT_MISSING_HEX,
  RESULT_ADDRESS_OUT_OF_RANGE,
  RESULT_DATA_OUT_OF_RANGE,
  RESULT_NO_NEWLINE_FOUND,
  RESULT_UNKNOW
};

/***
 * struct for SymbolTable
 */
struct SymbolTable {
  bool symbolFound;
  std::string symbolValue;
  unsigned int symbolLineNumber;
  unsigned char symbolAddressLow;
  unsigned char symbolAddressHigh;
};

/***
 * Token struct used for initial token generation from the file
 */
// TODO remove m_ from here
struct TokenStruct {
  unsigned int m_lineNumber;   // line of the token
  unsigned int m_startPos;     // start pos of the token
  unsigned int m_endPos;       // end pos of token
  unsigned long m_totalLength; // length of the token
  TOKEN_TYPES m_tokenType;     // type of toke: INST, LABEL etc..
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

// TODO fill this table
const std::map<std::string, unsigned char> type_mapInstructionBytes{
    {"ACI", 0},  {"ADC", 0},  {"ADD", 0},  {"ADI", 0},  {"ANA", 0},
    {"ANI", 0},  {"CALL", 0}, {"CC", 0},   {"CM", 0},   {"CMA", 0},
    {"CMC", 0},  {"CMP", 0},  {"CNC", 0},  {"CNZ", 0},  {"CP", 0},
    {"CPE", 0},  {"CPI", 0},  {"CPO", 0},  {"CZ", 0},   {"DAA", 0},
    {"DAD", 0},  {"DCR", 0},  {"DCX", 0},  {"DI", 0},   {"EI", 0},
    {"HLT", 0},  {"IN", 0},   {"INR", 0},  {"INX", 0},  {"JC", 0},
    {"JM", 3},   {"JMP", 3},  {"JNC", 3},  {"JNZ", 3},  {"JP", 3},
    {"JPE", 3},  {"JPO", 3},  {"JZ", 3},   {"LDA", 0},  {"LDAX", 0},
    {"LHLD", 0}, {"LXI", 0},  {"MOV", 0},  {"MVI", 0},  {"NOP", 0},
    {"ORA", 0},  {"ORI", 0},  {"OUT", 0},  {"PCHL", 0}, {"POP", 0},
    {"PUSH", 0}, {"RAL", 0},  {"RAR", 0},  {"RC", 0},   {"RET", 0},
    {"RIM", 0},  {"RLC", 0},  {"RM", 0},   {"RNC", 0},  {"RNZ", 0},
    {"RP", 0},   {"RPE", 0},  {"RPO", 0},  {"RRC", 0},  {"RST", 0},
    {"SSB", 0},  {"SBI", 0},  {"SHLD", 0}, {"SIM", 0},  {"SPHL", 0},
    {"STA", 0},  {"STAX", 0}, {"STC", 0},  {"SUB", 0},  {"SUI", 0},
    {"XCHG", 0}, {"XRA", 0},  {"XRI", 0},  {"XTHL", 0}};

const std::map<std::string, unsigned char> types_mapInstruction{
    {"ACI_Data", 0xCE},
    {"ADC_A", 0x8F},
    {"ADC_B", 0x88},
    {"ADC_C", 0x89},
    {"ADC_D", 0x8A},
    {"ADC_E", 0x8B},
    {"ADC_H", 0x8C},
    {"ADC_L", 0x8D},
    {"ADC_M", 0x8E},
    {"ADD_A", 0x87},
    {"ADD_B", 0x80},
    {"ADD_C", 0x81},
    {"ADD_D", 0x82},
    {"ADD_E", 0x83},
    {"ADD_H", 0x84},
    {"ADD_L", 0x85},
    {"ADD_M", 0x86},
    {"ADI_Data", 0xC6},
    {"ANA_A", 0xA7},
    {"ANA_B", 0xA0},
    {"ANA_C", 0xA1},
    {"ANA_D", 0xA2},
    {"ANA_E", 0xA3},
    {"ANA_H", 0xA4},
    {"ANA_L", 0xA5},
    {"ANA_M", 0xA6},
    {"ANI_Data", 0xE6},
    {"CALL_Address", 0xCD},
    {"CC_Address", 0xDC},
    {"CM_Address", 0xFC},
    {"CMA", 0x2F},
    {"CMC", 0x3F},
    {"CMP_A", 0xBF},
    {"CMP_B", 0xB8},
    {"CMP_C", 0xB9},
    {"CMP_D", 0xBA},
    {"CMP_E", 0xBB},
    {"CMP_H", 0xBC},
    {"CMP_L", 0xBD},
    {"CMP_M", 0xBD},
    {"CNC_Address", 0xD4},
    {"CNZ_Address", 0xC4},
    {"CP_Address", 0xF4},
    {"CPE_Address", 0xEC},
    {"CPI_Data", 0xFE},
    {"CPO_Address", 0xE4},
    {"CZ_Address", 0xCC},
    {"DAA", 0x27},
    {"DAD_B", 0x09},
    {"DAD_D", 0x19},
    {"DAD_H", 0x29},
    {"DAD_SP", 0x39},
    {"DCR_A", 0x3D},
    {"DCR_B", 0x05},
    {"DCR_C", 0x0D},
    {"DCR_D", 0x15},
    {"DCR_E", 0x1D},
    {"DCR_H", 0x25},
    {"DCR_L", 0x2D},
    {"DCR_M", 0x35},
    {"DCX_B", 0x0B},
    {"DCX_D", 0x1B},
    {"DCX_H", 0x2B},
    {"DCX_SP", 0x3B},
    {"DI", 0xF3},
    {"EI", 0xFB},
    {"HLT", 0x76},
    {"IN_Port-address", 0xDB},
    {"INR_A", 0x3C},
    {"INR_B", 0x04},
    {"INR_C", 0x0C},
    {"INR_D", 0x14},
    {"INR_E", 0x1C},
    {"INR_H", 0x24},
    {"INR_L", 0x2C},
    {"INR_M", 0x34},
    {"INX_B", 0x03},
    {"INX_D", 0x13},
    {"INX_H", 0x23},
    {"INX_SP", 0x33},
    {"JC_Address", 0xDA},
    {"JM_Address", 0xFA},
    {"JMP_Address", 0xC3},
    {"JNC_Address", 0xD2},
    {"JNZ_Address", 0xC2},
    {"JP_Address", 0xF2},
    {"JPE_Address", 0xEA},
    {"JPO_Address", 0xE2},
    {"JZ_Address", 0xCA},
    {"LDA_Address", 0x3A},
    {"LDAX_B", 0x0A},
    {"LDAX_D", 0x1A},
    {"LHLD_Address", 0x2A},
    {"LXI_B", 0x01},
    {"LXI_D", 0x11},
    {"LXI_H", 0x21},
    {"LXI_SP", 0x31},
    {"MOV_A_A", 0x7F},
    {"MOV_A_B", 0x78},
    {"MOV_A_C", 0x79},
    {"MOV_A_D", 0x7A},
    {"MOV_A_E", 0x7B},
    {"MOV_A_H", 0x7C},
    {"MOV_A_L", 0x7D},
    {"MOV_A_M", 0x7E},
    {"MOV_B_A", 0x47},
    {"MOV_B_B", 0x40},
    {"MOV_B_C", 0x41},
    {"MOV_B_D", 0x42},
    {"MOV_B_E", 0x43},
    {"MOV_B_H", 0x44},
    {"MOV_B_L", 0x45},
    {"MOV_B_M", 0x46},
    {"MOV_C_A", 0x4F},
    {"MOV_C_B", 0x48},
    {"MOV_C_C", 0x49},
    {"MOV_C_D", 0x4A},
    {"MOV_C_E", 0x4B},
    {"MOV_C_H", 0x4C},
    {"MOV_C_L", 0x4D},
    {"MOV_C_M", 0x4E},
    {"MOV_D_A", 0x57},
    {"MOV_D_B", 0x50},
    {"MOV_D_C", 0x51},
    {"MOV_D_D", 0x52},
    {"MOV_D_E", 0x53},
    {"MOV_D_H", 0x54},
    {"MOV_D_L", 0x55},
    {"MOV_D_M", 0x56},
    {"MOV_E_A", 0x5F},
    {"MOV_E_B", 0x58},
    {"MOV_E_C", 0x59},
    {"MOV_E_D", 0x5A},
    {"MOV_E_E", 0x5B},
    {"MOV_E_H", 0x5C},
    {"MOV_E_L", 0x5D},
    {"MOV_E_M", 0x5E},
    {"MOV_H_A", 0x67},
    {"MOV_H_B", 0x60},
    {"MOV_H_C", 0x61},
    {"MOV_H_D", 0x62},
    {"MOV_H_E", 0x63},
    {"MOV_H_H", 0x64},
    {"MOV_H_L", 0x65},
    {"MOV_H_M", 0x66},
    {"MOV_L_A", 0x6F},
    {"MOV_L_B", 0x68},
    {"MOV_L_C", 0x69},
    {"MOV_L_D", 0x6A},
    {"MOV_L_E", 0x6B},
    {"MOV_L_H", 0x6C},
    {"MOV_L_L", 0x6D},
    {"MOV_L_M", 0x6E},
    {"MOV_M_A", 0x77},
    {"MOV_M_B", 0x70},
    {"MOV_M_C", 0x71},
    {"MOV_M_D", 0x72},
    {"MOV_M_E", 0x73},
    {"MOV_M_H", 0x74},
    {"MOV_M_L", 0x75},
    {"MVI_A_Data", 0x3E},
    {"MVI_B_Data", 0x06},
    {"MVI_C_Data", 0x0E},
    {"MVI_D_Data", 0x16},
    {"MVI_E_Data", 0x1E},
    {"MVI_H_Data", 0x26},
    {"MVI_L_Data", 0x2E},
    {"MVI_M_Data", 0x36},
    {"NOP", 0x00},
    {"ORA_A", 0xB7},
    {"ORA_B", 0xB0},
    {"ORA_C", 0xB1},
    {"ORA_D", 0xB2},
    {"ORA_E", 0xB3},
    {"ORA_H", 0xB4},
    {"ORA_L", 0xB5},
    {"ORA_M", 0xB6},
    {"ORI_Data", 0xF6},
    {"OUT_Port-Address", 0xD3},
    {"PCHL", 0xE9},
    {"POP_B", 0xC1},
    {"POP_D", 0xD1},
    {"POP_H", 0xE1},
    {"POP_PSW", 0xF1},
    {"PUSH_B", 0xC5},
    {"PUSH_D", 0xD5},
    {"PUSH_H", 0xE5},
    {"PUSH_PSW", 0xF5},
    {"RAL", 0x17},
    {"RAR", 0x1F},
    {"RC", 0xD8},
    {"RET", 0xC9},
    {"RIM", 0x20},
    {"RLC", 0x07},
    {"RM", 0xF8},
    {"RNC", 0xD0},
    {"RNZ", 0xC0},
    {"RP", 0xF0},
    {"RPE", 0xE8},
    {"RPO", 0xE0},
    {"RRC", 0x0F},
    {"RST_0", 0xC7},
    {"RST_1", 0xCF},
    {"RST_2", 0xD7},
    {"RST_3", 0xDF},
    {"RST_4", 0xE7},
    {"RST_5", 0xEF},
    {"RST_6", 0xF7},
    {"RST_7", 0xFF},
    {"RZ", 0xC8},
    {"SBB_A", 0x9F},
    {"SBB_B", 0x98},
    {"SBB_C", 0x99},
    {"SBB_D", 0x9A},
    {"SBB_E", 0x9B},
    {"SBB_H", 0x9C},
    {"SBB_L", 0x9D},
    {"SBB_M", 0x9E},
    {"SBI_Data", 0xDE},
    {"SHLD_Address", 0x22},
    {"SIM", 0x30},
    {"SPHL", 0xF9},
    {"STA_Address", 0x32},
    {"STAX_B", 0x02},
    {"STAX_D", 0x12},
    {"STC", 0x37},
    {"SUB_A", 0x97},
    {"SUB_B", 0x90},
    {"SUB_C", 0x91},
    {"SUB_D", 0x92},
    {"SUB_E", 0x93},
    {"SUB_H", 0x94},
    {"SUB_L", 0x95},
    {"SUB_M", 0x96},
    {"SUI_Data", 0xD6},
    {"XCHG", 0xEB},
    {"XRA_A", 0xAF},
    {"XRA_B", 0xA8},
    {"XRA_C", 0xA9},
    {"XRA_D", 0xAA},
    {"XRA_E", 0xAB},
    {"XRA_H", 0xAC},
    {"XRA_L", 0xAD},
    {"XRA_M", 0xAE},
    {"XRI_Data", 0xEE},
    {"XTHL", 0xE3},
};
#endif