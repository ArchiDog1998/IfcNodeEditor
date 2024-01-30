#include "NodeEditorLayer.h"
#include "BaseNode.h"

void NodeEditorLayer::OnAttach()
{
	ed::Config config;
	config.SettingsFile = "Simple.json";
	_context = ed::CreateEditor(&config);
}

void NodeEditorLayer::OnDetach() 
{
	ed::DestroyEditor(_context);
}

void NodeEditorLayer::OnUIRender()
{
	ImGui::SetNextWindowDockID(ImGui::GetWindowDockID(), ImGuiCond_FirstUseEver);
	ImGui::Begin("Node Editor");
	ed::SetCurrentEditor(_context);

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