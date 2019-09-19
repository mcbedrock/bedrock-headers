#pragma once

#include <util/CompoundTag.h>
#include <world/Block.h>
#include <util/Color.h>
#include "ItemEnchants.h"

struct Item {};

struct ItemInstance {
	static const ItemInstance EMPTY_ITEM;

	ItemInstance(Item const &, int, int);

	short getId() const;

	short getAuxValue() const;

	void setAuxValue(short);

	bool operator ==(const ItemInstance &) const;

	bool operator !=(const ItemInstance &) const;

	ItemEnchants &getEnchantmentsFromUserData() const;

	bool hasCompoundTextUserData() const;

	bool isBlock() const;

	bool isNull() const;

	bool isDamageableItem() const;

	bool hasCustomHoverName() const;

	short getDamageValue() const;

	void setDamageValue(short);

	unsigned char getMaxStackSize() const;

	int getMaxDamage() const;

	bool hasUserData() const;

	ItemEnchants &getEnchantsFromUserData() const;

	void setCustomName(std::string const &);

	void fromTag(const CompoundTag &);

	void load(const CompoundTag &);
};

struct ItemRegistry {
	static ItemRegistry *mItemRegistry;

	Item &getItem(std::string const &);

	Item &getItem(short);
};

struct ItemStack : ItemInstance {
	ItemStack(ItemStack const &);

	ItemStack(ItemInstance const &);

	ItemStack(const Item &);

	ItemStack(const Item &, int, int);

	bool isBlock() const;

	// ID
	void _setItem(int);

	// Count
	void set(int);

	void setNull();

	void setBlock(const Block *);

	bool operator==(const ItemStack &) const;

	std::string getName() const;

	std::string getFullItemName() const;

	Color getColor() const;
};

struct ContainerItemStack : ItemStack {
	ContainerItemStack(ItemInstance const &);

	ContainerItemStack(ItemStack const &);

	short getId() const;

	bool isEmpty() const;

	int getCount() const;

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

	bool operator==(const ContainerItemStack &) const;
};
