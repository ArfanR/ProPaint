#pragma once
#include <wx/frame.h>
#include <wx/timer.h>
#include <wx/menu.h>
#include <memory>
#include "EventID.h"
#include "Cursors.h"

class PaintFrame : public wxFrame
{
public:
	PaintFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
	// Helper setup function
	void SetupMenu();
	void SetupToolbar();
	void SetupModelAndView();
	
	// Exit event (close program)
	void OnExit(wxCommandEvent& event);
	// File>New event
	void OnNew(wxCommandEvent& event);
	
	// Export the drawing to an image
	void OnExport(wxCommandEvent& event);
	// Import an image into the drawing
	void OnImport(wxCommandEvent& event);

	// Edit>Undo
	void OnUndo(wxCommandEvent& event);
	// Edit>Redo
	void OnRedo(wxCommandEvent& event);
    // Update Undo and Redo
    void UpdateUndoAndRedo();
	// Edit>Unselect
	void OnUnselect(wxCommandEvent& event);
	// Edit>Delete
	void OnDelete(wxCommandEvent& event);

	// Colors>Pen Color
	void OnSetPenColor(wxCommandEvent& event);
	// Colors>Pen Width
	void OnSetPenWidth(wxCommandEvent& event);
	// Colors>Brush Color
	void OnSetBrushColor(wxCommandEvent& event);
	
	// Event when the mouse button is clicked
	void OnMouseButton(wxMouseEvent& event);
	// Event when the mouse moves (inside draw panel)
	void OnMouseMove(wxMouseEvent& event);

	// Event when selecting a drawing tool
	void OnSelectTool(wxCommandEvent& event);
	void ToggleTool(EventID toolID);

	void SetCursor(CursorType type);
	
	wxDECLARE_EVENT_TABLE();
private:
	CursorCache mCursors;

	std::shared_ptr<class PaintModel> mModel;

	// Menus
	class wxMenu* mFileMenu;
	class wxMenu* mEditMenu;
	class wxMenu* mColorMenu;
	// Toolbar
	class wxToolBar* mToolbar;
	// Panel for drawing
	class PaintDrawPanel* mPanel;

	EventID mCurrentTool;
};
