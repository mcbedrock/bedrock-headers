#pragma once

#include "Packet.h"

struct MoveActorAbsolutePacket : Packet {
	int64_t entityID;
	uint8_t flags;
private:
	char filler[3];
public:
	float x, y, z;
	uint8_t xRot, yRot, zRot; // * (360 / 256)
};