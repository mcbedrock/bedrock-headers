#pragma once

#include "ItemEnchants.h"

struct ItemInstance {
	unsigned int getId() const;

	int getDamageValue() const;

	ItemEnchants &getEnchantmentsFromUserData() const;
};