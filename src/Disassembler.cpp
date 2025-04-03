#include "../includes/Disassembler.hpp"
#include "../includes/Types.hpp"

#include <fstream>
#include <iostream>

// constructor
Disassembler::Disassembler(const char *fileName) : m_fileName{fileName} {}

// public function to disassmble program
// which calls the private function of the same class
void Disassembler::DisassembleProgram(void) {
  std::cout << "[Disassembler]::[DisassembleProgram]:[start]" << std::endl;
  if (this->m_fileName == nullptr) {
    std::cout << "File name is empty, cant disassemble" << std::endl;
  } else {
    this->ReadBinaryFileToDisassemble();
  }
  std::cout << "[Disassembler]::[DisassembleProgram]:[end]" << std::endl;
}

// This function actually disassemble the program
void Disassembler::ReadBinaryFileToDisassemble(void) {
  std::cout << "[Disassembler]::[ReadBinaryFileToDisassemble]:[start]"
            << std::endl;
  char fileContent[1024];
  const unsigned char a = 0xA9;
  std::ifstream file(this->m_fileName, std::ios::in | std::ios::binary);
  if (file.is_open()) {
    file.read(fileContent, 1024);
    file.close();
    for (unsigned long i = 0; i < 1024; i++) {
      const auto data = types_mapOpcode.find(fileContent[i]);
      if (data != types_mapOpcode.end()) {
        /*std::cout << "[Disassembler]::[ReadBinaryFileToDisassemble]:[found "
                     "instruction = "
                  << this->ReturnInstructionWithoutUnderscore(data->second)
                  << "]" << std::endl;*/

        if (data->second == "HLT") {
          std::cout << "HLT" << std::endl;
          break; // found last instruction, no need to loop any further
        }

        switch (data->first) {
        case 0x3E: // MVI_A instruction
        case 0x06: // MVI_B instruction
        case 0x0E: // MVI_C instruction
        case 0x16: // MVI_D instruction
        case 0x1E: // MVI_E instruction
        case 0x26: // MVI_H instruction
        case 0x2E: // MVI_L instruction
        case 0x36: // MVI_M instruction
          // all these instruction have one byte of data
          {
            std::cout << this->ReturnInstructionWithoutUnderscore(data->second)
                      << ", 0" << std::hex << std::uppercase
                      << static_cast<unsigned char>(fileContent[i + 1]) % 255
                      << std::dec << "H" << std::endl;
            i++;
          }
          break;

        case 0xE8: // RPE
        case 0xD0: // RNC
        case 0xC0: // RNZ
        case 0xF8: // RM
        case 0xE0: // RPO
        case 0xDC: // CC
        case 0xCC: // CZ
        case 0xF4: // CP
        case 0xEC: // CPE
        case 0xD4: // CNC
        case 0xC4: // CNZ
        case 0xFC: // CM
        case 0xE4: // CPO
        case 0x2A: // LHLD
        case 0x22: // SHLD
        case 0x3A: // LDA
        case 0x32: // STA
        case 0xD8: // RC
        case 0xC8: // RZ
        case 0xF0: // RP
        case 0xDA: //{0xDA, "JC"}
        case 0xFA: //{0xFA, "JM"},
        case 0xC3: //{0xC3, "JMP"},
        case 0xD2: //{0xD2, "JNC"},
        case 0xC2: //{0xC2, "JNZ"},
        case 0xF2: //{0xF2, "JP"},
        case 0xEA: //{0xEA, "JPE"}
        case 0xE2: //{0xE2, "JPO"},
        case 0xCA: //{0xCA, "JZ"}
        {
          std::cout << data->second << " 0" << std::hex
                    << (static_cast<unsigned short>(fileContent[i + 2] << 8) |
                        (fileContent[i + 1]))
                    << std::dec << "H" << std::endl;
          i += 2; // increment with 2, one for high and one for low byte

        } break;

        case 0x8F: //{0x8F, "ADC_A"}
        case 0x88: //{0x88, "ADC_B"}
        case 0x89: //{0x89, "ADC_C"}
        case 0x8A: //{0x8A, "ADC_D"}
        case 0x8B: //{0x8B, "ADC_E"}
        case 0x8C: //{0x8C, "ADC_H"}
        case 0x8D: //{0x8D, "ADC_L"}
        case 0x8E: //{0x8E, "ADC_M"}

        case 0x87: //{0x87, "ADD_A"}
        case 0x80: //{0x80, "ADD_B"}
        case 0x81: //{0x81, "ADD_C"}
        case 0x82: //{0x82, "ADD_D"}
        case 0x83: //{0x83, "ADD_E"}
        case 0x84: //{0x84, "ADD_H"}
        case 0x85: //{0x85, "ADD_L"}
        case 0x86: //{0x86, "ADD_M"}

        case 0xA7: //{0xA7, "ANA_A"}
        case 0xA0: //{0xA0, "ANA_B"}
        case 0xA1: //{0xA1, "ANA_C"}
        case 0xA2: //{0xA2, "ANA_D"}
        case 0xA3: //{0xA3, "ANA_E"}
        case 0xA4: //{0xA4, "ANA_H"}
        case 0xA5: //{0xA5, "ANA_L"}
        case 0xA6: //{0xA6, "ANA_M"}

        case 0xBF: //{0xBF, "CMP_A"}
        case 0xB8: //{0xB8, "CMP_B"}
        case 0xB9: //{0xB9, "CMP_C"}
        case 0xBA: //{0xBA, "CMP_D"}
        case 0xBB: //{0xBB, "CMP_E"}
        case 0xBC: //{0xBC, "CMP_H"}
        case 0xBD: //{0xBD, "CMP_L"}
        case 0xBE: //{0xBE, "CMP_M"}

        case 0x3D: //{0x3D, "DCR_A"}
        case 0x05: //{0x05, "DCR_B"}
        case 0x0D: //{0x0D, "DCR_C"}
        case 0x15: //{0x15, "DCR_D"}
        case 0x1D: //{0x1D, "DCR_E"}
        case 0x25: //{0x25, "DCR_H"}
        case 0x2D: //{0x2D, "DCR_L"}
        case 0x35: //{0x35, "DCR_M"}

        case 0x3C: //{0x3C, "INR_A"}
        case 0x04: //{0x04, "INR_B"}
        case 0x0C: //{0x0C, "INR_C"}
        case 0x14: //{0x14, "INR_D"}
        case 0x1C: //{0x1C, "INR_E"}
        case 0x24: //{0x24, "INR_H"}
        case 0x2C: //{0x2C, "INR_L"}
        case 0x34: //{0x34, "INR_M"}

        case 0xB7: //{0xB7, "ORA_A"}
        case 0xB0: //{0xB0, "ORA_B"}
        case 0xB1: //{0xB1, "ORA_C"}
        case 0xB2: //{0xB2, "ORA_D"}
        case 0xB3: //{0xB3, "ORA_E"}
        case 0xB4: //{0xB4, "ORA_H"}
        case 0xB5: //{0xB5, "ORA_L"}
        case 0xB6: //{0xB6, "ORA_M"}

        case 0x9F: //{0x9F, "SBB_A"}
        case 0x98: //{0x98, "SBB_B"}
        case 0x99: //{0x99, "SBB_C"}
        case 0x9A: //{0x9A, "SBB_D"}
        case 0x9B: //{0x9B, "SBB_E"}
        case 0x9C: //{0x9C, "SBB_H"}
        case 0x9D: //{0x9D, "SBB_L"}
        case 0x9E: //{0x9E, "SBB_M"}

        case 0x97: //{0x97, "SUB_A"}
        case 0x90: //{0x90, "SUB_B"}
        case 0x91: //{0x91, "SUB_C"}
        case 0x92: //{0x92, "SUB_D"}
        case 0x93: //{0x93, "SUB_E"}
        case 0x94: //{0x94, "SUB_H"}
        case 0x95: //{0x95, "SUB_L"}
        case 0x96: //{0x96, "SUB_M"}

        case 0xAF: //{0xAF, "XRA_A"}
        case 0xA8: //{0xA8, "XRA_B"}
        case 0xA9: //{0xA9, "XRA_C"}
        case 0xAA: //{0xAA, "XRA_D"}
        case 0xAB: //{0xAB, "XRA_E"}
        case 0xAC: //{0xAC, "XRA_H"}
        case 0xAD: //{0xAD, "XRA_L"}
        case 0xAE: //{0xAE, "XRA_M"}
        {
          std::cout << this->ReturnInstructionWithoutUnderscore(data->second)
                    << std::endl;
        } break;
        case 0x2F: // CMA
        {
          std::cout << this->ReturnInstructionWithoutUnderscore(data->second)
                    << std::endl;
        } break;
        case 0x7F: // MOV_A_A
        case 0x78: // MOV_A_B
        case 0x79: // MOV_A_C
        case 0x7A: // MOV_A_D
        case 0x7B: // MOV_A_E
        case 0x7C: // MOV_A_H
        case 0x7D: // MOV_A_L
        case 0x7E: // MOV_A_M
        case 0x47: // MOV_B_A
        case 0x40: // MOV_B_B
        case 0x41: // MOV_B_C
        case 0x42: // MOV_B_D
        case 0x43: // MOV_B_E
        case 0x44: // MOV_B_H
        case 0x45: // MOV_B_L
        case 0x46: // MOV_B_M
        case 0x4F: // MOV_C_A
        case 0x48: // MOV_C_B
        case 0x49: // MOV_C_C
        case 0x4A: // MOV_C_D
        case 0x4B: // MOV_C_E
        case 0x4C: // MOV_C_H
        case 0x4D: // MOV_C_L
        case 0x4E: // MOV_C_M
        case 0x57: // MOV_D_A
        case 0x50: // MOV_D_B
        case 0x51: // MOV_D_C
        case 0x52: // MOV_D_D
        case 0x53: // MOV_D_E
        case 0x54: // MOV_D_H
        case 0x55: // MOV_D_L
        case 0x56: // MOV_D_M
        case 0x5F: // MOV_E_A
        case 0x58: // MOV_E_B
        case 0x59: // MOV_E_C
        case 0x5A: // MOV_E_D
        case 0x5B: // MOV_E_E
        case 0x5C: // MOV_E_H
        case 0x5D: // MOV_E_L
        case 0x5E: // MOV_E_M
        case 0x67: // MOV_H_A
        case 0x60: // MOV_H_B
        case 0x61: // MOV_H_C
        case 0x62: // MOV_H_D
        case 0x63: // MOV_H_E
        case 0x64: // MOV_H_H
        case 0x65: // MOV_H_L
        case 0x66: // MOV_H_M
        case 0x6F: // MOV_L_A
        case 0x68: // MOV_L_B
        case 0x69: // MOV_L_C
        case 0x6A: // MOV_L_D
        case 0x6B: // MOV_L_E
        case 0x6C: // MOV_L_H
        case 0x6D: // MOV_L_L
        case 0x6E: // MOV_L_M
        case 0x77: // MOV_M_A
        case 0x70: // MOV_M_B
        case 0x71: // MOV_M_C
        case 0x72: // MOV_M_D
        case 0x73: // MOV_M_E
        case 0x74: // MOV_M_H
        case 0x75: // MOV_M_L
        {
          std::cout << this->ReturnInstructionWithoutUnderscore(data->second)
                    << std::endl;
        } break;

        case 0x00: // nop
        {
          std::cout << "NOP" << std::endl;
        } break;

        default:
          break;
        }
      }
    }
  }

  else {
    std::cout
        << "[Disassembler]::[ReadBinaryFileToDisassemble]:[file open error]"
        << std::endl;
  }
  std::cout << "[Disassembler]::[ReadBinaryFileToDisassemble]:[end]"
            << std::endl;
}

/***
 * takes the string like MOV_A_B and returns the string like MOV A, B
 */
const std::string &
Disassembler::ReturnInstructionWithoutUnderscore(const std::string &input) {
  this->m_strInstruction = "";
  bool firstComma = false;
  if (input == "")
    return this->m_strInstruction;

  unsigned int counter = 0;
  while (counter < input.length()) {
    if (input[counter] == '_') {
      if (firstComma == false) {
        this->m_strInstruction += ' ';
        firstComma = true;
        counter++;
      } else {
        this->m_strInstruction += ", ";
        counter++;
      }
    }
    this->m_strInstruction += input[counter];
    counter++;
  }
  return this->m_strInstruction;
}