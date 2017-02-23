//
//  SetBrushCommand.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "SetBrushCommand.hpp"
#include "PaintModel.h"

SetBrushCommand::SetBrushCommand(const wxPoint& start, std::shared_ptr<Shape> shape): Command(start, shape) {};

void SetBrushCommand::Update(const wxPoint& newPoint)
{

}

void SetBrushCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    mBrush = mShape->GetBrush();
    model->GetSelectedShape()->SetBrush(model->GetBrush());
}

void SetBrushCommand::Undo(std::shared_ptr<PaintModel> model)
{
    wxBrush oldBrush = mShape->GetBrush();
    mShape->SetBrush(mBrush);
    mBrush = oldBrush;
}

void SetBrushCommand::Redo(std::shared_ptr<PaintModel> model)
{
    wxBrush oldBrush = mShape->GetBrush();
    mShape->SetBrush(mBrush);
    mBrush = oldBrush;
}
