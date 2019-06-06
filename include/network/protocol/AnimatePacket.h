#pragma once

#include "Packet.h"

/**
 * Packet for hand swings
 */
struct AnimatePacket : Packet {
private:
	char filler[6];

public:
	enum Action : int32_t;

	int64_t entityID; // 20
	int32_t action; // 28
	float extra = 0; // 32

	enum Action : int32_t {
		SwingArm = 1,
		StopSleep = 3,
		Criticial = 4
	};

#include "PacketTemplate.h"
};
