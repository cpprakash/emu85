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
  std::ifstream file(this->m_fileName, std::ios::in | std::ios::binary);
  if (file.is_open()) {
    file.read(fileContent, 1024);
    file.close();
    for (unsigned long i = 0; i < 1024; i++) {
      const auto data = types_mapOpcode.find(fileContent[i]);
      if (data != types_mapOpcode.end()) {
        std::cout << "[Disassembler]::[ReadBinaryFileToDisassemble]:[found "
                     "instruction = "
                  << this->ReturnInstructionWithoutUnderscore(data->second)
                  << "]" << std::endl;

        if (data->second == "HLT")
          break; // found last instruction, no need to loop any further

        switch (data->first) {
        case 0x00:
          break;

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