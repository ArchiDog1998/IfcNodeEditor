#pragma once
#include "BasePin.h"

enum class NodeType
{
    Blueprint,
    Simple,
    Tree,
    Comment,
    Houdini,
};

class BaseNode
{
public:
	std::vector<BasePin> Inputs, Outputs;
	std::string Name;
	ed::NodeId ID;
    ImColor Color;
    NodeType Type;

	virtual void OnUIRender();
};