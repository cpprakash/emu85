#include "../includes/MainFrame.hpp"
#include <wx/menu.h>
#include <wx/stc/stc.h>

MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "8085 Microporcessor Emulator",
              wxPoint(0, 0)) {
  CreateMenuBar();
  CreateStatusBar();
  // CreateBoxSizers();
  CreateGUIControls();
  SetStatusText("Welcome to this quick todo list.");
  this->SetMinClientSize(wxSize(800, 600));
}

void MainFrame::CreateMenuBar() {
  m_pMainMenu = new wxMenuBar();
  m_pMainMenu->Append(new wxMenu("File"), "FileMenu");

  SetMenuBar(m_pMainMenu);
}

void MainFrame::CreateBoxSizers() { outer_box = new wxBoxSizer(wxVERTICAL); }

void MainFrame::CreateGUIControls() {
  code_window = new wxTextCtrl(this, wxID_ANY, "Hola", wxPoint(100, 100),
                               wxSize(300, 300), wxTE_MULTILINE);
  /*code_window->SetDefaultStyle(wxTextAttr(*wxRED));
  code_window->AppendText("Red text\n");
  code_window->SetDefaultStyle(wxTextAttr(wxNullColour, *wxLIGHT_GREY));
  code_window->AppendText("Red on grey text\n");
  code_window->SetDefaultStyle(wxTextAttr(*wxBLUE));
  code_window->AppendText("Blue on grey text\n");*/
  code_window->LoadFile("tests/prog1.asm", wxTEXT_TYPE_ANY);
}