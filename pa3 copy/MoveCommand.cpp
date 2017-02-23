//
//  MoveCommand.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/22/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "MoveCommand.hpp"
#include "PaintModel.h"

MoveCommand::MoveCommand(const wxPoint& start, std::shared_ptr<Shape> shape) : Command(start, shape)
{
    assert(mShape != nullptr);
    mOldOffSet = shape->GetOffset();
}

void MoveCommand::Update(const wxPoint& newPoint)
{
    assert(mShape != nullptr);
    mShape->SetOffset(newPoint - mStartPoint);
}

void MoveCommand::Finalize(std::shared_ptr<PaintModel> model)
{

}

void MoveCommand::Undo(std::shared_ptr<PaintModel> model)
{
    wxPoint mOldOff = mShape->GetOffset();
    mShape->SetOffset(mShape->GetOffset());
    mOldOffSet = mOldOff;
}

void  MoveCommand::Redo(std::shared_ptr<PaintModel> model)
{
    wxPoint mOldOff = mShape->GetOffset();
    mShape->SetOffset(mShape->GetOffset());
    mOldOffSet = mOldOff;
}
