#pragma once

#include "math/BlockPos.h"

struct HitResult {
	enum struct Type { Tile, Entity, Miss };
	Vec3 x, y;
	Type type;
	Direction face;
	BlockPos blockPos;
	Vec3 pos;
	Actor *actor;
	bool hitLiquid;
	Direction liquidFace;
	BlockPos liquid;
	Vec3 liquidPos;
	bool unk;
};
