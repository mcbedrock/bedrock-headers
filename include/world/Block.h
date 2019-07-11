#pragma once

#include "../math/AABB.h"

class BlockSource;

struct Block {
	ActorRuntimeID &getRuntimeId() const;

	AABB &getAABB(BlockSource &, BlockPos const &, AABB &, bool) const;

	float getTranslucency() const;

	bool operator !=(const Block *other) {
		return getRuntimeId().data != other->getRuntimeId().data;
	}

	bool operator !=(const Block &other) {
		return getRuntimeId().data != other.getRuntimeId().data;
	}

	bool operator ==(const Block *other) {
		return getRuntimeId().data == other->getRuntimeId().data;
	}

	bool operator ==(const Block &other) {
		return getRuntimeId().data == other.getRuntimeId().data;
	}
};
