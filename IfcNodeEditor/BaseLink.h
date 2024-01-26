#pragma once
#include "imgui_node_editor.h"
#include <string>
#include <vector>

namespace ed = ax::NodeEditor;

class BaseLink
{
public:
    ed::LinkId ID;

    ed::PinId StartPinID;
    ed::PinId EndPinID;

    ImColor Color;

    BaseLink(ed::LinkId id, ed::PinId startPinId, ed::PinId endPinId);
};

