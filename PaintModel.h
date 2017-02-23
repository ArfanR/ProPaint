#pragma once
#include <memory>
#include <vector>
#include <stack>
#include "Shape.h"
#include "Command.h"
#include <wx/bitmap.h>

class PaintModel : public std::enable_shared_from_this<PaintModel>
{
public:
	PaintModel();
	
	// Draws any shapes in the model to the provided DC (draw context)
	void DrawShapes(wxDC& dc, bool showSelection = true);

	// Clear the current paint model and start fresh
	void New();

	// Add a shape to the paint model
	void AddShape(std::shared_ptr<Shape> shape);
	// Remove a shape from the paint model
	void RemoveShape(std::shared_ptr<Shape> shape);
    
    // Check if there is a current command
    bool HasActiveCommand() const;
    // Create a new command to draw shapes
    void CreateCommand(CommandType type, const wxPoint& start);
    // Update the point for a current command
    void UpdateCommand(const wxPoint& newPoint);
    // Finalize the shape command
    void FinalizeCommand();
    
    // Check if undo is possible
    bool CanUndo() const;
    // Check if redo is possible
    bool CanRedo() const;
    // Undo a command
    void Undo();
    // Redo a command
    void Redo();
    
    // Set the width of the pen from 0 to 10
    void SetPenWidth(const int width);
    // Get the current pen width
    int GetPenWidth() const;
    // Set the color of the model's pen
    void SetPenColor(const wxColour& color);
    // Get the current color of the pen
    wxColour GetPenColor() const;
    // Set the color of the model's brush
    void SetBrushColor(const wxColour& color);
    // Get the current color of the model's brush
    wxColour GetBrushColor() const;
    // Get the current wxPen
    wxPen GetPen() const;
    // Get the current wxBrush
    wxBrush GetBrush() const;
    
    // Get the current selected shape
    std::shared_ptr<Shape> GetSelectedShape() const;
    // Check if point intersects with the selected shape
    bool PointSelection(const wxPoint& point);
    // Has a selected shape
    bool HasSelection() const;
    // Unselect the current shape
    void Unselect();
    
    // Set to move mode on selected shape
    void SetMoveMode(const bool moveMode);
    // Check if it is in move mode
    bool IsMoveMode() const;
    
    // Save file for exporting
    void SaveFile(const std::string& fileName, const wxSize& size);
    // Load file for importing 
    void LoadFile(const std::string& fileName);
    
private:
	// Vector of all the shapes in the model
	std::vector<std::shared_ptr<Shape>> mShapes;
    // Manage the current active command
    std::shared_ptr<Command> mActiveCommand;
    // Stack of undo commands
    std::stack<std::shared_ptr<Command>> mUndoCommands;
    // Stack of redo commands
    std::stack<std::shared_ptr<Command>> mRedoCommands;
    // Track the model's pen and brush
    wxPen mPen;
    wxBrush mBrush;
    // Track the selected shape
    std::shared_ptr<Shape> mSelectedShape;
    // Track move in selected shape
    bool mMoveMode;
    // bitmap for import and export
    wxBitmap mLoadBitMap;

};
