#include "PaintDrawPanel.h"
#include <wx/dcclient.h>
#include <wx/sizer.h>
#include <wx/dcbuffer.h>
#include "PaintModel.h"

BEGIN_EVENT_TABLE(PaintDrawPanel, wxPanel)
	EVT_PAINT(PaintDrawPanel::PaintEvent)
END_EVENT_TABLE()


PaintDrawPanel::PaintDrawPanel(wxFrame* parent)
: wxPanel(parent)
{
	
}

void PaintDrawPanel::PaintEvent(wxPaintEvent & evt)
{
	wxBufferedPaintDC dc(this, mBitmap);
	Render(dc);
}

void PaintDrawPanel::PaintNow()
{
	wxClientDC dc(this);
	wxBufferedDC bdc(&dc, mBitmap);
	Render(bdc);
}

void PaintDrawPanel::Render(wxDC& dc)
{
	// Clear
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();
	
	if (mModel)
	{
		mModel->DrawShapes(dc);
	}
}

void PaintDrawPanel::SetModel(std::shared_ptr<class PaintModel> model)
{
	mModel = model;
}

void PaintDrawPanel::SetupBitmap()
{
	mBitmap.Create(GetSize());
}
