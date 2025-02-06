#include "../includes/MainFrame.hpp"

MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "8085 Microporcessor Emulator",
              wxPoint(0, 0)) {
  CreateStatusBar();
  SetStatusText("Welcome to this quick todo list.");
  this->SetMinClientSize(wxSize(800, 600));
}
