#pragma once

#include "Enchant.h"
#include "Item.h"
#include "EnchantmentInstance.h"

struct EnchantUtils {
	static void applyEnchant(ItemStackBase &item, Enchant::Type type, int level, bool b_unk);

	static void applyEnchant(ItemStackBase &item, EnchantmentInstance const &enchant, int level, bool b_unk);

	static void applyEnchant(ItemStackBase &item, ItemEnchants const &enchants, bool b_unk);

	static bool canEnchant(ItemStackBase const &item, EnchantmentInstance const &enchant, bool b_unk);

	static bool  canEnchant(ItemStackBase const &item, Enchant::Type enchant, int level, bool b_unk);
};