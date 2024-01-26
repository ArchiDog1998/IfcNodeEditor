#include "BaseLink.h"

BaseLink::BaseLink(ed::LinkId id, ed::PinId startPinId, ed::PinId endPinId)
: ID(id), StartPinID(startPinId), EndPinID(endPinId), Color(255, 255, 255)
{
}