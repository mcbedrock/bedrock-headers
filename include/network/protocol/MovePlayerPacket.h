#pragma once

#include "math/Vec2.h"
#include "math/Vec3.h"
#include "util/ActorRuntimeID.h"
#include "Packet.h"

struct MovePlayerPacket : Packet {
	enum struct Mode : uint8_t {
		Normal,
		Reset,
		Teleport,
		Pitch // *shrug*
	};
	/**
	 * Player Runtime ID
	 */
	ActorRuntimeID runtimeID;
	/**
	 * Position
	 */
	union {
		struct {
			float x, y, z;
		};
		Vec3 pos;
	};
	/**
	 * Rotations
	 */
	 union {
	 	struct {
		 float pitch, yaw, headYaw;
	 	};
	 	Vec3 rot;
	 };
	/**
	 * Mode
	 */
	Mode mode;
	/**
	 * On Ground
	 */
	bool onGround;

	/**
	 * Ridden Entity Runtime ID
	 */
	ActorRuntimeID rideId;

	/**
	 * Self explanatory, only written to BinaryStream if mode is teleport
	 */
	int32_t teleportCause, teleportItem;

	/**
	 * Current tick, probably used for lag check/syncing
	 */
	uint64_t tick;

	MovePlayerPacket(const ActorRuntimeID runtimeID, bool onGround, const Vec3 &position, const Vec3 &rotations, Mode mode = Mode::Normal, ActorRuntimeID rideId = ActorRuntimeID{0},
			int32_t teleportCause = 0, int32_t teleportItem = 0, uint64_t tick = 0) :
			runtimeID(runtimeID), onGround(onGround), pos(position), rot(rotations),
			mode(mode), rideId(rideId), teleportCause(teleportCause), teleportItem(teleportItem), tick(tick) {}

	explicit MovePlayerPacket(const MovePlayerPacket &base) : runtimeID(base.runtimeID), onGround(base.onGround), x(base.x), y(base.y), z(base.z), yaw(base.yaw), pitch(base.pitch),
		headYaw(base.headYaw), rideId(base.rideId), tick(base.tick) {
		if (base.mode == Mode::Teleport) {
			teleportCause = base.teleportCause;
			teleportItem = base.teleportItem;
		} else
			teleportCause = teleportItem = 0; // Necessary?
	}

#include "VirtualTemplate.h"
};

static_assert(offsetof(MovePlayerPacket, runtimeID) == 0x28);
static_assert(offsetof(MovePlayerPacket, mode) == 0x48);
static_assert(offsetof(MovePlayerPacket, onGround) == 0x49);
static_assert(offsetof(MovePlayerPacket, rideId) == 0x50);
static_assert(offsetof(MovePlayerPacket, teleportCause) == 0x58);
static_assert(offsetof(MovePlayerPacket, teleportItem) == 0x5C);
static_assert(offsetof(MovePlayerPacket, tick) == 0x60);