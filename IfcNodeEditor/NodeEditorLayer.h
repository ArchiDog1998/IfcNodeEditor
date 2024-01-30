#pragma once
#include "Walnut/Application.h"
#include "imgui_node_editor.h"

namespace ed = ax::NodeEditor;

class NodeEditorLayer : public Walnut::Layer
{
public:
	void OnAttach() override;
	void OnDetach() override;
	void OnUIRender() override;
private:
	ed::EditorContext* m_Context = nullptr;
};

