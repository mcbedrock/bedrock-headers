#pragma once

#include "Vec3.h"
#include "stdlib.h"
#include "stdio.h"

struct ChunkPos {
};

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

	static BlockPos const &max(BlockPos const &pos1, BlockPos const &pos2);

	static BlockPos const &min(BlockPos const &, BlockPos const &);

	bool operator==(BlockPos const &) const;

	bool operator!=(BlockPos const &) const;

	BlockPos operator+(BlockPos const &) const;

	BlockPos operator+(int) const;

	BlockPos operator-(BlockPos const &) const;

	BlockPos operator-(int) const;

	BlockPos operator-() const;

	BlockPos operator*(int) const;

	BlockPos const &operator=(BlockPos const &);

	BlockPos const &operator+=(BlockPos const &);

	BlockPos const &operator-=(BlockPos const &);

	BlockPos const &operator*=(int);

	/**
	 * Get BlockPos above current
	 * @return BlockPos
	 */
	BlockPos above() const;

	/**
	 * Get BlockPos x blocks above current
	 * @param x
	 * @return BlockPos
	 */
	BlockPos above(int x) const;

	/**
	 * Get BlockPos below current
	 * @return BlockPos
	 */
	BlockPos below() const;

	/**
	 * Get BlockPos x blocks below current
	 * @param x
	 * @return BlockPos
	 */
	BlockPos below(int) const;

	/**
	 * Get BlockPos east from current
	 * @return BlockPos
	 */
	BlockPos east() const;

	/**
	 * Get BlockPos x blocks east from current
	 * @param x
	 * @return BlockPos
	 */
	BlockPos east(int) const;

	/**
	 * Get BlockPos south from current
	 * @return BlockPos
	 */
	BlockPos south() const;

	/**
	 * Get BlockPos x blocks south from current
	 * @param x
	 * @return BlockPos
	 */
	BlockPos south(int) const;

	/**
	 * Get BlockPos west from current
	 * @return BlockPos
	 */
	BlockPos west() const;

	/**
	 * Get BlockPos x blocks west from current
	 * @param x
	 * @return BlockPos
	 */
	BlockPos west(int) const;

	/**
	 * Get BlockPos north from current
	 * @return
	 */
	BlockPos north() const;

	/**
	 * Get BlockPos x blocks north from current
	 * @param x
	 * @return BlockPos
	 */
	BlockPos north(int x) const;

	/**
	 * Get Vec3 with center of BlockPos instead of the corner
	 * @return Vec3
	 */
	Vec3 center() const;
};