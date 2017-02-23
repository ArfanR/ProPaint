//
//  DeleteCommand.cpp
//  paint-mac
//
//  Created by Arfan Rehab on 2/22/17.
//  Copyright © 2017 Sanjay Madhav. All rights reserved.
//

#include "DeleteCommand.hpp"
#include "PaintModel.h"

DeleteCommand::DeleteCommand(const wxPoint& start, std::shared_ptr<Shape> shape): Command(start, shape) {};

void DeleteCommand::Update(const wxPoint& newPoint)
{
    
}

void DeleteCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    model->RemoveShape(model->GetSelectedShape());
}

void DeleteCommand::Undo(std::shared_ptr<PaintModel> model)
{
    model->AddShape(mShape);
}

void DeleteCommand::Redo(std::shared_ptr<PaintModel> model)
{
    model->RemoveShape(mShape);
}
