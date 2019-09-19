#pragma once

#include "Packet.h"
#include "gsl/string_span"

struct LevelSoundEventPacket : Packet {
	uint32_t sound; // 0x14
	Vec3 pos; // 0x18 0x1c 0x2o
	int32_t extra; // 0x24 -1 by default
	// below is out of range
	gsl::basic_string_span<const char, 1> entityType; // 0x28 semicolon by default, not used if extra is positive
	bool babyEntity, global; // 0x2c 0x2d

	LevelSoundEventPacket(uint32_t sound, Vec3 pos, std::string entityType, bool global = false, int32_t extra = -1, bool babyEntity = false) : sound(sound), pos(pos), entityType(entityType), global(global), extra(extra), babyEntity(babyEntity) {};

#include "VirtualTemplate.h"
};