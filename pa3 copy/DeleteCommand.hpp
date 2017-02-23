//
//  DeleteCommand.hpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/22/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#ifndef DeleteCommand_hpp
#define DeleteCommand_hpp

#include "Command.h"
#include <stdio.h>

class DeleteCommand : public Command
{
public:
    DeleteCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    void Update(const wxPoint& newPoint) override;
    void Finalize(std::shared_ptr<PaintModel> model);
    void Undo(std::shared_ptr<PaintModel> model);
    void Redo(std::shared_ptr<PaintModel> model);
};

#endif /* DeleteCommand_hpp */
