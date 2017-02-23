//
//  SetPenCommand.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef SetPenCommand_hpp
#define SetPenCommand_hpp

#include "Command.h"
#include <stdio.h>

class SetPenCommand : public Command
{
public:
    SetPenCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    void Update(const wxPoint& newPoint) override;
    void Finalize(std::shared_ptr<PaintModel> model);
    void Undo(std::shared_ptr<PaintModel> model);
    void Redo(std::shared_ptr<PaintModel> model);
private:
    wxPen mPen;
};

#endif /* SetPenCommand_hpp */
