//
//  EllipseShape.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "EllipseShape.hpp"

EllipseShape::EllipseShape(const wxPoint& start): Shape(start) {};

void EllipseShape::Draw(wxDC& dc) const
{
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    dc.DrawEllipse(wxRect(mTopLeft + mOffset, mBotRight + mOffset));
}

