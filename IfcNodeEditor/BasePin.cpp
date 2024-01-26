#include "BasePin.h"

void BasePin::OnUIRender(ed::PinKind kind)
{
	ed::BeginPin(ID, kind);
	Draw();
	ed::EndPin();
}

void BasePin::Draw()
{
	ImGui::Text(Name.c_str());
}