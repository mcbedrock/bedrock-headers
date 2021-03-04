#pragma once

#include "util/Brightness.h"
#include "math/AABB.h"
#include "util/ActorRuntimeID.h"

struct BlockSource;

enum struct MaterialType;

struct Material {
	bool isReplaceable() const;

	bool isType(MaterialType) const;
};

enum struct BlockProperty : unsigned char;

struct Block {
	ActorRuntimeID getRuntimeId() const;

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

	bool hasProperty(BlockProperty) const;
};

struct BlockLegacy {
	//virtual void forEachBlockPermutation(std::function<bool(const Block &)>) const;

	virtual std::string getFullName() const;

	virtual unsigned int getColor(BlockSource&, BlockPos const&, Block const&) const;

	virtual Brightness getLightEmission(Block const&) const;
};

struct BlockTypeRegistry {
	static void forEachBlock(std::function<bool (BlockLegacy const &)>);
};

enum struct BlockRenderLayer;