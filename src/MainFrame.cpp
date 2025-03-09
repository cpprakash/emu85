#include "../includes/MainFrame.hpp"
#include <wx/menu.h>
#include <wx/stc/stc.h>

MainFrame::MainFrame()
    : wxFrame(nullptr, wxID_ANY, "8085 Microporcessor Simulator",
              wxPoint(0, 0)) {
  this->CreateMenuBar();
  this->CreateStatusBar();
  this->CreateGUIControls();
  this->CreateBoxSizers();
  SetStatusText("Welcome to 8085 Microporcessor Simulator.");
  this->SetMinClientSize(wxSize(800, 600));
}

/***
 * The menu bar for the app
 */
void MainFrame::CreateMenuBar() {

  this->m_pMainMenuBar = new wxMenuBar();

  /***file menu */
  this->m_pFileMenu = new wxMenu();
  this->m_pFileMenu->Append(wxID_ANY, wxT("New"));
  this->m_pFileMenu->Append(wxID_ANY, wxT("Open"));
  this->m_pFileMenu->Append(wxID_ANY, wxT("Open Recent"));
  this->m_pFileMenu->Append(wxID_ANY, wxT("Save"));
  this->m_pFileMenu->Append(wxID_ANY, wxT("Save As"));
  this->m_pFileMenu->Append(wxID_ANY, wxT("Save All"));
  this->m_pFileMenu->Append(wxID_EXIT, wxT("&Exit"));

  /***Edit menu */
  this->m_pEditMenu = new wxMenu();
  this->m_pEditMenu->Append(wxID_ANY, wxT("Undo"));
  this->m_pEditMenu->Append(wxID_ANY, wxT("Redo"));
  this->m_pEditMenu->Append(wxID_ANY, wxT("Cut"));
  this->m_pEditMenu->Append(wxID_ANY, wxT("Copy"));
  this->m_pEditMenu->Append(wxID_ANY, wxT("Paste"));
  this->m_pEditMenu->Append(wxID_ANY, wxT("Find"));
  this->m_pEditMenu->Append(wxID_ANY, wxT("Replace"));

  /***Tools menu */
  this->m_pToolsMenu = new wxMenu();
  this->m_pToolsMenu->Append(wxID_ANY, wxT("Dec To Bin"));
  this->m_pToolsMenu->Append(wxID_ANY, wxT("Dec To Hex"));
  this->m_pToolsMenu->Append(wxID_ANY, wxT("Hex to Bin"));
  this->m_pToolsMenu->Append(wxID_ANY, wxT("Hex to Dec"));
  this->m_pToolsMenu->Append(wxID_ANY, wxT("Bin to Hex"));
  this->m_pToolsMenu->Append(wxID_ANY, wxT("Bin to Dec"));

  /***View menu */
  this->m_pViewMenu = new wxMenu();
  this->m_pViewMenu->Append(wxID_ANY, wxT("View Stack"));
  this->m_pViewMenu->Append(wxID_ANY, wxT("View Registers"));
  this->m_pViewMenu->Append(wxID_ANY, wxT("View IOs"));

  /***Run menu */
  this->m_pRunMenu = new wxMenu();
  this->m_pRunMenu->Append(wxID_ANY, wxT("Compile"));
  this->m_pRunMenu->Append(wxID_ANY, wxT("Assemble"));
  this->m_pRunMenu->Append(wxID_ANY, wxT("Load Program"));
  this->m_pRunMenu->Append(wxID_ANY, wxT("Compile + Assemble + Load"));
  this->m_pRunMenu->Append(wxID_ANY, wxT("Run Program"));

  /***Help menu */
  this->m_pHelpMenu = new wxMenu();
  this->m_pHelpMenu->Append(wxID_ANY, wxT("About"));
  this->m_pHelpMenu->Append(wxID_ANY, wxT("Licence"));

  /***Append all menus to the menubar */
  this->m_pMainMenuBar->Append(this->m_pFileMenu, wxT("&File"));
  this->m_pMainMenuBar->Append(this->m_pEditMenu, wxT("&Edit"));
  this->m_pMainMenuBar->Append(this->m_pToolsMenu, wxT("&Tools"));
  this->m_pMainMenuBar->Append(this->m_pViewMenu, wxT("&View"));
  this->m_pMainMenuBar->Append(this->m_pRunMenu, wxT("&Run"));
  this->m_pMainMenuBar->Append(this->m_pHelpMenu, wxT("&Help"));

  this->m_pMainMenuBar->Show(true);
  SetMenuBar(m_pMainMenuBar);
}

void MainFrame::CreateBoxSizers() {
  /***
   * the main outer box sizer to hold all controls
   */
  this->m_pOuterBoxSizer = new wxBoxSizer(wxHORIZONTAL);
  /***
   * this registerboxsizer will hold all the registers info
   */
  this->m_pRegistersBoxSizer = new wxBoxSizer(wxVERTICAL);
  /***
   * this box sizer will hold code window on the top and the console window at
   * the bottom
   */
  this->m_pCodeWindowBoxSizer = new wxBoxSizer(wxVERTICAL);

  this->m_pCodeWindowBoxSizer->Add(this->m_pCodeWindow);
  this->m_pCodeWindowBoxSizer->Add(this->m_pConsoleListView);

  this->m_pRomRamBoxSizer = new wxBoxSizer(wxVERTICAL);
  this->m_pRomRamBoxSizer->Add(this->m_pRomListView);
  this->m_pRomRamBoxSizer->Add(this->m_pRamListView);

  wxStaticText *text =
      new wxStaticText(this, wxID_STATIC, wxT("Write here register values"));
  this->m_pOuterBoxSizer->Add(text);
  this->m_pOuterBoxSizer->Add(
      this->m_pCodeWindowBoxSizer); // add codeWindowBoxSizer

  this->m_pOuterBoxSizer->Add(
      this->m_pRomRamBoxSizer); // add Ram_Rom boxer to this boxer

  SetSizer(this->m_pOuterBoxSizer);
  this->m_pOuterBoxSizer->Fit(this);
}

/***
 * Create all GUI Controls in this function
 * gets called in the main frame constructor
 */
void MainFrame::CreateGUIControls() {
  this->m_pCodeWindow =
      new wxTextCtrl(this, wxID_ANY, "Hola", wxPoint(100, 100),
                     wxSize(300, 300), wxTE_MULTILINE);
  /*code_window->SetDefaultStyle(wxTextAttr(*wxRED));
  code_window->AppendText("Red text\n");
  code_window->SetDefaultStyle(wxTextAttr(wxNullColour, *wxLIGHT_GREY));
  code_window->AppendText("Red on grey text\n");
  code_window->SetDefaultStyle(wxTextAttr(*wxBLUE));
  code_window->AppendText("Blue on grey text\n");*/
  this->m_pCodeWindow->LoadFile("tests/testprog1.asm", wxTEXT_TYPE_ANY);
  this->m_pConsoleListView =
      new wxListView(this, wxID_ANY, wxDefaultPosition, wxSize(250, 200));
  this->m_pRomListView =
      new wxListView(this, wxID_ANY, wxDefaultPosition, wxSize(250, 200));
  this->m_pRamListView =
      new wxListView(this, wxID_ANY, wxDefaultPosition, wxSize(250, 200));
}