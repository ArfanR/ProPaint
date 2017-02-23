#include "Cursors.h"

CursorCache::CursorCache()
{
	// Populate cursor cache
	mMap.emplace(CU_Default, new wxCursor(wxCURSOR_ARROW));
	mMap.emplace(CU_Cross, new wxCursor(wxCURSOR_CROSS));
	mMap.emplace(CU_Pencil, new wxCursor(wxCURSOR_PENCIL));
	mMap.emplace(CU_Move, new wxCursor(wxCURSOR_SIZING));
	mMap.emplace(CU_SizeNS, new wxCursor(wxCURSOR_SIZENS));
	mMap.emplace(CU_SizeEW, new wxCursor(wxCURSOR_SIZEWE));
	mMap.emplace(CU_SizeNWSE, new wxCursor(wxCURSOR_SIZENWSE));
}

CursorCache::~CursorCache()
{
	for (auto& iter : mMap)
	{
		delete iter.second;
	}
}

wxCursor* CursorCache::GetCursor(CursorType type)
{
	auto iter = mMap.find(type);
	if (iter != mMap.end())
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}
