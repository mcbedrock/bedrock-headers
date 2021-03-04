#pragma once

#include "Packet.h"
#include "math/Vec3.h"
#include "util/ActorRuntimeID.h"

struct InteractPacket : Packet {
	enum struct Action : uint8_t {
		LegacyAttack = 2,
		LeaveVehicle = 3,
		MouseOver = 4,
		ActionOpenInventory = 6
	};
	/**
	 * Action
	 * @see InteractPacket::Action
	 */
	Action action;
	char pad[0x3];
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

	InteractPacket(Action action, ActorRuntimeID runtimeId, float x, float y, float z) : action(action),
	entityID(runtimeId), x(x), y(y), z(z) {}

#include "VirtualTemplate.h"
};
