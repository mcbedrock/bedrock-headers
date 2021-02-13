#pragma once

#include "Enchant.h"
#include "Item.h"

struct EnchantUtils {
	static void randomlyEnchant(ItemStack &);

	static void applyEnchant(ItemStackBase &item, Enchant::Type type, int level, bool b_unk);

	// EnchantmentInstance is not yet restructured
	//static void applyEnchant(ItemStackBase &item, const EnchantmentInstance &enchant, int level, bool b_unk);

	static bool canEnchant(ItemStack const &, Enchant::Type, int, bool);

	static bool canEnchant(Enchant::Type, ItemStack const &);
};