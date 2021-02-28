#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

struct MoveActorAbsolutePacket : Packet {
	ActorRuntimeID rid;
	uint8_t flags;
private:
	char filler[3];
public:
	union {
		struct {
			float x, y, z;
		};
		Vec3 pos;
	};
	union {
		struct {
			uint8_t xRot, yRot, zRot; // * (360 / 256)
		};
		struct {
			uint8_t pitch, headYaw, yaw;
		};
	};
};

static_assert(offsetof(MoveActorAbsolutePacket, rid) == 0x28);
static_assert(offsetof(MoveActorAbsolutePacket, flags) == 0x30);
static_assert(offsetof(MoveActorAbsolutePacket, pos) == 0x34);
static_assert(offsetof(MoveActorAbsolutePacket, xRot) == 0x40);
static_assert(offsetof(MoveActorAbsolutePacket, yRot) == 0x41);
static_assert(offsetof(MoveActorAbsolutePacket, zRot) == 0x42);