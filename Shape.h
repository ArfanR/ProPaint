#pragma once
#include <wx/dc.h>

// Abstract base class for all Shapes
class Shape
{
public:
	Shape(const wxPoint& start);
	// Tests whether the provided point intersects
	// with this shape
	bool Intersects(const wxPoint& point) const;
	// Update shape with new provided point
	virtual void Update(const wxPoint& newPoint);
	// Finalize the shape -- when the user has finished drawing the shape
	virtual void Finalize();
	// Returns the top left/bottom right points of the shape
	void GetBounds(wxPoint& topLeft, wxPoint& botRight) const;
    
    // Set the current shapes' pen
    void SetPen(const wxPen& pen);
    // Get the current shapes pen
    wxPen GetPen() const;
    // Set the current brush
    void SetBrush(const wxBrush& brush);
    // Get the current brush
    wxBrush GetBrush() const;
    // Set the offset value for move command
    void SetOffset(const wxPoint& offset);
    // Get the offset value for move command
    wxPoint GetOffset() const;
    
    // Draw around the current selected shape
    void DrawSelection(wxDC& dc);
    
	// Draw the shape
	virtual void Draw(wxDC& dc) const = 0;
	virtual ~Shape() { }	
protected:
	// Starting point of shape
	wxPoint mStartPoint;
	// Ending point of shape
	wxPoint mEndPoint;
	// Top left point of shape
	wxPoint mTopLeft;
	// Bottom right point of shape
	wxPoint mBotRight;

    wxPen mPen;
    wxBrush mBrush;
    wxPoint mOffset;
};
