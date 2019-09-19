#pragma once

#include "Item.h"

enum ContainerID : int {};

struct PlayerInventoryProxy {
	ContainerID getSelectedContainerId();

	void selectSlot(int, ContainerID);

	void setSelectedItem(const ItemStack&);

	void setContainerChanged(int);

	void setItem(int slot, const ItemStack &, ContainerID);
};

struct Container {
	bool addItem(ItemStack &);
	bool addItemToFirstEmptySlot(ItemStack &);
	std::vector<ContainerItemStack const *> getSlots() const;
};

struct BaseContainerMenu : Container {

};

struct SimpleContainer : Container {
	ItemStack const &getItem(int) const;
	int getContainerSize() const;
	int getMaxStackSize() const;
};