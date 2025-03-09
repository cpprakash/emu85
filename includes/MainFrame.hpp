#ifndef __INCLUDES_MAINFRAME_HPP__
#define __INCLUDES_MAINFRAME_HPP__

#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/stc/stc.h>
#include <wx/wx.h>

class MainFrame : public wxFrame {
private:
  /***
   * Menu related variables
   */
  wxMenuBar *m_pMainMenuBar;
  wxMenu *m_pFileMenu;
  wxMenu *m_pEditMenu;
  wxMenu *m_pToolsMenu;
  wxMenu *m_pViewMenu;
  wxMenu *m_pRunMenu;
  wxMenu *m_pHelpMenu;

  /***sizers variables*/
  wxBoxSizer *m_pOuterBoxSizer;
  wxBoxSizer *m_pRegistersBoxSizer;
  wxBoxSizer *m_pCodeWindowBoxSizer;
  wxBoxSizer *m_pRomBoxSizer; // displays the ROM
  wxBoxSizer *m_pRamBoxSizer; // displays the RAM

  /***
   * text control where youc an write your code
   */
  wxTextCtrl *m_pCodeWindow;      // Main Text Control for code
  wxListView *m_pConsoleListView; // List view to display ROM

  wxListView *m_pRomListView; // List view to display ROM
  wxListView *m_pRamListView; // List view to display RAM

private:
  void CreateMenuBar(void);     // Create MenuBar
  void CreateBoxSizers(void);   // Create all sizers here
  void CreateGUIControls(void); // Create all GUI Controls here

public:
  MainFrame();
};

#endif