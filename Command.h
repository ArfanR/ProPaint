#pragma once
#include <wx/gdicmn.h>
#include <wx/pen.h>
#include <wx/brush.h>
#include <memory>

enum CommandType
{
	CM_DrawLine,
	CM_DrawEllipse,
	CM_DrawRect,
	CM_DrawPencil,
	CM_Move,
	CM_Delete,
	CM_SetPen,
	CM_SetBrush,
};

// Forward declarations
class PaintModel;
class Shape;

// Abstract Base Command class
// All actions that change the drawing (drawing, deleting, etc., are commands)
class Command
{
public:
	Command(const wxPoint& start, std::shared_ptr<Shape> shape);
	// Called when the command is still updating (such as in the process of drawing)
	virtual void Update(const wxPoint& newPoint);
	// Called when the command is completed
	virtual void Finalize(std::shared_ptr<PaintModel> model) = 0;
	// Used to "undo" the command
	virtual void Undo(std::shared_ptr<PaintModel> model) = 0;
	// Used to "redo" the command
	virtual void Redo(std::shared_ptr<PaintModel> model) = 0;
	virtual ~Command() { }
protected:
	wxPoint mStartPoint;
	wxPoint mEndPoint;
	std::shared_ptr<Shape> mShape;
};

// Factory method to help create a particular command
struct CommandFactory
{
	static std::shared_ptr<Command> Create(std::shared_ptr<PaintModel> model,
		CommandType type, const wxPoint& start);
};
