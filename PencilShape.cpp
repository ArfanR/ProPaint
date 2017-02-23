//
//  PencilShape.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "PencilShape.hpp"
#include "Shape.h"

PencilShape::PencilShape(const wxPoint& start): Shape(start)
{
    mPoints.emplace_back(start);
}

void PencilShape::Update(const wxPoint& newPoint)
{
    Shape::Update(newPoint);
    mPoints.emplace_back(newPoint);
}

void PencilShape::Finalize()
{
    int mMinX = mStartPoint.x;
    int mMinY = mStartPoint.y;
    int mMaxX = mStartPoint.x;
    int mMaxY = mStartPoint.y;
    // loop through each point
    for (const auto& i: mPoints)
    {
        // look for min and max x values
        if (i.x < mMinX)
        {
            mMinX = i.x;
        }
        else if (i.x > mMaxX)
        {
            mMaxX = i.x;
        }
        // look for min and max y values
        if (i.y < mMinY)
        {
            mMinY = i.y;
        }
        else if (i.y > mMaxY)
        {
            mMaxY = i.y;
        }
    }
    // assign top left and bottom right coordinates
    mTopLeft.x = mMinX;
    mTopLeft.y = mMinY;
    mBotRight.x = mMaxX;
    mBotRight.y = mMaxY;
}

void PencilShape::Draw(wxDC& dc) const
{
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    
    if (mPoints.size() == 1)
    {
        dc.DrawPoint(mPoints.front() + mOffset);
    }
    else
    {
        dc.DrawLines(static_cast<int>(mPoints.size()), mPoints.data(), mOffset.x, mOffset.y);
    }
}





