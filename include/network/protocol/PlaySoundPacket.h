#pragma once

#include "Packet.h"
#include "math/BlockPos.h"

struct PlaySoundPacket : Packet {
	char pad[0x8];
	gsl::cstring_span soundName;
	BlockPos pos;
	float volume, pitch;
};

static_assert(offsetof(PlaySoundPacket, soundName) == 0x30);
static_assert(offsetof(PlaySoundPacket, pos) == 0x40);
static_assert(offsetof(PlaySoundPacket, volume) == 0x4C);
static_assert(offsetof(PlaySoundPacket, pitch) == 0x50);
