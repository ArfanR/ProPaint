#pragma once
#include <wx/app.h>

class PaintApp : public wxApp
{
public:
	virtual bool OnInit();
private:
	class PaintFrame* mFrame;
};
