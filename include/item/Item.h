#pragma once

#include <util/CompoundTag.h>
#include <world/Block.h>
#include <util/Color.h>
#include "ItemEnchants.h"

struct Item {};

struct ItemStackBase {
	bool isNull() const;

	bool isDamageableItem() const;
	void setDamageValue(short);
	short getDamageValue() const;

	void _setItem(int id, bool b_unk = false);
	short getId() const;

	void set(int count);

	void setAuxValue(short meta);
	short getAuxValue() const;

	std::string getName() const;

	int getMaxDamage() const;

	int getAttackDamage() const;

	bool isBlock() const;

	void setCustomName(std::string const &);
	void setCustomLore(std::string const &);
};

struct ItemInstance : ItemStackBase {
	static const ItemInstance EMPTY_ITEM;

	ItemInstance(Item const &, int, int);

	bool operator ==(const ItemInstance &) const;

	bool operator !=(const ItemInstance &) const;

	ItemEnchants &getEnchantmentsFromUserData() const;

	bool hasCompoundTextUserData() const;

	bool hasCustomHoverName() const;

	unsigned char getMaxStackSize() const;

	bool hasUserData() const;

	ItemEnchants &getEnchantsFromUserData() const;

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

	void setNull();

	void setBlock(const Block *);

	bool operator==(const ItemStack &) const;

	std::string getFullItemName() const;
};

struct ContainerItemStack : ItemStack {
	ContainerItemStack(ItemInstance const &);

	ContainerItemStack(ItemStack const &);

	void increaseCount(int);

	void decreaseCount(int);

	void setStackSize(unsigned char);

	void forceSetCount(int);

	unsigned char getStackSize() const;

	// Unknowns
	/*ItemStack getItemStack();

	ItemInstance getItemInstance();

	ItemStack getItemStack() const;

	ItemInstance getItemInstance() const;*/

	bool operator==(const ContainerItemStack &) const;
};
