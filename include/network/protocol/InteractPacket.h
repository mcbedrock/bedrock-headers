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
	ActorRuntimeID entityID;

	/**
	 * Hit vector for MouseOver
	 */
	union {
		Vec3 pos;
		struct {
			float x, y, z;
		};
	};

	enum Action : uint8_t {
		LegacyAttack = 2,
		LeaveVehicle = 3,
		MouseOver = 4,
		ActionOpenInventory = 6
	};

	InteractPacket(Action action, ActorRuntimeID runtimeId, float x, float y, float z) : action(action),
	entityID(runtimeId), x(x), y(y), z(z) {}

#include "VirtualTemplate.h"
};
