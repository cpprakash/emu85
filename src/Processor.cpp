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