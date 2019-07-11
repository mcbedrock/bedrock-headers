#pragma once

#include "Item.h"
#include <vector>

struct Container {
	bool addItem(ItemStack &);
	bool addItemToFirstEmptySlot(ItemStack &);
	std::vector<ContainerItemStack const *> getSlots() const;
};

struct SimpleContainer : Container {
	ItemStack const &getItem(int) const;
	int getContainerSize() const;
	int getMaxStackSize() const;
};