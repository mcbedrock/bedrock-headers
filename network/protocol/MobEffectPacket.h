#pragma once

#include "Packet.h"

struct MobEffectPacket : Packet {
private:
	char filler[7];

public:
	enum Event : uint8_t;

	uint64_t entityID; // 20 RuntimeID of target
	uint32_t duration; // 28 Duration in ticks
	Event eventID; // 32 Event

private:
	char fillerr[3];

public:
	uint32_t effectID, amplifier; // 36 40
	bool particles; // 44

	MobEffectPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {};

	enum Event : uint8_t {
		Add = 1, Modify = 2, Remove = 3
	};

#include "PacketTemplate.h"
};
