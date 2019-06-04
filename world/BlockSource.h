#pragma once

#include "../math/BlockPos.h"
#include "../world/Block.h"

struct BlockSource {
	Block &getBlock(BlockPos const&) const;

	Block &getBlock(int x, int y, int z) const;

	//BlockEntity &getBlockEntity(BlockPos const&);

	//BlockEntity &getBlockEntity(int x, int y, int z) const;
};