#pragma once

#include "Packet.h"

struct LevelEventPacket : Packet {
	int event;
	Vec3 pos;
	int data;

#include "VirtualTemplate.h"
};

static_assert(offsetof(LevelEventPacket, event) == 0x24);