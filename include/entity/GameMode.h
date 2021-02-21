#pragma once

#include "Actor.h"
#include "item/Item.h"

struct GameMode {
	void buildBlock(BlockPos const&, unsigned char face);
	void baseUseItem(ItemStack&);
	void stopBuildBlock();
	void releaseUsingItem();
	void attack(Actor&);
	void useItem(ItemStack&);
	void interact(Actor&, Vec3 const&);
	void useItemOn(ItemStack&, BlockPos const&, unsigned char, Vec3 const&, Block const*);
	void startDestroyBlock(const BlockPos&, unsigned char face, bool &unk);
	void continueDestroyBlock(const BlockPos &, unsigned char face, bool &unk);
	void destroyBlock(const BlockPos &, unsigned char face);
	void stopDestroyBlock(BlockPos const&);
};

struct SurvivalMode : GameMode {
	void buildBlock(BlockPos const&, unsigned char);
	void baseUseItem(ItemStack&);
	void attack(Actor&);
};