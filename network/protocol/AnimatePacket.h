#pragma once

#include "Packet.h"

/**
 * Packet for hand swings
 */
struct AnimatePacket : Packet {
private:
	char filler[6];

public:
	int64_t entityID; // 0x14 (RuntimeID::data)
	int32_t x; // 0x1c typically 1
	float y; // 0x20 ( if 0x1c > 0 ) typically 0

#include "PacketTemplate.h"
};
