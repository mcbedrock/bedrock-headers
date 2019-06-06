#pragma once

#include "ItemEnchants.h"

struct ItemStack {
	ItemStack(ItemInstance const&);

	ItemEnchants &getEnchantsFromUserData() const;

	int getId() const;

	int getDamageValue() const;
};