#ifndef __INCLUDES_DISASSEMBLER_HPP__
#define __INCLUDES_DISASSEMBLER_HPP__

class Disassembler {
public:
  Disassembler(const char *fileName);
  void DisassembleProgram();

private:
  void ReadBinaryFileToDisassemble();

private:
  const char *m_fileName;
};

#endif