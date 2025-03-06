
#ifndef __INCLUDES_MAINAPP_HPP__
#define __INCLUDES_MAINAPP_HPP__

#include <wx/wx.h>

// The MainApp class.
class MainApp : public wxApp {
public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MainApp);

#endif // __MAINAPP_HPP__