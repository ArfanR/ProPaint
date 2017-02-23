#include "Shape.h"

Shape::Shape(const wxPoint& start)
	:mStartPoint(start)
	,mEndPoint(start)
	,mTopLeft(start)
	,mBotRight(start)
{
    mOffset.x = 0;
    mOffset.y = 0;
}

// Tests whether the provided point intersects
// with this shape
bool Shape::Intersects(const wxPoint& point) const
{
	wxPoint topleft;
	wxPoint botright;
	GetBounds(topleft, botright);
	if (point.x >= topleft.x && point.x <= botright.x &&
		point.y >= topleft.y && point.y <= botright.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Update shape with new provided point
void Shape::Update(const wxPoint& newPoint)
{
	mEndPoint = newPoint;

	// For most shapes, we only have two points - start and end
	// So we can figure out the top left/bottom right bounds
	// based on this.
	mTopLeft.x = std::min(mStartPoint.x, mEndPoint.x);
	mTopLeft.y = std::min(mStartPoint.y, mEndPoint.y);
	mBotRight.x = std::max(mStartPoint.x, mEndPoint.x);
	mBotRight.y = std::max(mStartPoint.y, mEndPoint.y);
}

void Shape::Finalize()
{
	// Default finalize doesn't do anything
}

void Shape::GetBounds(wxPoint& topLeft, wxPoint& botRight) const
{
	topLeft = mTopLeft + mOffset;
	botRight = mBotRight + mOffset;
}

void Shape::SetPen(const wxPen& pen)
{
    mPen = pen;
}

wxPen Shape::GetPen() const
{
    return mPen;
}

void Shape::SetBrush(const wxBrush& brush)
{
    mBrush = brush;
}

wxBrush Shape::GetBrush() const
{
    return mBrush;
}

void Shape::DrawSelection(wxDC& dc)
{
    dc.SetPen(*wxBLACK_DASHED_PEN);
    dc.SetBrush(*wxTRANSPARENT_BRUSH);
    wxPoint mTop, mBot;
    mTop = mTop + mOffset;
    mBot = mBot + mOffset;
    mTop.x = mTopLeft.x - 1;
    mTop.y = mTopLeft.y + 1;
    mBot.x = mBotRight.x + 1;
    mBot.y = mBotRight.y - 1;
    dc.DrawRectangle(wxRect(mTop, mBot));
}

wxPoint Shape::GetOffset() const
{
    return mOffset;
}

void Shape::SetOffset(const wxPoint& offset)
{
    mOffset = offset;
}
