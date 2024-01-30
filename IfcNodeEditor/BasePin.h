#pragma once
#include "imgui_node_editor.h"
#include <string>
#include <vector>

namespace ed = ax::NodeEditor;

enum class PinType
{
    Flow,
    Bool,
    Int,
    Float,
    String,
    Object,
    Function,
    Delegate,
};

class BasePin
{
public:
	std::string Name;
	ed::PinId ID;

    PinType Type;
    ed::PinKind Kind;

	void OnUIRender();

protected:
	virtual void Draw();

private:
	void* PersistentData;
};