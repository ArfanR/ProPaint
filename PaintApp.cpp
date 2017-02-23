#include "PaintApp.h"
#include "PaintFrame.h"

wxIMPLEMENT_APP(PaintApp);

bool PaintApp::OnInit()
{
	mFrame = new PaintFrame( "ProPaint", wxPoint(50, 50), wxSize(1024, 768) );
	
	return true;
}
