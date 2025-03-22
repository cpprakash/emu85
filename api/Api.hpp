#ifndef __API_API_HPP__
#define __API_API_HPP__

#include "../includes/Types.hpp"

class Api {
public:
  Api();
  // void GetDataForGUI(void);
  GuiData GetDataForGUI(const char *filePath);
};

#endif