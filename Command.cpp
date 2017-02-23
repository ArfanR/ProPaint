#include "Command.h"
#include "DrawCommand.hpp"
#include "Shape.h"
#include "RectShape.hpp"
#include "EllipseShape.hpp"
#include "LineShape.hpp"
#include "PencilShape.hpp"
#include "SetPenCommand.hpp"
#include "SetBrushCommand.hpp"
#include "DeleteCommand.hpp"
#include "MoveCommand.hpp"
#include "PaintModel.h"

Command::Command(const wxPoint& start, std::shared_ptr<Shape> shape)
	:mStartPoint(start)
	,mEndPoint(start)
	,mShape(shape)
{

}

// Called when the command is still updating (such as in the process of drawing)
void Command::Update(const wxPoint& newPoint)
{
	mEndPoint = newPoint;
}

std::shared_ptr<Command> CommandFactory::Create(std::shared_ptr<PaintModel> model,
	CommandType type, const wxPoint& start)
{
	std::shared_ptr<Command> retVal;
    std::shared_ptr<Shape> shape;
    // make command for each shape
    if (type == CM_DrawRect)
    {
        shape = std::make_shared<RectShape>(start);
    }
    else if (type == CM_DrawEllipse)
    {
        shape = std::make_shared<EllipseShape>(start);
    }
    else if (type == CM_DrawLine)
    {
        shape = std::make_shared<LineShape>(start);
    }
    else if (type == CM_DrawPencil)
    {
        shape = std::make_shared<PencilShape>(start);
    }
    else if (type == CM_SetPen)
    {
        if (model->HasSelection())
        {
            shape = model->GetSelectedShape();
            retVal = std::make_shared<SetPenCommand>(start, shape);
            return retVal;
        }
    }
    else if (type == CM_SetBrush)
    {
        if (model->HasSelection())
        {
            shape = model->GetSelectedShape();
            retVal = std::make_shared<SetBrushCommand>(start, shape);
            return retVal;
        }
    }
    else if (type == CM_Delete)
    {
        if (model->HasSelection())
        {
            shape = model->GetSelectedShape();
            retVal = std::make_shared<DeleteCommand>(start, shape);
            return retVal;
        }
    }
    else if (type == CM_Move)
    {
        if (model->HasSelection())
        {
            shape = model->GetSelectedShape();
            retVal = std::make_shared<MoveCommand>(start, shape);
            return retVal;
        }
    }
    // Make the shape based on the command type
    shape->SetBrush(model->GetBrush());
    shape->SetPen(model->GetPen());
    model->AddShape(shape);
    retVal = std::make_shared<DrawCommand>(start, shape);
	return retVal;
}
