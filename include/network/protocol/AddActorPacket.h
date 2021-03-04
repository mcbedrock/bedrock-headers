#pragma once

#include "Packet.h"
#include "gsl-lite.hpp"

struct AddActorPacket : Packet {
	char pad_0024[0x1C];
	Vec3 pos, motion, rot;
	char pad_0038[0x4]; // TODO: Attributes
	ActorUniqueID uid;
	ActorRuntimeID rid;
	char pad_0078[0x20]; // TODO: Synced actor data
	gsl::cstring_span entityType;
	// TODO: Entity meta data/links/attributes

#include "VirtualTemplate.h"
};

static_assert(offsetof(AddActorPacket, pos) == 0x40);
static_assert(offsetof(AddActorPacket, motion) == 0x4C);
static_assert(offsetof(AddActorPacket, rot) == 0x58);
static_assert(offsetof(AddActorPacket, uid) == 0x68);
static_assert(offsetof(AddActorPacket, rid) == 0x70);
static_assert(offsetof(AddActorPacket, entityType) == 0x98);
