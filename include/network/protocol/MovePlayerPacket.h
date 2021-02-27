#pragma once

#include "math/Vec2.h"
#include "util/ActorRuntimeID.h"
#include "Packet.h"

struct MovePlayerPacket : Packet {
	enum Mode : uint8_t {
		Normal,
		Reset,
		Teleport,
		Pitch // *shrug*
	};

	int pad;

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
	uint8_t mode;
	/**
	 * On Ground
	 */
	bool onGround;

	char filler[7]; // again...

	/**
	 * Ridden Entity Runtime ID
	 */
	ActorRuntimeID ridingEntityID;

	/**
	 * TODO: Document
	 */
	uint32_t teleportCause, teleportItem;


	MovePlayerPacket(const ActorRuntimeID runtimeID, bool onGround, const Vec3 &position, const Vec3 &rotations, Mode mode = Normal, uint64_t ridingEntity = 0,
			uint32_t teleportCause = 0, uint32_t teleportItem = 0) :
			runtimeID(runtimeID), onGround(onGround), pos(position), rot(rotations),
			mode(mode), ridingEntityID(ridingEntity), teleportCause(teleportCause), teleportItem(teleportItem) {}

	MovePlayerPacket(const MovePlayerPacket &base) : runtimeID(base.runtimeID), onGround(base.onGround), x(base.x), y(base.y), z(base.z), yaw(base.yaw), pitch(base.pitch),
		headYaw(base.headYaw), ridingEntityID(base.ridingEntityID), teleportCause(base.teleportCause), teleportItem(base.teleportItem) {}

#include "VirtualTemplate.h"
};

static_assert(offsetof(MovePlayerPacket, runtimeID) == 0x28);