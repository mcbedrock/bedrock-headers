#pragma once

#include "Packet.h"

struct LevelSoundEventPacket : Packet {
	uint32_t sound;
	Vec3 pos;
	int32_t extra; // -1 by default
	char pad[0x4];
	gsl::cstring_span entityType; // semicolon by default, not used if extra is positive
	bool babyEntity, global;

	LevelSoundEventPacket(uint32_t sound, Vec3 pos, std::string entityType, bool global = false, int32_t extra = -1, bool babyEntity = false) : sound(sound), pos(pos), entityType(entityType), global(global), extra(extra), babyEntity(babyEntity) {};

#include "VirtualTemplate.h"
};

static_assert(offsetof(LevelSoundEventPacket, sound) == 0x24);
static_assert(offsetof(LevelSoundEventPacket, pos) == 0x28);
static_assert(offsetof(LevelSoundEventPacket, extra) == 0x34);
static_assert(offsetof(LevelSoundEventPacket, entityType) == 0x40);
static_assert(offsetof(LevelSoundEventPacket, babyEntity) == 0x50);
static_assert(offsetof(LevelSoundEventPacket, global) == 0x51);
