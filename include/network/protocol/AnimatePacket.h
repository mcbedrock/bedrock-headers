#pragma once

#include "Packet.h"
#include "util/ActorRuntimeID.h"

/**
 * Packet for hand swings
 */
struct AnimatePacket : Packet {
	enum Action : uint32_t;

	/**
	 * Runtime ID
	 */
	ActorRuntimeID rid; // 20
	/**
	 * Action
	 * @see AnimatePacket::Action
	 */
	Action action; // 28
	/**
	 * TODO Document
	 */
	float extra; // 32

	enum Action : uint32_t {
		SwingArm = 1,
		StopSleep = 3,
		Criticial = 4
	};

	AnimatePacket(ActorRuntimeID rid, Action action, float extra = 0) : rid(rid), action(action), extra(extra) {}

#include "VirtualTemplate.h"
};
