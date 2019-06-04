#pragma once

#include "Mob.h"
#include "../item/ItemInstance.h"

struct Player : Mob {
	ItemInstance *getSelectedItem() const;

	bool canUseAbility(std::string const &);

	void setSpeed(float);

	// Player::handleMovePlayerPacket(Player::PositionMode, Vec3 const&, Vec2 const&, float, int, int)

	void sendNetworkPacket(Packet&) const;
};