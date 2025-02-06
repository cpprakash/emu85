// For compilers that don't support precompilation, include "wx/wx.h"
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "../includes/MainApp.hpp"
#include "../includes/MainFrame.hpp"

// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool MainApp::OnInit() {
  MainFrame *mainFrame = new MainFrame();
  mainFrame->SetClientSize(1000, 800);
  mainFrame->Center();

  mainFrame->Show();
  return true;
}