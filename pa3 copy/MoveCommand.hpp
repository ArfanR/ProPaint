//
//  MoveCommand.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/22/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef MoveCommand_hpp
#define MoveCommand_hpp

#include <stdio.h>
#include "Command.h"

class MoveCommand : public Command
{
public:
    MoveCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    void Update(const wxPoint& newPoint) override;
    void Finalize(std::shared_ptr<PaintModel> model);
    void Undo(std::shared_ptr<PaintModel> model);
    void Redo(std::shared_ptr<PaintModel> model);
private:
    wxPoint mOldOffSet;
};

#endif /* MoveCommand_hpp */
