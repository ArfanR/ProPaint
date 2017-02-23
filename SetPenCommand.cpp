//
//  SetPenCommand.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/21/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "SetPenCommand.hpp"
#include "PaintModel.h"


SetPenCommand::SetPenCommand(const wxPoint& start, std::shared_ptr<Shape> shape): Command(start, shape) {};

void SetPenCommand::Update(const wxPoint& newPoint)
{

}

void SetPenCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    mPen = mShape->GetPen();
    model->GetSelectedShape()->SetPen(model->GetPen());
}

void SetPenCommand::Undo(std::shared_ptr<PaintModel> model)
{
    wxPen oldPen = mShape->GetPen();
    mShape->SetPen(mPen);
    mPen = oldPen;
}

void SetPenCommand::Redo(std::shared_ptr<PaintModel> model)
{
    wxPen oldPen = mShape->GetPen();
    mShape->SetPen(mPen);
    mPen = oldPen;
}
