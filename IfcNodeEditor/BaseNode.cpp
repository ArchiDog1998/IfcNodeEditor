#include "BaseNode.h"
void BaseNode::OnUIRender() 
{
	ed::BeginNode(ID);
	ImGui::PushID(ID.AsPointer());

	//Header
	ImGui::BeginGroup();
	ImGui::Text(Name.c_str());
	ImGui::EndGroup();

	const auto headerMin = ImGui::GetItemRectMin();
	const auto headerMax = ImGui::GetItemRectMax();

	// spacing between header and content
	ImGui::Spacing();

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

	ImGui::PopID();
	ed::EndNode();

	if (ImGui::IsItemVisible()) // Header background.
	{
		const auto drawList = ed::GetNodeBackgroundDrawList(ID);
		const auto& style = ed::GetStyle();
		const auto halfBorderWidth = style.NodeBorderWidth * 0.5f;

		const auto alpha = static_cast<int>(255 * ImGui::GetStyle().Alpha);

		if ((headerMax.x > headerMin.x) && (headerMax.y > headerMin.y))
		{
			drawList->AddRectFilled(ImVec2(headerMin.x - style.NodePadding.x + halfBorderWidth,
				headerMin.y - style.NodePadding.y + halfBorderWidth),
				  ImVec2(headerMax.x + style.NodePadding.z - halfBorderWidth, headerMax.y + 4), IM_COL32(128, 64, 64, 255), style.NodeRounding, ImDrawFlags_RoundCornersTop);
		}
	}
}