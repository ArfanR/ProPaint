//
//  SetBrushCommand.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef SetBrushCommand_hpp
#define SetBrushCommand_hpp

#include "Command.h"
#include <stdio.h>

class SetBrushCommand : public Command
{
public:
    SetBrushCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    void Update(const wxPoint& newPoint) override;
    void Finalize(std::shared_ptr<PaintModel> model);
    void Undo(std::shared_ptr<PaintModel> model);
    void Redo(std::shared_ptr<PaintModel> model);
private:
    wxBrush mBrush;
};

#endif /* SetBrushCommand_hpp */
