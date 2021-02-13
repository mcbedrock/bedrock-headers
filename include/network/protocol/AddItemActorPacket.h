#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

struct AddItemActorPacket : Packet {
	char pad_0014[0x10]; // TODO: Synched actor data
	ActorUniqueID uid; // 0x24
	ActorRuntimeID eid; // 0x2c
	ItemStack *stack; // 0x34
	char pad_003C[0x4C];
	Vec3 pos; // 0x84
	Vec3 motion; // 0x90

#include "VirtualTemplate.h"
};

//static_assert(offsetof(AddItemActorPacket, motion) == 0x90);