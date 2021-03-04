#pragma once

#include "util/DataItem.h"
#include "Packet.h"
#include "mce/UUID.h"
#include "util/ActorRuntimeID.h"
#include "util/DeviceOS.h"
#include "gsl-lite.hpp"
#include "item/Item.h"
#include <vector>

// TODO: Update

struct AddPlayerPacket : Packet {
	char pad[0x24];
	gsl::cstring_span username;
	mce::UUID uuid;
	ActorUniqueID uid;
	ActorRuntimeID eid;
	char pad2[0x8];
	gsl::cstring_span platformChatId;
	Vec3 pos;
	Vec3 motion;
	Vec3 rot;
	ItemStack stack;
	// Can't read the hell hole that's going on past loc_4A14427
	//std::vector<DataItem *> meta;
	char idk[0x168];
	gsl::cstring_span deviceId;
	DeviceOS platform; // Off the top of my head: 0 = Android, 7 = Windows 10

#include "VirtualTemplate.h"
};

static_assert(offsetof(AddPlayerPacket, username) == 0x48);
static_assert(offsetof(AddPlayerPacket, uuid) == 0x58);
static_assert(offsetof(AddPlayerPacket, uid) == 0x68);
static_assert(offsetof(AddPlayerPacket, eid) == 0x70);
static_assert(offsetof(AddPlayerPacket, platformChatId) == 0x80);
static_assert(offsetof(AddPlayerPacket, pos) == 0x90);
static_assert(offsetof(AddPlayerPacket, motion) == 0x9C);
static_assert(offsetof(AddPlayerPacket, rot) == 0xA8);
static_assert(offsetof(AddPlayerPacket, stack) == 0xB8);
//static_assert(offsetof(AddPlayerPacket, meta) == 0xF8); ?
static_assert(offsetof(AddPlayerPacket, deviceId) == 0x2A8);
static_assert(offsetof(AddPlayerPacket, platform) == 0x2B8);
