#pragma once

#include "ItemEnchants.h"

struct ItemInstance {
	short getId() const;

	// This isn't correct from getSelectedItem()...
	short getAuxValue() const;

	ItemEnchants &getEnchantmentsFromUserData() const;

	bool hasCompoundTextUserData() const;

	bool isBlock() const;

	bool isNull() const;
};

struct ItemStack {
	ItemStack(ItemInstance const&);

	ItemEnchants &getEnchantsFromUserData() const;

	short getId() const;

	int getDamageValue() const;

	void setAuxValue(short);

	short getAuxValue() const;

	bool isBlock() const;
};

struct ContainerItemStack : ItemStack {
	short getId() const;

	void increaseCount(int);

	void decreaseCount(int);

	void setStackSize(unsigned char);

	void forceSetCount(int);

	unsigned char getStackSize() const;

	short getAuxValue() const;

	// are these refs or ptrs?

	ItemStack getItemStack();

	ItemInstance getItemInstance();

	ItemStack getItemStack() const;

	ItemInstance getItemInstance() const;
};

