#pragma once

#include "Packet.h"

struct PlayerActionPacket : Packet {
	enum Action : uint32_t;

	/**
	 * Block position for some actions
	 */
	int32_t x, y, z;
	/**
	 * Block face for some actions
	 */
	uint32_t face;
	/**
	 * Action
	 * @see PlayerActionPacket::Action
	 */
	Action action;
	/**
	 * Player Runtime ID
	 */
	uint64_t entityID;

	enum Action : uint32_t {
		StartBreak = 0,
		AbortBreak = 1,
		StopBreak = 2,
		GetUpdatedBlock = 3,
		DropItem = 4,
		StartSleeping = 5,
		StopSleeping = 6,
		Respawn = 7,
		Jump = 8,
		StartSprinting = 9,
		StopSprinting = 10,
		StartSneaking = 11,
		StopSneaking = 12,
		RequestDimensionChange = 13,
		DimensionChangeAck = 14,
		StartGlide = 15,
		StopGlide = 16,
		BuildDenied = 17,
		ContinueBreak = 18,
		ChangeSkin = 19,
		SetEnchantmentSeed = 20,
		StartSwimming = 21,
		StopSwimming = 22,
		StartSpinAttack = 23,
		StopSpinAttack = 24
	};

#include "VirtualTemplate.h"
};
