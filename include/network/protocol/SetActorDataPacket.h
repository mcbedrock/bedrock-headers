#pragma once

#include "util/DataItem.h"
#include "Packet.h"
#include <vector>

struct SetActorDataPacket : Packet {
	ActorRuntimeID rid;

	std::vector<std::unique_ptr<DataItem>> entries;

#include "VirtualTemplate.h"
};