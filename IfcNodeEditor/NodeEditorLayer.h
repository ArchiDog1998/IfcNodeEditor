#pragma once
#include "Walnut/Application.h"
#include "imgui_node_editor.h"

namespace ed = ax::NodeEditor;

class NodeEditorLayer : public Walnut::Layer
{
public:
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUIRender() override;
private:
	ed::EditorContext* m_Context = nullptr;
};

