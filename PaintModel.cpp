#include "PaintModel.h"
#include <algorithm>
#include <wx/dcmemory.h>

PaintModel::PaintModel()
{
    mActiveCommand = nullptr;
    mPen = *wxBLACK_PEN;
    mBrush = *wxWHITE_BRUSH;
    mSelectedShape = nullptr;
}

// Draws any shapes in the model to the provided DC (draw context)
void PaintModel::DrawShapes(wxDC& dc, bool showSelection)
{
    if (mLoadBitMap.IsOk())
    {
        dc.DrawBitmap(mLoadBitMap,0,0);
    }
    
    for (const auto& i: mShapes)
    {
        i->Draw(dc);
        if (HasSelection())
        {
            mSelectedShape->DrawSelection(dc);
        }
    }
}

// Clear the current paint model and start fresh
void PaintModel::New()
{
    mActiveCommand.reset();
    mShapes.clear();
    
    while (!mUndoCommands.empty())
    {
        mUndoCommands.pop();
    }
    while (!mRedoCommands.empty())
    {
        mRedoCommands.pop();
    }
    
    mPen = *wxBLACK_PEN;
    mBrush = *wxWHITE_BRUSH;
    mSelectedShape = nullptr;
    mLoadBitMap = wxBitmap();
}

// Add a shape to the paint model
void PaintModel::AddShape(std::shared_ptr<Shape> shape)
{
	mShapes.emplace_back(shape);
}

// Remove a shape from the paint model
void PaintModel::RemoveShape(std::shared_ptr<Shape> shape)
{
	auto iter = std::find(mShapes.begin(), mShapes.end(), shape);
	if (iter != mShapes.end())
	{
		mShapes.erase(iter);
	}
}

bool PaintModel::HasActiveCommand() const
{
    return (mActiveCommand != nullptr);
}

void PaintModel::CreateCommand(CommandType type, const wxPoint& start)
{
    mActiveCommand = CommandFactory::Create(shared_from_this(), type, start);
}

void PaintModel::UpdateCommand(const wxPoint& newPoint)
{
    mActiveCommand->Update(newPoint);
}

void PaintModel::FinalizeCommand()
{
    mActiveCommand->Finalize(shared_from_this());
    mUndoCommands.push(mActiveCommand);
    mActiveCommand.reset();
    // make sure redo stack is cleared
    while (!mRedoCommands.empty())
    {
        mRedoCommands.pop();
    }
}

bool PaintModel::CanUndo() const
{
    return !mUndoCommands.empty();
}

bool PaintModel::CanRedo() const
{
    return !mRedoCommands.empty();
}

void PaintModel::Undo()
{
    std::shared_ptr<Command> mCurrCommand = mUndoCommands.top();
    mCurrCommand->Undo(shared_from_this());
    mUndoCommands.pop();
    mRedoCommands.push(mCurrCommand);
}

void PaintModel::Redo()
{
    std::shared_ptr<Command> mCurrCommand = mRedoCommands.top();
    mCurrCommand->Redo(shared_from_this());
    mRedoCommands.pop();
    mUndoCommands.push(mCurrCommand);
}

void PaintModel::SetPenWidth(const int width)
{
    mPen.SetWidth(width);
}

int PaintModel::GetPenWidth() const
{
    return mPen.GetWidth();
}

void PaintModel::SetPenColor(const wxColour& color)
{
    mPen.SetColour(color);
}

wxColour PaintModel::GetPenColor() const
{
    return mPen.GetColour();
}

void PaintModel::SetBrushColor(const wxColour& color)
{
    mBrush.SetColour(color);
}

wxColour PaintModel::GetBrushColor() const
{
    return mBrush.GetColour();
}

wxPen PaintModel::GetPen() const
{
    return mPen;
}

wxBrush PaintModel::GetBrush() const
{
    return mBrush;
}

bool PaintModel::HasSelection() const
{
    return mSelectedShape != nullptr;
}

void PaintModel::Unselect()
{
    mSelectedShape = nullptr;
}

std::shared_ptr<Shape> PaintModel::GetSelectedShape() const
{
    return mSelectedShape;
}

bool PaintModel::PointSelection(const wxPoint& point)
{
    int i = static_cast<int>(mShapes.size()-1);
    
    while (i >= 0)
    {
        if (mShapes[i]->Intersects(point))
        {
            mSelectedShape = mShapes[i];
            return true;
        }
        i--;
    }
    
    mSelectedShape = nullptr;
    return false;
}

void PaintModel::SetMoveMode(const bool moveMode)
{
    mMoveMode = moveMode;
}

bool PaintModel::IsMoveMode() const
{
    return mMoveMode;
}

void PaintModel::SaveFile(const std::string& fileName, const wxSize& size)
{
    std::string extension = fileName.substr(fileName.find('.'));
    // Determine the correct wxBitmapType to save to
    wxBitmapType type;
    if (extension == ".jpg" || extension == ".jpeg")
    {
        type = wxBITMAP_TYPE_JPEG;
    }
    else if (extension == ".bmp")
    {
        type = wxBITMAP_TYPE_BMP;
    }
    else if (extension == ".png")
    {
        type = wxBITMAP_TYPE_PNG;
    }
    else
    {
        return;
    }
    
    wxBitmap bitmap;
    // Create the bitmap of the specified wxSize
    bitmap.Create(size);
    // Create a memory DC to draw to the bitmap
    wxMemoryDC dc(bitmap);
    // Clear the background color
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    // Draw all the shapes (make sure not the selection!)
    Unselect();
    DrawShapes(dc);
    // Write the bitmap with the specified file name and wxBitmapType
    bitmap.SaveFile(wxString(fileName), type);
}

void PaintModel::LoadFile(const std::string& fileName)
{
    // clear everything 
    New();
    
    std::string extension = fileName.substr(fileName.find('.'));
    // Determine the correct wxBitmapType to save to
    wxBitmapType type;
    if (extension == ".jpg" || extension == ".jpeg")
    {
        type = wxBITMAP_TYPE_JPEG;
    }
    else if (extension == ".bmp")
    {
        type = wxBITMAP_TYPE_BMP;
    }
    else if (extension == ".png")
    {
        type = wxBITMAP_TYPE_PNG;
    }
    else
    {
        return;
    }
    // load file
    mLoadBitMap.LoadFile(fileName, type);
    wxMemoryDC dc(mLoadBitMap);
    // draw all shapes
    if (mLoadBitMap.IsOk())
    {
        DrawShapes(dc);
    }
    
}


