#pragma once

#include "../item/ItemStack.h"
#include <vector>

struct Container {
	bool addItem(ItemStack &);
	bool addItemToFirstEmptySlot(ItemStack &);
	std::vector<ItemStack const *> getSlots() const;
};

struct SimpleContainer : Container {
	ItemStack const &getItem(int) const;
	int getContainerSize() const;
	int getMaxStackSize() const;
};