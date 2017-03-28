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
    int minX = mStartPoint.x;
    int minY = mStartPoint.y;
    int maxX = mStartPoint.x;
    int maxY = mStartPoint.y;
    // loop through each point
    for (const auto& i: mPoints)
    {
        // look for min and max x values
        if (i.x < minX)
        {
            minX = i.x;
        }
        else if (i.x > maxX)
        {
            maxX = i.x;
        }
        // look for min and max y values
        if (i.y < minY)
        {
            minY = i.y;
        }
        else if (i.y > maxY)
        {
            maxY = i.y;
        }
    }
    // assign top left and bottom right coordinates
    mTopLeft.x = minX;
    mTopLeft.y = minY;
    mBotRight.x = maxX;
    mBotRight.y = maxY;
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





