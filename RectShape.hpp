//
//  RectShape.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/20/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef RectShape_hpp
#define RectShape_hpp

#include "Shape.h"
#include <stdio.h>


class RectShape : public Shape
{
public:
    RectShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
    
};
#endif /* RectShape_hpp */
