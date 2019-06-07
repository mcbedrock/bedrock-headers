#pragma once

#include "Packet.h"

struct InteractPacket : Packet {
	enum Action : uint8_t;

	/**
	 * Action
	 * @see InteractPacket::Action
	 */
	Action action;

private:
	char filler[3]; // action is 1 byte not 4

public:
	/**
	 * Target Runtime ID
	 */
	uint64_t entityID;

	/**
	 * Hit vector for MouseOver
	 */
	float x, y, z;

	enum Action : uint8_t {
		LeaveVehicle = 3,
		MouseOver = 4,
		ActionOpenInventory = 6
	};

#include "VirtualTemplate.h"
};