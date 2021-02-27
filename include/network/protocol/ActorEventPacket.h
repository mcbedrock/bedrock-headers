#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

struct ActorEventPacket : Packet {
	ActorRuntimeID eid;
	unsigned char event;
	char pad_001C[3];
	int data;

	ActorEventPacket(ActorRuntimeID eid, unsigned char event, int data) : eid(eid), event(event), data(data), pad_001C{0} {}

#include "VirtualTemplate.h"
};

static_assert(offsetof(ActorEventPacket, eid) == 0x28);
static_assert(offsetof(ActorEventPacket, event) == 0x30);
static_assert(offsetof(ActorEventPacket, data) == 0x34);