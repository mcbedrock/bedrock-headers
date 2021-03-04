#pragma once

#include "math/BlockPos.h"
#include "util/ActorRuntimeID.h"
#include "Packet.h"

struct PlayerActionPacket : Packet {
	enum struct Action : uint32_t {
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
		StopSpinAttack = 24,
		InteractBlock = 25
	};

	/**
	 * Block position for some actions
	 */
	union {
		struct {
			int32_t x = 0;
			uint32_t y = 0;
			int32_t z = 0;
		};
		BlockPos blockPos;
	};

	uint32_t face;

	/**
	 * Action
	 * @see PlayerActionPacket::Action
	 */
	Action action;
	/**
	 * Player Runtime ID
	 */
	ActorRuntimeID rid;

	PlayerActionPacket(ActorRuntimeID rid, Action action) : rid(rid), action(action) {}

	PlayerActionPacket(const PlayerActionPacket &other) : rid(other.rid), blockPos(other.blockPos), face(other.face), action(other.action) {}

#include "VirtualTemplate.h"
};

static_assert(offsetof(PlayerActionPacket, x) == 0x24);
static_assert(offsetof(PlayerActionPacket, face) == 0x30);
static_assert(offsetof(PlayerActionPacket, action) == 0x34);
static_assert(offsetof(PlayerActionPacket, rid) == 0x38);