#pragma once

#include "Packet.h"

/**
 * Packet for hand swings
 */
struct AnimatePacket : Packet {
	enum Action : uint32_t;

	/**
	 * Runtime ID
	 */
	int64_t entityID; // 20
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

	AnimatePacket(int64_t entityID, Action action, float extra = 0) : entityID(entityID), action(action), extra(extra) {
		//
	}

#include "VirtualTemplate.h"
};
