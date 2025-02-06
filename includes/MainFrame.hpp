#ifndef __HEADER_MAINFRAME__
#define __HEADER_MAINFRAME__

#include <wx/menu.h>
#include <wx/stc/stc.h>
#include <wx/wx.h>

class MainFrame : public wxFrame {
private:
  wxMenuBar *m_pMainMenu;
  wxBoxSizer *outer_box;

  wxTextCtrl *code_window; // Main Text Control for code

private:
  void CreateMenuBar(void);     // Create MenuBar
  void CreateBoxSizers(void);   // Create all sizers here
  void CreateGUIControls(void); // Create all GUI Controls here

public:
  MainFrame();
};

#endif