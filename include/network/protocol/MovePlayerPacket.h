#pragma once

#include "Packet.h"

struct MovePlayerPacket : Packet {
	enum Mode : uint8_t;

	/**
	 * Player Runtime ID
	 */
	uint64_t entityID;
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

#include "VirtualTemplate.h"
};