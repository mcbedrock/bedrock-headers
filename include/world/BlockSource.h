#pragma once

#include "../math/BlockPos.h"
#include "../math/Vec3.h"
#include "Block.h"

struct BlockSource {
	Block &getBlock(BlockPos const &) const;

	Block &getBlock(int x, int y, int z) const;

	bool isInWall(Vec3 const&);

	//BlockEntity &getBlockEntity(BlockPos const &);

	//BlockEntity &getBlockEntity(int x, int y, int z) const;
};