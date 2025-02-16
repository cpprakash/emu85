#ifndef __HEADERS_PROCESSOR_HPP__
#define __HEADERS_PROCESSOR_HPP__

class Processor {
public:
  Processor() : m_usProgramCounter{0x0000} {}

private:
  void GetProgramCounter();

public:
  unsigned short m_usProgramCounter;

private:
  unsigned short m_usMem;
  unsigned char m_cAccumulator; // accumulator
  unsigned char m_ucRegB;       // register B
  unsigned char m_ucRegC;       // register C
  unsigned char m_ucRegD;       // register D
  unsigned char m_ucRegE;       // register E
  unsigned char m_ucRegH;       // register H
  unsigned char m_ucRegL;       // register L

  unsigned short m_usStackPointer; // Stack pointer

  unsigned char m_ucPSW; // Program Status Word
};

#endif // end  __HEADERS_PROCESSOR_HPP__