#pragma once

#include "Actor.h"
#include "../item/Item.h"

struct GameMode {
	void attack(Actor&);

	void useItem(ItemStack&);

	void releaseUsingItem();

	void buildBlock(BlockPos const&, unsigned char face);
};
