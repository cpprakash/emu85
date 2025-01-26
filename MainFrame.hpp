#ifndef __HEADER_MAINFRAME__
#define __HEADER_MAINFRAME__

#include <wx/wx.h>

class MainFrame : public wxFrame {
private:
  unsigned int id = 0;
  unsigned int rank = 0;

public:
  MainFrame();
};

#endif