#pragma once

#include "Packet.h"

struct RemoveActorPacket : Packet {
	ActorUniqueID uid;

#include "VirtualTemplate.h"
};