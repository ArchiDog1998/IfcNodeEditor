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
			input.OnUIRender(ed::PinKind::Input);
		}
		ImGui::EndGroup();
	}

	// Outputs.
	{ 
		ImGui::BeginGroup();
		for (auto& output : Outputs)
		{
			output.OnUIRender(ed::PinKind::Output);
		}
		ImGui::EndGroup();
	}

	ed::EndNode();
}