#include "NodeEditorLayer.h"
#include "BaseNode.h"

void NodeEditorLayer::OnAttach()
{
	ed::Config config;
	config.SettingsFile = "Simple.json";
	m_Context = ed::CreateEditor(&config);
}

void NodeEditorLayer::OnDetach() 
{
	ed::DestroyEditor(m_Context);
}

void NodeEditorLayer::OnUIRender()
{
	ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_FirstUseEver);
	ImGui::Begin("Node Editor");
	ed::SetCurrentEditor(m_Context);
	ed::Begin("My Editor", ImVec2(0.0, 0.0f));
	int uniqueId = 1;
	// Start drawing nodes.

	BaseNode node;
	node.ID = uniqueId++;
	node.Name = "Some Node";

	BasePin inputPin;
	inputPin.ID = uniqueId++;
	inputPin.Name = "Input";
	node.Inputs.push_back(inputPin);

	node.OnUIRender();

	ed::End();
	ed::SetCurrentEditor(nullptr);

	ImGui::End();
}