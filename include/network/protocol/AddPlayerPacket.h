#pragma once

#include "Packet.h"
#include "mce/UUID.h"
#include "util/ActorRuntimeID.h"
#include "gsl/string_span"

// TODO: Update

struct AddPlayerPacket : Packet {
	char pad[12];
	const char *username; // 0x20 (0x20 - 0xC)
	mce::UUID uuid; // 0x24
	ActorUniqueID uid; // 0x34
	ActorRuntimeID eid; // 0x3c
	const char* platformChatId; // 0x38 (0x44 - 0xC)
	Vec3 pos; // 0x48
	Vec3 motion; // 0x54
	Vec3 rot; // 0x60
	ItemStack *stack; // 0x6C
	char pad_0074[0x194]; // skip adventure and other data shit rn
	const char *deviceId;

#include "VirtualTemplate.h"
};

//char (*test)[sizeof(AddPlayerPacket)] = 1;
/*static_assert(offsetof(AddPlayerPacket, username) == 0x20);
static_assert(offsetof(AddPlayerPacket, uuid) == 0x24);
static_assert(offsetof(AddPlayerPacket, uid) == 0x34);
static_assert(offsetof(AddPlayerPacket, eid) == 0x3c);
static_assert(offsetof(AddPlayerPacket, platformChatId) == 0x44);
static_assert(offsetof(AddPlayerPacket, pos) == 0x48);
static_assert(offsetof(AddPlayerPacket, stack) == 0x6C);
static_assert(offsetof(AddPlayerPacket, deviceId) == 0x204);*/