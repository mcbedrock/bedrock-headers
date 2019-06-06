#pragma once

#include "Mob.h"
#include "../item/ItemInstance.h"
#include "../item/ItemStack.h"

struct Player : Mob {
	ItemInstance const &getSelectedItem() const;

	bool canUseAbility(std::string const &);

	void setSpeed(float);

	void sendNetworkPacket(Packet&) const;

	bool isUsingItem() const;

	ItemStack const &getCarriedItem() const;

	int getSelectedItemSlot() const;

	NetworkIdentifier const &getClientId() const;
};