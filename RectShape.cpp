//
//  RectShape.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/20/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "RectShape.hpp"

RectShape::RectShape(const wxPoint& start): Shape(start) {};

void RectShape::Draw(wxDC& dc) const
{
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    dc.DrawRectangle(wxRect(mTopLeft + mOffset, mBotRight + mOffset));
}
