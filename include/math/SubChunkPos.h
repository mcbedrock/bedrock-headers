#pragma once

#include "BlockPos.h"

struct SubChunkPos {
	SubChunkPos(const BlockPos &);

	SubChunkPos(const ChunkPos &, int);

	SubChunkPos(float, float, float);
};