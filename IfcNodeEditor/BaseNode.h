#pragma once
#include "BasePin.h"
#include <vector>
#include <string>

class BaseNode
{
public:
	std::vector<BasePin> Inputs, Outputs;
	std::string Name;
	ed::NodeId ID;

	virtual void OnUIRender();
};

