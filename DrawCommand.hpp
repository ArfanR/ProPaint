//
//  DrawCommand.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/20/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef DrawCommand_hpp
#define DrawCommand_hpp

#include "Command.h"
#include <stdio.h>

class DrawCommand : public Command
{
public:
    DrawCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    void Update(const wxPoint& newPoint) override;
    void Finalize(std::shared_ptr<PaintModel> model);
    void Undo(std::shared_ptr<PaintModel> model);
    void Redo(std::shared_ptr<PaintModel> model);
};

#endif /* DrawCommand_hpp */
