#pragma once

#include "Packet.h"

struct AddActorPacket : Packet {
	char pad_0014[4]; // TODO: Attributes
	ActorUniqueID uid; // 0x20
	ActorRuntimeID eid; // 0x28
	char pad_0030[0x10]; // TODO: Synched actor data
	//gsl::basic_string_span<const char, 0x20> entityType; // 0x40
	char entityType[28];
	Vec3 pos; // 0x5c
	Vec3 motion; // 0x68
	Vec3 rot; // 0x74
	// TODO: Entity meta data

#include "VirtualTemplate.h"
};