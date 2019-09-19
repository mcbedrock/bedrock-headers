#pragma once

#include <util/DataItem.h>
#include "Packet.h"

struct SetActorDataPacket : Packet {
	ActorRuntimeID rid;

	std::vector<std::unique_ptr<DataItem>> entries;

#include "VirtualTemplate.h"
};