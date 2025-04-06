#include "includes/Processor.hpp"

#include <iostream>

void Processor::GetProgramCounter() {}

/**
 * Set the value of the accumulator
 */

void Processor::SetAccumulator(const char *value) {
  std::cout << "Assembler::SetAccumulator::Old value of Acc= "
            << this->m_cAccumulator << std::endl;
  this->m_cAccumulator = atoi(value);
  std::cout << "Assembler::SetAccumulator::New value of Acc= "
            << this->m_cAccumulator << std::endl;
}

/***
 * Get the value of the accumulator register
 */
const char &Processor::GetAccumulator() { return this->m_cAccumulator; }

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Private functions

void Processor::InitProgramStatusWord(void) {
  this->SetAuxCarryBit(false);
  this->SetParityBit(false);
  this->SetZeroBit(false);
  this->SetSignBit(false);
  this->SetCarryBit(false);
}

void Processor::SetStackPointer(void) {}

void Processor::SetProgramCounter(void) {}

/***
 * set/reset all psw registers
 */
void Processor::SetAuxCarryBit(bool value) {
  this->m_ucPSW = this->m_ucPSW & (value << 0);
}
void Processor::SetParityBit(bool value) {
  this->m_ucPSW = this->m_ucPSW & (value << 1);
}
void Processor::SetZeroBit(bool value) {
  this->m_ucPSW = this->m_ucPSW & (value << 2);
}
void Processor::SetSignBit(bool value) {
  this->m_ucPSW = this->m_ucPSW & (value << 3);
}
void Processor::SetCarryBit(bool value) {
  this->m_ucPSW = this->m_ucPSW & (value << 4);
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++