#pragma once
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/bitmap.h>
#include <string>
#include <memory>

class PaintDrawPanel : public wxPanel
{
public:
	PaintDrawPanel(wxFrame* parent);
 
	void PaintEvent(wxPaintEvent & evt);
	void PaintNow();
 
	void Render(wxDC& dc);

	void SetModel(std::shared_ptr<class PaintModel> model);
	void SetupBitmap();
	
	DECLARE_EVENT_TABLE()
	
public:
	// Buffer that stores current drawing as bitmap
	wxBitmap mBitmap;
	// Variables here
	std::shared_ptr<class PaintModel> mModel;
};

