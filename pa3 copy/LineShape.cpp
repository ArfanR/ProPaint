//
//  LineShape.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "LineShape.hpp"

LineShape::LineShape(const wxPoint& start): Shape(start) {};

void LineShape::Draw(wxDC& dc) const
{
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    dc.DrawLine(mStartPoint + mOffset, mEndPoint + mOffset);
}

