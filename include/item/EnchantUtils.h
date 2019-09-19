#pragma once

#include "Enchant.h"
#include "Item.h"

struct EnchantUtils {
	static void randomlyEnchant(ItemStack &);

	static void applyEnchant(ItemInstance &, Enchant::Type, int, bool);

	static void applyEnchant(ItemStack &, Enchant::Type, int, bool);

	static bool canEnchant(ItemStack const &, Enchant::Type, int, bool);

	static bool canEnchant(Enchant::Type, ItemStack const &);
};