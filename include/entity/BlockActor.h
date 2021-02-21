#pragma once

#include "util/CompoundTag.h"

struct BlockSource;

// TODO: Correct inheritance
struct BlockActor {
	void saveItemInstanceData(CompoundTag &);
	void save(CompoundTag &) const;
	void saveBlockData(CompoundTag &, BlockSource &) const;
};
