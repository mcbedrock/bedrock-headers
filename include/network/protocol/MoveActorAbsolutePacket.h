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
		Vec3 rot;
	};
};