#pragma once

#include "math/BlockPos.h"

struct HitResult {
	enum struct Type { Tile, Entity, Miss };
	Vec3 x, y;
	Type type;
	Facing::Direction::Direction face;
	BlockPos blockPos;
	Vec3 pos;
	Actor *actor;
	bool hitLiquid;
	Facing::Direction::Direction liquidFace;
	BlockPos liquid;
	Vec3 liquidPos;
	bool unk;
};
