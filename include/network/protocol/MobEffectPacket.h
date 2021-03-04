#pragma once

#include "Packet.h"

/**
 * Informs clients of effects added, typically only sent by the server for your own effects. Only particle colors are sent for other entities (wink wink)
 *
 * Seems to still be relatively working without changes between 1.12-1.16
 */
struct MobEffectPacket : Packet {
	enum struct Event : uint8_t {
		Add = 1, Modify = 2, Remove = 3
	};
	/**
	 * Runtime ID
	 */
	ActorRuntimeID rid;
	/**
	 * Duration in ticks
	 */
	uint32_t duration;
	/**
	 * Event
	 * @see MobEffectPacket::Event
	 */
	Event eventID;
	char pad[3];
	/**
	 * Effect ID
	 */
	uint32_t effectID;
	/**
	 * Effect amplifier
	 */
	uint32_t amplifier;
	/**
	 * Particles showing
	 */
	bool particles;

#include "VirtualTemplate.h"
};
