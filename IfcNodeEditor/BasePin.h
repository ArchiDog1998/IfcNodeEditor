#pragma once
#include "imgui_node_editor.h"
#include <string>

namespace ed = ax::NodeEditor;

class BasePin
{
public:
	std::string Name;
	ed::PinId ID;

	void* PersistentData;
	template <typename T>
	bool SetPersistentData(T data)
	{

	}

	void OnUIRender(ed::PinKind kind);

protected:
	virtual void Draw();
};

