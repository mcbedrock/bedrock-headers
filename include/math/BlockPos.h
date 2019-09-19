#pragma once

#include "Vec3.h"
#include "Facing.h"

struct ChunkPos {};

struct BlockPos {
	int x, y, z;

	//BlockPos(float, float, float);

	BlockPos(int x, int y, int z) : x(x), y(y), z(z) {};

	/**
	 * Create BlockPos from Vec3
	 */
	BlockPos(Vec3 const &);

	/**
	 * Create BlockPos from ChunkPos
	 */
	BlockPos(ChunkPos const &, int);

	/**
	 * Copy BlockPos
	 * @param pos
	 */
	BlockPos(BlockPos const &pos) : BlockPos(pos.x, pos.y, pos.z) {};

	static BlockPos MAX;
	static BlockPos MIN;
	static BlockPos ONE;
	static BlockPos ZERO;

	/**
	 * Get Vec3 with center of BlockPos instead of the corner
	 * @return Vec3
	 */
	Vec3 center() const;

	BlockPos neighbor(unsigned char) const;

	BlockPos relative(unsigned char, int) const;
};