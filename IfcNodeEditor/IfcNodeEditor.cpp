#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"

#include "Walnut/Image.h"
#include "Walnut/UI/UI.h"
#include "imgui_node_editor.h"
#include "NodeEditorLayer.h"

Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Ifc Node Editor";
	spec.CustomTitlebar = true;
	spec.CenterWindow = true;

	Walnut::Application* app = new Walnut::Application(spec);
	std::shared_ptr<NodeEditorLayer> nodeEditorLayer = std::make_shared<NodeEditorLayer>();
	app->PushLayer(nodeEditorLayer);

	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			ImGui::EndMenu();
		}
	});
	return app;
}