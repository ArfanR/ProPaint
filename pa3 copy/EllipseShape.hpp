//
//  EllipseShape.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef EllipseShape_hpp
#define EllipseShape_hpp

#include <stdio.h>
#include "Shape.h"

class EllipseShape : public Shape
{
public:
    EllipseShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
    
};

#endif /* EllipseShape_hpp */
