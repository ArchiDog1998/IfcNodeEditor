#include "BaseNode.h"

void BaseNode::OnUIRender() 
{
	ed::BeginNode(ID);

	ImGui::Text(Name.c_str());

	// Inputs.
	{ 
		ImGui::BeginGroup();
		for (auto& input : Inputs)
		{
			input.OnUIRender();
		}
		ImGui::EndGroup();
	}

	// Outputs.
	{ 
		ImGui::BeginGroup();
		for (auto& output : Outputs)
		{
			output.OnUIRender();
		}
		ImGui::EndGroup();
	}

	ed::EndNode();
}