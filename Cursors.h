#pragma once
#include <unordered_map>
#include "wx/cursor.h"

enum CursorType
{
	CU_Default,
	CU_Cross,
	CU_Pencil,
	CU_Move,
	CU_SizeNS,
	CU_SizeEW,
	CU_SizeNWSE,
};

class CursorCache
{
public:
	CursorCache();
	~CursorCache();
	
	wxCursor* GetCursor(CursorType type);

	// Disallow copy/assignment
	CursorCache(const CursorCache&) = delete;
	CursorCache& operator=(const CursorCache&) = delete;
private:
	std::unordered_map<int, wxCursor*> mMap;
};