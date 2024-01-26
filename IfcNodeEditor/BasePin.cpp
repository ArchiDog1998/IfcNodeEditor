#include "BasePin.h"

void BasePin::OnUIRender()
{
	ed::BeginPin(ID, Kind);
	Draw();
	ed::EndPin();
}

void BasePin::Draw()
{
	ImGui::Text(Name.c_str());
}