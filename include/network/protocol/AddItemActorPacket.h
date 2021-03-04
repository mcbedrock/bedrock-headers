#pragma once

#include "util/DataItem.h"
#include "util/ActorRuntimeID.h"
#include "item/Item.h"
#include "Packet.h"
#include <vector>

struct AddItemActorPacket : Packet {
	char pad_0024[0x20]; // TODO: Synched actor data(?)
	ActorUniqueID uid; // 0x48
	ActorRuntimeID eid; // 0x50
	ItemStack stack; // 0x58
	char stackpad[0x8]; // cause I probably am missing fields in ItemStackBase or this is some other random ptr
	//char pad_0060[0x8]; // Item meta?
	/*std::vector<DataItem *> meta;
	char pad[0x70];*/
	Vec3 pos; // 0x84
	Vec3 motion; // 0x90
	bool fromFishing; // 0x100

#include "VirtualTemplate.h"
};

static_assert(offsetof(AddItemActorPacket, uid) == 0x48);
static_assert(offsetof(AddItemActorPacket, eid) == 0x50);
static_assert(offsetof(AddItemActorPacket, stack) == 0x58);
static_assert(offsetof(AddItemActorPacket, pos) == 0xE8);
static_assert(offsetof(AddItemActorPacket, motion) == 0xF4);
static_assert(offsetof(AddItemActorPacket, fromFishing) == 0x100);
