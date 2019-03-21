#pragma once

#include "ItemEnchants.h"

struct ItemStack {
	ItemEnchants &getEnchantsFromUserData() const;
};