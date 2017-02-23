//
//  LineShape.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef LineShape_hpp
#define LineShape_hpp

#include <stdio.h>
#include "Shape.h"

class LineShape : public Shape
{
public:
    LineShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
    
};
#endif /* LineShape_hpp */
