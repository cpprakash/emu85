#include "../includes/FileHandler.hpp"
#include "../includes/Assembler.hpp"
#include "../includes/Helper.hpp"
#include "../includes/Parser.hpp"

#include <algorithm>
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
    Parser m_parser;

    delete[] memblock; // frre up the memory
    // m_assembler.AssembleProgram(this->m_vectTokens);
    unsigned char *data = m_parser.ParseProgram(this->m_vectTokens);
    this->WriteBinFile("test.bin", data,
                       1024); // TODO fix it to call the function from
    // itself
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
      this->m_vectTokens.push_back(
          {line_number, 0, 0, 0, TOKEN_NEWLINE, "NEWLINE"});
      line_number++;
      continue;
    }
    if (isspace(file_text[i])) { // check if token is space, do nothing
      cur_pos++;
      continue;
    }
    if (isalnum(file_text[i])) { // check if token starts with character
      start_pos = i;
      std::string temp_string;
      while (isalnum(file_text[i])) { // collect the token
        cur_pos++;
        temp_string += file_text[i];
        i++;
      }
      end_pos = i;
      if (std::find(this->m_arrAllInstructions.begin(),
                    this->m_arrAllInstructions.end(),
                    Helper::ConvertToUppercase(temp_string)) !=
          std::end(this->m_arrAllInstructions)) {
        m_vectTokens.push_back({line_number, start_pos + 1, end_pos,
                                temp_string.length(), TOKEN_INSTRUCTION,
                                Helper::ConvertToUppercase(temp_string)});
      } else {
        m_vectTokens.push_back({line_number, start_pos + 1, end_pos,
                                temp_string.length(), TOKEN_LABEL,
                                temp_string});
      }

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
      this->m_vectTokens.push_back({line_number, start_pos, end_pos - 1,
                                    temp_num.length(), TOKEN_NUMBER, temp_num});
      i--;
      // std::cout << "TempNumber = " << temp_num << std::endl;
    } else if (file_text[i] == ',') {
      this->m_vectTokens.push_back(
          {line_number, i, i + 1, 1, TOKEN_COMMA, "COMMA"});
    } else if (file_text[i] == ':') {
      this->m_vectTokens.push_back(
          {line_number, i, i + 1, 1, TOKEN_COLON, "COLON"});
    } else if (file_text[i] == ';') {
      this->m_vectTokens.push_back(
          {line_number, i, i + 1, 1, TOKEN_COMMENT, "COMMENT"});
    } else {
      this->m_vectTokens.push_back(
          {line_number, i, i + 1, 1, TOKEN_UNKNOWN, "UNKNWON"});
      std::cout << "Unknow token|" << file_text[i] << "|" << std::endl;
    }
  }
  if (this->m_vectTokens[this->m_vectTokens.size()].m_tokenValue != "NEWLINE") {
    this->m_vectTokens.push_back(
        {line_number, 1, 8, 8, TOKEN_NEWLINE, "NEWLINE"}); // add newline
  }
  this->m_vectTokens.push_back({line_number, 1, 3, 3, TOKEN_EOF, "EOF"});
}
/***
 * write the bin ROM file with the program
 * takes argument file name
 * unsigned char array of data
 * and the fiel size, default is 1kBx8
 */
bool FileHandler::WriteBinFile(const std::string &file, unsigned char data[],
                               unsigned long size = 1024ul) {
  std::ofstream out_file;
  out_file.open("./tests/prog.bin", std::ios::out | std::ios::binary);
  if (!out_file.is_open()) {
    std::cout << "Could not write to the file, please try again later!"
              << std::endl;
    return false;
  }
  std::cout << "Writing bin file with a data size of =" << size << std::endl;
  out_file.write((char *)(&data), size);
  out_file.close();
  return true;
}
