#pragma once

#include <math/Vec2.h>
#include "Packet.h"

struct MovePlayerPacket : Packet {
	enum Mode : uint8_t;

	/**
	 * Player Runtime ID
	 */
	int64_t entityID;
	/**
	 * Position
	 */
	float x, y, z;
	/**
	 * Rotations
	 */
	float pitch, yaw, headYaw;
	/**
	 * Mode
	 */
	uint8_t mode;
	/**
	 * On Ground
	 */
	bool onGround;

private:
	char filler[7]; // again...

public:
	/**
	 * Ridden Entity Runtime ID
	 */
	uint64_t ridingEntityID;

	/**
	 * TODO: Document
	 */
	uint32_t teleportCause, teleportItem;

	enum Mode : uint8_t {
		Normal,
		Reset,
		Teleport,
		Pitch // *shrug*
	};

	// BIG TODO Fix up headYaw, I have no clue what it is and haven't done any digging
	MovePlayerPacket(int64_t entityID, bool onGround, const Vec3 &position, const Vec2 &rotations, Mode mode = Normal, uint64_t ridingEntity = 0,
			uint32_t teleportCause = 0, uint32_t teleportItem = 0) :
			entityID(entityID), onGround(onGround), x(position.x), y(position.y), z(position.z), yaw(rotations.yaw), pitch(rotations.pitch), headYaw(rotations.yaw),
			mode(mode), ridingEntityID(ridingEntity), teleportCause(teleportCause), teleportItem(teleportItem) {
		//
	}

	MovePlayerPacket(MovePlayerPacket &base) : entityID(base.entityID), onGround(base.onGround), x(base.x), y(base.y), z(base.z), yaw(base.yaw), pitch(base.pitch),
		headYaw(base.headYaw), ridingEntityID(base.ridingEntityID), teleportCause(base.teleportCause), teleportItem(base.teleportItem) {
		//
	}

#include "VirtualTemplate.h"
};