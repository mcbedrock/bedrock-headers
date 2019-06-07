#pragma once

#include "Packet.h"

struct MobEffectPacket : Packet {
	enum Event : uint8_t;

	/**
	 * Runtime ID
	 */
	uint64_t entityID; // 20
	/**
	 * Duration in ticks
	 */
	uint32_t duration; // 28
	/**
	 * Event
	 * @see MobEffectPacket::Event
	 */
	Event eventID; // 32

private:
	char fillerr[3]; // eventID is 1 byte not 4

public:
	/**
	 * Effect ID
	 */
	uint32_t effectID; // 36
	/**
	 * Effect amplifier
	 */
	uint32_t amplifier; // 40
	/**
	 * Particles showing
	 */
	bool particles; // 44

	MobEffectPacket(unsigned char playerSubIndex) : Packet(playerSubIndex) {};

	enum Event : uint8_t {
		Add = 1, Modify = 2, Remove = 3
	};

#include "VirtualTemplate.h"
};
