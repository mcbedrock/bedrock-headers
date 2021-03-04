#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

/**
 * Packet for hand swings
 */
struct AnimatePacket : Packet {
	enum struct Action : uint32_t {
		None = 0,
		SwingArm = 1,
		StopSleep = 3,
		Criticial = 4,
		EnchantCritical = 5, // aka magic

		// ????
		RowRight = 128,
		RowLeft = 129
	};

	/**
	 * Runtime ID
	 */
	ActorRuntimeID rid;
	/**
	 * Action
	 * @see AnimatePacket::Action
	 */
	Action action;
	/**
	 * Rowing time
	 */
	float rowingTime;

	AnimatePacket(ActorRuntimeID rid, Action action, float rowingTime = 0) : rid(rid), action(action) {
		if (action == Action::RowLeft || action == Action::RowRight)
			rowingTime = rowingTime;
	}

#include "VirtualTemplate.h"
};

static_assert(offsetof(AnimatePacket, rid) == 0x28);
static_assert(offsetof(AnimatePacket, rowingTime) == 0x34);
