#pragma once

#include "../util/CompoundTag.h"

struct BlockSource;

struct BlockActor {
	void saveItemInstanceData(CompoundTag &);

	void save(CompoundTag &) const;

	void saveBlockData(CompoundTag &, BlockSource &) const;
};
