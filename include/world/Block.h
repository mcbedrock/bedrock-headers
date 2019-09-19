#pragma once

#include "../math/AABB.h"
#include "../util/ActorRuntimeID.h"

struct BlockSource;

enum MaterialType {};

struct Material {
	bool isReplaceable() const;

	bool isType(MaterialType) const;
};

struct Block {
	ActorRuntimeID &getRuntimeId() const;

	AABB &getAABB(BlockSource &, BlockPos const &, AABB &, bool) const;

	float getTranslucency() const;

	int getRenderLayer() const;

	unsigned int getColor() const;

	bool operator !=(const Block *other) const {
		return getRuntimeId().data != other->getRuntimeId().data;
	}

	bool operator !=(const Block &other) const {
		return getRuntimeId().data != other.getRuntimeId().data;
	}

	bool operator ==(const Block *other) const {
		return getRuntimeId().data == other->getRuntimeId().data;
	}

	bool operator ==(const Block &other) const {
		return getRuntimeId().data == other.getRuntimeId().data;
	}

	const Material &getMaterial() const;

	int getSerializationId() const;
};

struct BlockLegacy {
	void forEachBlockPermutation(std::function<bool(const Block &)>) const;

	std::string getFullName() const;
};

struct BlockTypeRegistry {
	static void forEachBlock(std::function<bool (BlockLegacy const &)>);
};

enum struct BlockRenderLayer;