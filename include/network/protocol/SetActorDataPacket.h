#pragma once

#include "util/DataItem.h"
#include "Packet.h"
#include <vector>

struct SetActorDataPacket : Packet {
	ActorRuntimeID rid;
	char pad[0x8];
	std::vector<DataItem *> entries;

#include "VirtualTemplate.h"
};

static_assert(offsetof(SetActorDataPacket, rid) == 0x28);
static_assert(offsetof(SetActorDataPacket, entries) == 0x38);