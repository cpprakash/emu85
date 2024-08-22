#ifndef __HEADERS_INSTRUCTIONS_HPP__
#define __HEADERS_INSTRUCTIONS_HPP__

#include <iostream>

class Instructions {
public:
  Instructions(void);

private:
  void FetchNextInstructions(void);

public:
  std::string instruction_name;

private:
  unsigned int total_instructions;
};

#endif