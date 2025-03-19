#include "Api.hpp"

#include <iostream>
#include <vector>

#include "../includes/FileHandler.hpp"
#include "../includes/Parser.hpp"
#include "../includes/Types.hpp"

Api::Api() {}

/***
 * function responsible for returning the data required by the frontend, this
 * means the frontend needs to give this function a file path for the .asm file
 * this function must parse the .asm file and generate these data structures
 * 1. generate tokens (for debugging)
 * 2. generate ROM file of the program in case program was compiled
 * 3. generate all the log messages for the frontend
 * 4. generate the other control structure
 */
GuiData Api::GetDataForGUI(const char *filePath) {
  GuiData result = {};
  FileHandler m_fileHandler;
  const std::vector<TokenStruct> m_tokens =
      m_fileHandler.ReturnTokens(filePath);
  Parser m_parser;
  // result.m_finalParsedProgram = m_parser.ParseProgram(m_tokens);

  result.m_tokens = m_tokens;

  /*for (unsigned long i = 0; i < m_tokens.size(); i++)
    std::cout << "Tokens received i =" << i
              << " value =" << m_tokens[i].m_tokenValue << std::endl;*/
  return result;
}
