#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

struct ActorEventPacket : Packet {
	ActorRuntimeID eid;
	unsigned char event;
	char pad_001C[3];
	int data;

#include "VirtualTemplate.h"
};

static_assert(offsetof(ActorEventPacket, event) == 0x1C);
