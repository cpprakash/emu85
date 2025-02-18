#include "../includes/FileHandler.hpp"
#include "../includes/Assembler.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
/***
 * Reads the file based on the parameters passed from the main function
 */
void FileHandler::ReadFile(char *file_path) {
  std::streampos size;
  char *memblock;

  std::ifstream file(file_path,
                     std::ios::in | std::ios::binary | std::ios::ate);
  if (file.is_open()) {
    size = file.tellg();
    memblock = new char[size];
    file.seekg(0, std::ios::beg);
    file.read(memblock, size);
    file.close();

    GenerateTokens(memblock);
    Assembler m_assembler;

    delete[] memblock;
    m_assembler.AssembleProgram(this->m_vectTokens);
    m_assembler.WriteBinFile();
  } else {
    std::cout << "Unable to open file" << std::endl;
    return;
  }
}

/***
 * Generates the tokens based on the file content of the <program>.asm file
 */
void FileHandler::GenerateTokens(const std::string &file_text) {
  unsigned int line_number{1};
  unsigned int start_pos{0};
  unsigned int end_pos{0};
  unsigned int cur_pos{0};
  // std::cout << file_text << std::endl;
  for (unsigned int i = 0; i < file_text.length(); i++) {
    if (file_text[i] == '\n' || file_text[i] == '\r') { // newline character
      cur_pos = 0;
      this->m_vectTokens.push_back({line_number, 0, 0, 0, "NEWLINE"});
      line_number++;
      continue;
    }
    if (isspace(file_text[i])) { // check if token is space, do nothing
      cur_pos++;
      continue;
    }
    if (isalpha(file_text[i])) { // check if token starts with character
      start_pos = i;
      std::string temp_string;
      while (isalpha(file_text[i])) { // collect the token
        cur_pos++;
        temp_string += file_text[i];
        i++;
      }
      end_pos = i;
      m_vectTokens.push_back({line_number, start_pos + 1, end_pos,
                              temp_string.length(), temp_string});
      i--;
    } else if (isdigit(file_text[i])) { // check if token starts with a digit
      start_pos = i;
      cur_pos++;
      std::string temp_num;
      while (isdigit(file_text[i])) { // while it is a digit collect it
        temp_num += file_text[i];
        i++;
      }
      end_pos = i;
      this->m_vectTokens.push_back(
          {line_number, start_pos, end_pos - 1, temp_num.length(), temp_num});
      i--;
      // std::cout << "TempNumber = " << temp_num << std::endl;
    } else if (file_text[i] == ',') {
      this->m_vectTokens.push_back({line_number, i, i + 1, 1, "COMMA"});
    } else if (file_text[i] == ':') {
      this->m_vectTokens.push_back({line_number, i, i + 1, 1, "COLON"});
    } else if (file_text[i] == ';') {
      this->m_vectTokens.push_back({line_number, i, i + 1, 1, "COMMENT"});
    } else {
      this->m_vectTokens.push_back({line_number, i, i + 1, 1, "COMMENT"});
      std::cout << "Unknow token|" << file_text[i] << "|" << std::endl;
    }
  }
  this->m_vectTokens.push_back({line_number, 1, 3, 3, "EOF"});
}
