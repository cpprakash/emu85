#ifndef __INCLUDES_DISASSEMBLER_HPP__
#define __INCLUDES_DISASSEMBLER_HPP__

#include <string>

class Disassembler {
public:
  Disassembler(const char *fileName);
  void DisassembleProgram();

private:
  void ReadBinaryFileToDisassemble();
  const std::string &
  ReturnInstructionWithoutUnderscore(const std::string &input);

private:
  const char *m_fileName;
  std::string m_strInstruction;
};

#endif