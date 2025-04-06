#ifndef __INCLUDES_PROCESSOR_HPP__
#define __INCLUDES_PROCESSOR_HPP__

class Processor {
public:
  Processor() : m_usProgramCounter{0x0000} {
    this->SetProgramCounter();
    this->SetAccumulator(0x00);    // set the accumulator
    this->InitProgramStatusWord(); // set the PSWs
    this->SetStackPointer();       // set stackppinter to max add
  }

private:
  void GetProgramCounter();
  const char &GetAccumulator();
  void SetAccumulator(const char *value);
  void InitProgramStatusWord();
  void SetStackPointer();
  void SetProgramCounter();
  void SetAuxCarryBit(bool value);
  void SetParityBit(bool value);
  void SetZeroBit(bool value);
  void SetSignBit(bool value);
  void SetCarryBit(bool value);

public:
  unsigned short m_usProgramCounter;

private:
  char m_cAccumulator; // Accumulator Register
  unsigned short m_usMem;
  unsigned char m_cAccumulator; // accumulator
  unsigned char m_ucRegB;       // register B
  unsigned char m_ucRegC;       // register C
  unsigned char m_ucRegD;       // register D
  unsigned char m_ucRegE;       // register E
  unsigned char m_ucRegH;       // register H
  unsigned char m_ucRegL;       // register L

  // Stack pointer
  unsigned short m_usStackPointer;
  /**  Program Status Word
   *  bit 0 = AC (auxillary carry)
   *  bit 1 = P (Parity) XXXCSZPAC
   *  bit 2 = Z (Zero)
   *  bit 3 = S (Sign)
   *  bit 4 = C (carry)
   * bit 5, 6, 7 we dont care
   */
  unsigned char m_ucPSW;
};

#endif // end  __INCLUDES_PROCESSOR_HPP__