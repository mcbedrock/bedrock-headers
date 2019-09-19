#pragma once

#include "Packet.h"

struct UpdateBlockPacket : Packet {
	BlockPos pos;
	ActorRuntimeID bid;

#include "VirtualTemplate.h"
};