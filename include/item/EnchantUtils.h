#pragma once

#include "Enchant.h"
#include "Item.h"

struct EnchantUtils {
	static void randomlyEnchant(ItemStack &);

	static void applyEnchant(ItemInstance &, Enchant::Type, int, bool);
};