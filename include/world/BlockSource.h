#pragma once

#include "../entity/BlockActor.h"
#include "../math/BlockPos.h"
#include "../math/Vec3.h"
#include "Block.h"

struct ActorBlockSyncMessage;

struct BlockSource {
	Block &getBlock(BlockPos const &) const;

	Block &getBlock(int x, int y, int z) const;

	Material &getMaterial(BlockPos const&) const;

	Material &getMaterial(int x, int y, int z) const;

	bool isInWall(const Vec3 &);

	void setBlockNoUpdate(const BlockPos &, const Block &);

	void setBlock(const BlockPos &, const Block &, int = 0, const ActorBlockSyncMessage * = 0);

	BlockActor *getBlockEntity(const BlockPos &);

	//BlockEntity &getBlockEntity(BlockPos const &);

	//BlockEntity &getBlockEntity(int x, int y, int z) const;
};