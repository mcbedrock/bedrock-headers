#pragma once

#include "Mob.h"
#include "Agent.h"
#include "item/Item.h"

struct Player : Mob {
	bool canUseAbility(std::string const &);

	ItemInstance const &getSelectedItem() const;

	void setSelectedItem(ItemStack const &);

	void setSpeed(float);

	void sendNetworkPacket(Packet&) const;

	bool isUsingItem() const;

	short getSelectedItemSlot() const;

	NetworkIdentifier const &getClientId() const;

	Facing::LookDirection::LookDirection getDirection() const;

	void setEnchantmentSeed(int);

	int getEnchantmentSeed() const;

	void stopGliding();

	void startGliding();

	void updateGliding();

	Agent *getAgent() const;

	bool isSleeping() const;
};