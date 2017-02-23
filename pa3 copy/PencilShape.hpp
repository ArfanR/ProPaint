//
//  PencilShape.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef PencilShape_hpp
#define PencilShape_hpp

#include <stdio.h>
#include "Shape.h"

class PencilShape : public Shape
{
public:
    PencilShape(const wxPoint& start);
    void Update(const wxPoint& newPoint) override;
    void Finalize() override;
    void Draw(wxDC& dc) const override;
    
private:
    std::vector<wxPoint> mPoints;
};

#endif /* PencilShape_hpp */
